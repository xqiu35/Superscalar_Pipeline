/***********************************************************************
 * File         : pipeline.cpp
 * Author       : Soham J. Desai 
 * Date         : 14th January 2014
 * Description  : Superscalar Pipeline for Lab2 ECE 6100
 **********************************************************************/

#include "pipeline.h"
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

extern int32_t PIPE_WIDTH;
extern int32_t ENABLE_MEM_FWD;
extern int32_t ENABLE_EXE_FWD;
extern int32_t BPRED_POLICY;

/**********************************************************************
 * Support Function: Read 1 Trace Record From File and populate Fetch Op
 **********************************************************************/

void pipe_get_fetch_op(Pipeline *p, Pipeline_Latch* fetch_op){
    uint8_t bytes_read = 0;
    bytes_read = fread(&fetch_op->tr_entry, 1, sizeof(Trace_Rec), p->tr_file);

    // check for end of trace
    if( bytes_read < sizeof(Trace_Rec)) {
      fetch_op->valid=false;
      p->halt_op_id=p->op_id_tracker;
      return;
    }

    // got an instruction ... hooray!
    fetch_op->valid=true;
    fetch_op->stall=false;
    fetch_op->is_mispred_cbr=false;
    p->op_id_tracker++;
    fetch_op->op_id=p->op_id_tracker;

    return; 
}


/**********************************************************************
 * Pipeline Class Member Functions 
 **********************************************************************/

Pipeline * pipe_init(FILE *tr_file_in){
    printf("\n** PIPELINE IS %d WIDE **\n\n", PIPE_WIDTH);

    // Initialize Pipeline Internals
    Pipeline *p = (Pipeline *) calloc (1, sizeof (Pipeline));

    p->tr_file = tr_file_in;
    p->halt_op_id = ((uint64_t)-1) - 3;           

    // Allocated Branch Predictor
    if(BPRED_POLICY){
      p->b_pred = new BPRED(BPRED_POLICY);
    }

    return p;
}


/**********************************************************************
 * Print the pipeline state (useful for debugging)
 **********************************************************************/

void pipe_print_state(Pipeline *p){
    std::cout << "--------------------------------------------" << std::endl;
    std::cout <<"cycle count : " << p->stat_num_cycle << " retired_instruction : " << p->stat_retired_inst << std::endl;

    uint8_t latch_type_i = 0;   // Iterates over Latch Types
    uint8_t width_i      = 0;   // Iterates over Pipeline Width
    for(latch_type_i = 0; latch_type_i < NUM_LATCH_TYPES; latch_type_i++) {
        switch(latch_type_i) {
            case 0:
                printf(" IF: ");
                break;
            case 1:
                printf(" ID: ");
                break;
            case 2:
                printf(" EX: ");
                break;
            case 3:
                printf(" MA: ");
                break;
            default:
                printf(" ---- ");
        }
    }
    printf("\n");
    for(width_i = 0; width_i < PIPE_WIDTH; width_i++) {
        for(latch_type_i = 0; latch_type_i < NUM_LATCH_TYPES; latch_type_i++) {
            if(p->pipe_latch[latch_type_i][width_i].valid == true) {
        printf(" %6u ",(uint32_t)( p->pipe_latch[latch_type_i][width_i].op_id));
            } else {
                printf(" ------ ");
            }
        }
        printf("\n");
    }
    printf("\n");

}


/**********************************************************************
 * Pipeline Main Function: Every cycle, cycle the stage 
 **********************************************************************/
void pipe_cycle(Pipeline *p)
{
    p->stat_num_cycle++;
    pipe_cycle_WB(p);
    pipe_cycle_MA(p);
    pipe_cycle_EX(p);
    pipe_cycle_ID(p);
    pipe_cycle_IF(p);
    pipe_print_state(p);
}
/**********************************************************************
 * -----------  DO NOT MODIFY THE CODE ABOVE THIS LINE ----------------
 **********************************************************************/




/*        Xiaofei's Implementation starts from here                */




