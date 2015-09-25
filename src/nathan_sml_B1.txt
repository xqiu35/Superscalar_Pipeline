Opened file with command: gunzip -c ../traces/sml.ptr.gz 

** PIPELINE IS 2 WIDE **

--------------------------------------------
cycle count : 1 retired_instruction : 0
 IF:  ID:  EX:  MA: 
      1  ------  ------  ------ 
      2  ------  ------  ------ 

--------------------------------------------
cycle count : 2 retired_instruction : 0
 IF:  ID:  EX:  MA: 
      3       1  ------  ------ 
      4       2  ------  ------ 

--------------------------------------------
cycle count : 3 retired_instruction : 0
 IF:  ID:  EX:  MA: 
      5       3       1  ------ 
      6       4       2  ------ 

--------------------------------------------
cycle count : 4 retired_instruction : 0
 IF:  ID:  EX:  MA: 
      7       5       3       1 
      8       6       4       2 

--------------------------------------------
cycle count : 5 retired_instruction : 2
 IF:  ID:  EX:  MA: 
      9       7       5       3 
     10       8       6       4 

--------------------------------------------
cycle count : 6 retired_instruction : 4
 IF:  ID:  EX:  MA: 
 ------       9       7       5 
     11      10       8       6 

--------------------------------------------
cycle count : 7 retired_instruction : 6
 IF:  ID:  EX:  MA: 
 ------  ------       9       7 
 ------      11      10       8 

--------------------------------------------
cycle count : 8 retired_instruction : 8
 IF:  ID:  EX:  MA: 
 ------  ------  ------       9 
 ------  ------      11      10 

--------------------------------------------
cycle count : 9 retired_instruction : 10
 IF:  ID:  EX:  MA: 
 ------  ------  ------  ------ 
 ------  ------  ------      11 

--------------------------------------------
cycle count : 10 retired_instruction : 11
 IF:  ID:  EX:  MA: 
     12  ------  ------  ------ 
     13  ------  ------  ------ 

--------------------------------------------
cycle count : 11 retired_instruction : 11
 IF:  ID:  EX:  MA: 
     14      12  ------  ------ 
     15      13  ------  ------ 

--------------------------------------------
cycle count : 12 retired_instruction : 11
 IF:  ID:  EX:  MA: 
     16      14      12  ------ 
     17      15      13  ------ 

--------------------------------------------
cycle count : 13 retired_instruction : 11
 IF:  ID:  EX:  MA: 
 ------      16      14      12 
     18      17      15      13 

--------------------------------------------
cycle count : 14 retired_instruction : 13
 IF:  ID:  EX:  MA: 
 ------  ------      16      14 
 ------      18      17      15 

--------------------------------------------
cycle count : 15 retired_instruction : 15
 IF:  ID:  EX:  MA: 
 ------  ------  ------      16 
 ------  ------      18      17 

--------------------------------------------
cycle count : 16 retired_instruction : 17
 IF:  ID:  EX:  MA: 
 ------  ------  ------  ------ 
 ------  ------  ------      18 

--------------------------------------------
cycle count : 17 retired_instruction : 18
 IF:  ID:  EX:  MA: 
     19  ------  ------  ------ 
     20  ------  ------  ------ 

--------------------------------------------
cycle count : 18 retired_instruction : 18
 IF:  ID:  EX:  MA: 
     21      19  ------  ------ 
     22      20  ------  ------ 

--------------------------------------------
cycle count : 19 retired_instruction : 18
 IF:  ID:  EX:  MA: 
 ------      21      19  ------ 
     23      22      20  ------ 

--------------------------------------------
cycle count : 20 retired_instruction : 18
 IF:  ID:  EX:  MA: 
 ------  ------      21      19 
 ------      23      22      20 

--------------------------------------------
cycle count : 21 retired_instruction : 20
 IF:  ID:  EX:  MA: 
 ------  ------  ------      21 
 ------  ------      23      22 

--------------------------------------------
cycle count : 22 retired_instruction : 22
 IF:  ID:  EX:  MA: 
 ------  ------  ------  ------ 
 ------  ------  ------      23 

--------------------------------------------
cycle count : 23 retired_instruction : 23
 IF:  ID:  EX:  MA: 
     24  ------  ------  ------ 
     25  ------  ------  ------ 

--------------------------------------------
cycle count : 24 retired_instruction : 23
 IF:  ID:  EX:  MA: 
 ------      24  ------  ------ 
     26      25  ------  ------ 

--------------------------------------------
cycle count : 25 retired_instruction : 23
 IF:  ID:  EX:  MA: 
 ------  ------      24  ------ 
 ------      26      25  ------ 

--------------------------------------------
cycle count : 26 retired_instruction : 23
 IF:  ID:  EX:  MA: 
 ------  ------  ------      24 
 ------  ------      26      25 

