#include "bpred.h"

#define TAKEN   true
#define NOTTAKEN false
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

BPRED::BPRED(uint32_t policy)
{
	// init policy.
	/*switch(policy)
	{
		case 0:this->policy = BPRED_PERFECT;break;
		case 1:this->policy = BPRED_ALWAYS_TAKEN;break;
		case 2:this->policy = BPRED_GSHARE;break;
		case 3:this->policy = NUM_BPRED_TYPE;break;
		default: this->policy = BPRED_PERFECT;
	}*/
	this->policy = policy;
	// init data
	GHR=0;
	stat_num_branches = 0;
	stat_num_mispred = 0;
	for(int i=0;i<4096;i++)
	{
	    PHT[i] = 2;
	}
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

bool BPRED::GetPrediction(uint32_t PC)
{
	this->stat_num_branches++;
	if(policy==BPRED_ALWAYS_TAKEN)
	{
		return TAKEN;
	}
	else if(policy==2)
	{
		int index = ((PC & 4095) ^ GHR) & 4095 ;
		uint32_t pred_dir = PHT[index];

		if(pred_dir==0 || pred_dir==1)
		{
			return NOTTAKEN;
		}
		else if(pred_dir==2 || pred_dir==3)
		{
			return TAKEN;
		}
	}
	else
	{
		return TAKEN;
	}
}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
void  BPRED::UpdatePredictor(uint32_t PC, bool resolveDir, bool predDir)
{
	
	if(resolveDir != predDir)
	{
		this->stat_num_mispred++;
	}

	if(policy==2)
	{
	    int index = ((PC & 4095) ^ GHR) & 4095 ;

	    if(resolveDir) // if resolve Dir is taken
	    { 
		PHT[index] = SatIncrement(PHT[index], 3); // incre
		GHR = (GHR<< 1) + 1; // left shift by 1, and filling 1 
		GHR = GHR & 4095; // lower 12 bits
	    } 
	    else 
	    { 
		PHT[index] = SatDecrement(PHT[index]); // not taken, dec
		GHR = GHR << 1;	// left shift by 1, filling 0
		GHR = GHR & 4095; // lower 12 bits 
	    }    
	}
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