void pipe_cycle_WB(Pipeline *p)
{
  int ii;
  for(ii=0; ii<PIPE_WIDTH; ii++)
  {
    if(p->pipe_latch[MA_LATCH][ii].valid)
    {

      p->stat_retired_inst++;

      if(p->pipe_latch[MA_LATCH][ii].op_id >= p->halt_op_id)
      {
        p->halt=true;
        /*if(BPRED_POLICY)
        {
          //delete p->b_pred;
        }*/
      }
      if(p->pipe_latch[MA_LATCH][ii].is_mispred_cbr)
      {
        p->fetch_cbr_stall = 0;
      }
    }
  }
}

//-------------------------MA Stage------------------------------------//
void pipe_cycle_MA(Pipeline *p){
  int ii;
  for(ii=0; ii<PIPE_WIDTH; ii++)
  {
    p->pipe_latch[MA_LATCH][ii]=p->pipe_latch[EX_LATCH][ii];
  }
}

//---------------------------Ex Stage-------------------------------//
void pipe_cycle_EX(Pipeline *p)
{
  int ii;
  for(ii=0; ii<PIPE_WIDTH; ii++)
  {
    p->pipe_latch[EX_LATCH][ii]=p->pipe_latch[ID_LATCH][ii];
  }
}


//--------------------------Instr Decode Stage-----------------------------//
uint8_t check_pipe_stall(const Pipeline_Latch*, const Pipeline*); // this is used to check if the pipe has hazard
uint8_t check_older_stall(const uint64_t&, const Pipeline*);

uint8_t cal_dep_stall(const Pipeline_Latch*, const Pipeline_Latch*, Latch_Type, int& staller_op_id, int& needUpdated); // check is any hazard between two latches
void cal_cbr_staller(const Pipeline_Latch*, uint64_t& staller_op_id, int& row, int& is_updated);

Pipeline_Latch* get_stage_latches(Latch_Type, const Pipeline*); // this is used to get all latches for a specific stage

void printLatch(const Pipeline*, Latch_Type, const int&);
void printAll(const Pipeline*);

void halt(const int& cycle,const Pipeline* p)
{
  if(p->stat_num_cycle == cycle)
  {
    exit(1);
  }
}

void pipe_cycle_ID(Pipeline *p)
{
  int ii;
  uint8_t pipe_stall;

  for(ii=0; ii<PIPE_WIDTH; ii++)
  {
    p->pipe_latch[ID_LATCH][ii]=p->pipe_latch[IF_LATCH][ii];

    if(p->pipe_latch[ID_LATCH][ii].valid) // if valid
    {
      pipe_stall = check_pipe_stall(&p->pipe_latch[ID_LATCH][ii], p); // check data and cbr harzard

      if(pipe_stall==0) // if current row has stall
      {
        p->pipe_latch[ID_LATCH][ii].valid = 1;  // else move on
        p->pipe_latch[IF_LATCH][ii].stall = 0;  // send 0 stall signal to IF                    
      }
      else // if stall happend
      {
        p->pipe_latch[ID_LATCH][ii].valid = 0; // insert bubble to DE
        p->pipe_latch[IF_LATCH][ii].stall = 1; // assert stall singal IF
      }    
    }
  }
}

//---------------------------Fetch Stage--------------------------------//
bool sort_latch(const Pipeline_Latch& latch_A, const Pipeline_Latch& latch_B)
{
  return (latch_A.op_id<latch_B.op_id);
}

void pipe_cycle_IF(Pipeline *p)
{
  int ii;
  Pipeline_Latch fetch_op;
  bool tr_read_success;

  uint8_t is_stall;

  for(ii=0; ii<PIPE_WIDTH; ii++)
  {
    if(!p->pipe_latch[IF_LATCH][ii].stall) // if no stall signal received
    {
      if(!p->fetch_cbr_stall) // and no stall due to misprediction
      {
        pipe_get_fetch_op(p, &fetch_op); // fetch new inst

        if(BPRED_POLICY)
        {
          pipe_check_bpred(p, &fetch_op); // check predicted inst
        }

        p->pipe_latch[IF_LATCH][ii]=fetch_op;
      }
      else // if stall has not resolved
      {
        p->pipe_latch[IF_LATCH][ii].valid = 0; // insert bubble to current line
      }
    } 
  }
  std::sort(&p->pipe_latch[IF_LATCH][0],&p->pipe_latch[IF_LATCH][PIPE_WIDTH],sort_latch);

  //printAll(p);
  //halt(170,p);
}

//----------------------Part B--------------------------------//