--------------------------------------------
cycle count : 27 retired_instruction : 25
 IF:  ID:  EX:  MA: 
 ------  ------  ------  ------ 
 ------  ------  ------      26 

--------------------------------------------
cycle count : 28 retired_instruction : 26
 IF:  ID:  EX:  MA: 
     27  ------  ------  ------ 
     28  ------  ------  ------ 

--------------------------------------------
cycle count : 29 retired_instruction : 26
 IF:  ID:  EX:  MA: 
     29      27  ------  ------ 
     30      28  ------  ------ 

--------------------------------------------
cycle count : 30 retired_instruction : 26
 IF:  ID:  EX:  MA: 
     30      29      27  ------ 
     31  ------      28  ------ 

--------------------------------------------
cycle count : 31 retired_instruction : 26
 IF:  ID:  EX:  MA: 
     32      30      29      27 
     33      31  ------      28 

--------------------------------------------
cycle count : 32 retired_instruction : 28
 IF:  ID:  EX:  MA: 
     34      32      30      29 
     35      33      31  ------ 

--------------------------------------------
cycle count : 33 retired_instruction : 29
 IF:  ID:  EX:  MA: 
     35      34      32      30 
     36  ------      33      31 

--------------------------------------------
cycle count : 34 retired_instruction : 31
 IF:  ID:  EX:  MA: 
     37      35      34      32 
     38      36  ------      33 

--------------------------------------------
cycle count : 35 retired_instruction : 33
 IF:  ID:  EX:  MA: 
     39      37      35      34 
     40      38      36  ------ 

--------------------------------------------
cycle count : 36 retired_instruction : 34
 IF:  ID:  EX:  MA: 
     41      39      37      35 
     42      40      38      36 

--------------------------------------------
cycle count : 37 retired_instruction : 36
 IF:  ID:  EX:  MA: 
 ------      41      39      37 
 ------      42      40      38 

--------------------------------------------
cycle count : 38 retired_instruction : 38
 IF:  ID:  EX:  MA: 
 ------  ------      41      39 
 ------  ------      42      40 

--------------------------------------------
cycle count : 39 retired_instruction : 40
 IF:  ID:  EX:  MA: 
 ------  ------  ------      41 
 ------  ------  ------      42 

--------------------------------------------
cycle count : 40 retired_instruction : 42
 IF:  ID:  EX:  MA: 
     43  ------  ------  ------ 
     44  ------  ------  ------ 

--------------------------------------------
cycle count : 41 retired_instruction : 42
 IF:  ID:  EX:  MA: 
     45      43  ------  ------ 
     46      44  ------  ------ 

--------------------------------------------
cycle count : 42 retired_instruction : 42
 IF:  ID:  EX:  MA: 
     47      45      43  ------ 
     48      46      44  ------ 

--------------------------------------------
cycle count : 43 retired_instruction : 42
 IF:  ID:  EX:  MA: 
     49      47      45      43 
     50      48      46      44 

--------------------------------------------
cycle count : 44 retired_instruction : 44
 IF:  ID:  EX:  MA: 
     51      49      47      45 
     52      50      48      46 

--------------------------------------------
cycle count : 45 retired_instruction : 46
 IF:  ID:  EX:  MA: 
     53      51      49      47 
     54      52      50      48 

--------------------------------------------
cycle count : 46 retired_instruction : 48
 IF:  ID:  EX:  MA: 
 ------      53      51      49 
     55      54      52      50 

--------------------------------------------
cycle count : 47 retired_instruction : 50
 IF:  ID:  EX:  MA: 
 ------  ------      53      51 
 ------      55      54      52 

--------------------------------------------
cycle count : 48 retired_instruction : 52
 IF:  ID:  EX:  MA: 
 ------  ------  ------      53 
 ------  ------      55      54 

--------------------------------------------
cycle count : 49 retired_instruction : 54
 IF:  ID:  EX:  MA: 
 ------  ------  ------  ------ 
 ------  ------  ------      55 

--------------------------------------------
cycle count : 50 retired_instruction : 55
 IF:  ID:  EX:  MA: 
     56  ------  ------  ------ 
     57  ------  ------  ------ 

--------------------------------------------
cycle count : 51 retired_instruction : 55
 IF:  ID:  EX:  MA: 
 ------      56  ------  ------ 
     58      57  ------  ------ 

--------------------------------------------
cycle count : 52 retired_instruction : 55
 IF:  ID:  EX:  MA: 
 ------  ------      56  ------ 
 ------      58      57  ------ 

--------------------------------------------
cycle count : 53 retired_instruction : 55
 IF:  ID:  EX:  MA: 
 ------  ------  ------      56 
 ------  ------      58      57 