void pipe_check_bpred(Pipeline *p, Pipeline_Latch *fetch_op)
{
  // call branch predictor here, if mispred then mark in fetch_op
  // update the predictor instantly
  // stall fetch using the flag p->fetch_cbr_stall

  if(fetch_op->tr_entry.op_type == OP_CBR)
  {
    uint32_t PC = fetch_op->tr_entry.inst_addr;        // get address used for mapping to PHT
    bool pre_dir = p->b_pred->GetPrediction(PC);       // get predicted direction

    if( ((bool)fetch_op->tr_entry.br_dir) != pre_dir)         // if mis pred
    {
      p->fetch_cbr_stall = 1;
      fetch_op->is_mispred_cbr = 1;         // mark
    }

    p->b_pred->UpdatePredictor(PC, (bool)fetch_op->tr_entry.br_dir, pre_dir); // update prediction
  }
}


//--------------------------------------------------------------------//
uint8_t check_pipe_stall(const Pipeline_Latch* current_id_latch, const Pipeline* p)
{
  using namespace std;
  uint8_t stall = 0;
  uint8_t if_stall=0;
  uint8_t id_stall=0;
  uint8_t ex_stall=0;
  uint8_t ma_stall=0;

  uint8_t cbr_stall=0;
  uint8_t is_older_stall = 0;

  Pipeline_Latch* if_latches = get_stage_latches(IF_LATCH,p);
  Pipeline_Latch* id_latches = get_stage_latches(ID_LATCH,p);
  Pipeline_Latch* ex_latches = get_stage_latches(EX_LATCH,p);
  Pipeline_Latch* ma_latches = get_stage_latches(MA_LATCH,p);

  int staller_op_id=-1;
  int needUpdated = 0;

  for(int32_t i=0;i<PIPE_WIDTH;i++)
  {
    if_stall = if_stall || cal_dep_stall(current_id_latch,&if_latches[i],IF_LATCH,staller_op_id,needUpdated);
    if(needUpdated && (ENABLE_EXE_FWD || ENABLE_MEM_FWD))
    {
      if_stall = cal_dep_stall(current_id_latch,&if_latches[i],IF_LATCH,staller_op_id,needUpdated);
     // needUpdated = 0;
    }

    id_stall = id_stall || cal_dep_stall(current_id_latch,&id_latches[i],ID_LATCH,staller_op_id,needUpdated);
    if(needUpdated && (ENABLE_EXE_FWD || ENABLE_MEM_FWD))
    {
      id_stall = cal_dep_stall(current_id_latch,&id_latches[i],ID_LATCH,staller_op_id,needUpdated);
     // needUpdated = 0;
    }

    ex_stall = ex_stall || cal_dep_stall(current_id_latch,&ex_latches[i],EX_LATCH,staller_op_id,needUpdated);
    if(needUpdated && (ENABLE_EXE_FWD || ENABLE_MEM_FWD))
    {
      ex_stall = cal_dep_stall(current_id_latch,&ex_latches[i],EX_LATCH,staller_op_id,needUpdated);
     // needUpdated = 0;
    }

    ma_stall = ma_stall || cal_dep_stall(current_id_latch,&ma_latches[i],MA_LATCH,staller_op_id,needUpdated);
    if(needUpdated && (ENABLE_EXE_FWD || ENABLE_MEM_FWD))
    {
      ma_stall = cal_dep_stall(current_id_latch,&ma_latches[i],MA_LATCH,staller_op_id,needUpdated);
     // needUpdated = 0;
    }
  }

  is_older_stall = check_older_stall(current_id_latch->op_id,p);

  delete [] if_latches;
  delete [] id_latches;
  delete [] ex_latches;
  delete [] ma_latches;

  stall = if_stall || id_stall || ex_stall || ma_stall || is_older_stall;

  return stall;
}

uint8_t check_older_stall(const uint64_t& op_id, const Pipeline* p)
{
  Pipeline_Latch* if_latch = get_stage_latches(IF_LATCH,p);

  uint8_t is_valid;
  uint8_t is_stall;
  uint8_t is_older;

  uint8_t is_older_stall = 0;

  for(uint32_t i=0;i<PIPE_WIDTH;i++)
  {
    is_valid = if_latch[i].valid;
    is_stall = if_latch[i].stall;
    is_older = if_latch[i].op_id < op_id;


    if(is_stall && is_older && is_valid)
    {
      is_older_stall = 1;
    }
  }

  delete [] if_latch;
  return is_older_stall;
}