--------------------------------------------
cycle count : 54 retired_instruction : 57
 IF:  ID:  EX:  MA: 
 ------  ------  ------  ------ 
 ------  ------  ------      58 

--------------------------------------------
cycle count : 55 retired_instruction : 58
 IF:  ID:  EX:  MA: 
     59  ------  ------  ------ 
     60  ------  ------  ------ 

--------------------------------------------
cycle count : 56 retired_instruction : 58
 IF:  ID:  EX:  MA: 
     61      59  ------  ------ 
     62      60  ------  ------ 

--------------------------------------------
cycle count : 57 retired_instruction : 58
 IF:  ID:  EX:  MA: 
     62      61      59  ------ 
     63  ------      60  ------ 

--------------------------------------------
cycle count : 58 retired_instruction : 58
 IF:  ID:  EX:  MA: 
     64      62      61      59 
     65      63  ------      60 

--------------------------------------------
cycle count : 59 retired_instruction : 60
 IF:  ID:  EX:  MA: 
     66      64      62      61 
     67      65      63  ------ 

--------------------------------------------
cycle count : 60 retired_instruction : 61
 IF:  ID:  EX:  MA: 
     68      66      64      62 
     69      67      65      63 

--------------------------------------------
cycle count : 61 retired_instruction : 63
 IF:  ID:  EX:  MA: 
     70      68      66      64 
     71      69      67      65 

--------------------------------------------
cycle count : 62 retired_instruction : 65
 IF:  ID:  EX:  MA: 
     72      70      68      66 
     73      71      69      67 

--------------------------------------------
cycle count : 63 retired_instruction : 67
 IF:  ID:  EX:  MA: 
     74      72      70      68 
     75      73      71      69 

--------------------------------------------
cycle count : 64 retired_instruction : 69
 IF:  ID:  EX:  MA: 
     76      74      72      70 
     77      75      73      71 

--------------------------------------------
cycle count : 65 retired_instruction : 71
 IF:  ID:  EX:  MA: 
     78      76      74      72 
     79      77      75      73 

--------------------------------------------
cycle count : 66 retired_instruction : 73
 IF:  ID:  EX:  MA: 
     80      78      76      74 
     81      79      77      75 

--------------------------------------------
cycle count : 67 retired_instruction : 75
 IF:  ID:  EX:  MA: 
     82      80      78      76 
     83      81      79      77 

--------------------------------------------
cycle count : 68 retired_instruction : 77
 IF:  ID:  EX:  MA: 
     84      82      80      78 
     85      83      81      79 

--------------------------------------------
cycle count : 69 retired_instruction : 79
 IF:  ID:  EX:  MA: 
     86      84      82      80 
     87      85      83      81 

--------------------------------------------
cycle count : 70 retired_instruction : 81
 IF:  ID:  EX:  MA: 
     88      86      84      82 
     89      87      85      83 

--------------------------------------------
cycle count : 71 retired_instruction : 83
 IF:  ID:  EX:  MA: 
     90      88      86      84 
     91      89      87      85 

--------------------------------------------
cycle count : 72 retired_instruction : 85
 IF:  ID:  EX:  MA: 
     92      90      88      86 
     93      91      89      87 

--------------------------------------------
cycle count : 73 retired_instruction : 87
 IF:  ID:  EX:  MA: 
     94      92      90      88 
     95      93      91      89 

--------------------------------------------
cycle count : 74 retired_instruction : 89
 IF:  ID:  EX:  MA: 
     96      94      92      90 
     97      95      93      91 

--------------------------------------------
cycle count : 75 retired_instruction : 91
 IF:  ID:  EX:  MA: 
     98      96      94      92 
     99      97      95      93 

--------------------------------------------
cycle count : 76 retired_instruction : 93
 IF:  ID:  EX:  MA: 
    100      98      96      94 
 ------      99      97      95 

--------------------------------------------
cycle count : 77 retired_instruction : 95
 IF:  ID:  EX:  MA: 
 ------     100      98      96 
 ------  ------      99      97 

--------------------------------------------
cycle count : 78 retired_instruction : 97
 IF:  ID:  EX:  MA: 
 ------  ------     100      98 
 ------  ------  ------      99 

--------------------------------------------
cycle count : 79 retired_instruction : 99
 IF:  ID:  EX:  MA: 
 ------  ------  ------     100 
 ------  ------  ------  ------ 

--------------------------------------------
cycle count : 80 retired_instruction : 100
 IF:  ID:  EX:  MA: 
 ------  ------  ------  ------ 
 ------  ------  ------  ------ 




LAB2_NUM_INST           	 :        100
LAB2_NUM_CYCLES         	 :         80
LAB2_CPI                	 :      0.800
LAB2_BPRED_BRANCHES     	 :         15
LAB2_BPRED_MISPRED      	 :          7
LAB2_MISPRED_RATE       	 :     46.667