uint8_t cal_dep_stall(const Pipeline_Latch* A, const Pipeline_Latch* B, Latch_Type latch_type, int& staller_op_id, int& needUpdated)
{
  using namespace std;
  //////////////////////    data harzard   ///////////////////
  uint8_t stall = 0;

  if( ((int)A->op_id > (int)B->op_id) && B->valid)
  {
    uint8_t src1_need = A->tr_entry.src1_needed;
    uint8_t src2_need = A->tr_entry.src2_needed;
    uint8_t dest_need = B->tr_entry.dest_needed;

    uint8_t src1_reg = A->tr_entry.src1_reg;
    uint8_t src2_reg = A->tr_entry.src2_reg;
    uint8_t dest = B->tr_entry.dest;

    uint8_t is_sr1_matched = src1_reg == dest;
    uint8_t is_sr2_matched = src2_reg == dest;

    if(is_sr1_matched)
    {
      stall = src1_need && dest_need;
    }

    if(is_sr2_matched)
    {
      stall = src2_need && dest_need;
    }

    /////////////////////////// br harzard ///////////////////////////////

    uint8_t is_cbr_inst = A->tr_entry.op_type == OP_CBR;
    uint8_t is_cc_write = B->tr_entry.cc_write;

    if(is_cbr_inst)
    {
      stall = is_cc_write;
      if(((int)B->op_id >= staller_op_id))
      {
        needUpdated = 1;
        staller_op_id = B->op_id;
      }
      else
      {
        needUpdated = 0;
      }
    }
    else
    {
	needUpdated = 0;
    }

    if(ENABLE_MEM_FWD)
    {
      if(latch_type==EX_LATCH && (B->tr_entry.op_type != OP_LD)) // forwarding
      {
        stall=0;
      }
      if(latch_type==MA_LATCH)
      {
        stall=0;
      }
    }

    if(ENABLE_EXE_FWD) 
    {
      if(latch_type==ID_LATCH && (B->tr_entry.op_type != OP_LD)) // forwarding
      {                           
        stall = 0;            
      }
    }
  }
  return stall;
}


Pipeline_Latch* get_stage_latches(Latch_Type latch_type, const Pipeline* p)
{
  Pipeline_Latch* latches = new Pipeline_Latch[PIPE_WIDTH];

  for(uint32_t i=0;i<PIPE_WIDTH;i++)
  {
    latches[i] = p->pipe_latch[latch_type][i];
  }

  return latches;
}

void printAll(const Pipeline* p)
{
  using namespace std;
  cout<<endl<<"##############################################   "<< p->stat_num_cycle<<"   ###################################"<<endl<<endl;

  for(int i=0;i<PIPE_WIDTH;i++)
  {
    cout<<"********************   Pipe "<<i<<"    ***********************" <<endl;
    cout<<"FE:  ";
    printLatch(p,IF_LATCH,i);
    cout<<"DE:  ";
    printLatch(p,ID_LATCH,i);
    cout<<"EX:  ";
    printLatch(p,EX_LATCH,i);
    cout<<"MA:  ";
    printLatch(p,MA_LATCH,i);
    cout<<endl;
  }

}

void printLatch(const Pipeline* p, Latch_Type latch_type, const int& row)
{
  using namespace std;
  string str;


  cout<<"valid: "<<(int)p->pipe_latch[latch_type][row].valid<<"\t\t";
  cout<<"op_id: "<<(int)p->pipe_latch[latch_type][row].op_id<<"\t\t";
  Op_Type type = (Op_Type)p->pipe_latch[latch_type][row].tr_entry.op_type;
  switch(type)
  {
    case OP_ALU: str="ALU";break;
    case OP_LD: str="LD";break;
    case OP_ST: str="ST";break;
    case OP_CBR: str="CBR";break;
    case OP_OTHER: str="OTHER";break;
  }
  cout<<"op_type: "<<str<<"\t\t";
  cout<<"stall: "<<(int)p->pipe_latch[latch_type][row].stall<<"\t\t";
  cout<<endl;
}
