
######################################################################################
# This scripts runs all four traces
# You will need to first compile your code in ../src before launching this script
# the results are stored in the ../results/ folder 
######################################################################################



########## ---------------  A.1 ---------------- ################

../src/sim -pipewidth 1 ../traces/bzip2.ptr.gz > ../results/A1.bzip2.res 
../src/sim -pipewidth 1 ../traces/gcc.ptr.gz   > ../results/A1.gcc.res 
../src/sim -pipewidth 1 ../traces/libq.ptr.gz  > ../results/A1.libq.res 
../src/sim -pipewidth 1 ../traces/mcf.ptr.gz   > ../results/A1.mcf.res
../src/sim -pipewidth 1 ../traces/sml.ptr.gz   > ../results/A1.sml.res

########## ---------------  A.2 ---------------- ################

../src/sim -pipewidth 2 ../traces/bzip2.ptr.gz > ../results/A2.bzip2.res 
../src/sim -pipewidth 2 ../traces/gcc.ptr.gz   > ../results/A2.gcc.res 
../src/sim -pipewidth 2 ../traces/libq.ptr.gz  > ../results/A2.libq.res 
../src/sim -pipewidth 2 ../traces/mcf.ptr.gz   > ../results/A2.mcf.res
../src/sim -pipewidth 2 ../traces/sml.ptr.gz   > ../results/A2.sml.res

########## ---------------  A3 ---------------- ################

../src/sim -pipewidth 2 -enablememfwd -enableexefwd ../traces/bzip2.ptr.gz > ../results/A3.bzip2.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd ../traces/gcc.ptr.gz   > ../results/A3.gcc.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd ../traces/libq.ptr.gz  > ../results/A3.libq.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd ../traces/mcf.ptr.gz   > ../results/A3.mcf.res
../src/sim -pipewidth 2 -enablememfwd -enableexefwd ../traces/sml.ptr.gz   > ../results/A3.sml.res

########## ---------------  B1 ---------------- ################

../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 1 ../traces/bzip2.ptr.gz > ../results/B1.bzip2.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 1 ../traces/gcc.ptr.gz   > ../results/B1.gcc.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 1 ../traces/libq.ptr.gz  > ../results/B1.libq.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 1 ../traces/mcf.ptr.gz   > ../results/B1.mcf.res
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 1 ../traces/sml.ptr.gz   > ../results/B1.sml.res

########## ---------------  B2 ---------------- ################

../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 2 ../traces/bzip2.ptr.gz > ../results/B2.bzip2.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 2 ../traces/gcc.ptr.gz   > ../results/B2.gcc.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 2 ../traces/libq.ptr.gz  > ../results/B2.libq.res 
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 2 ../traces/mcf.ptr.gz  > ../results/B2.mcf.res
../src/sim -pipewidth 2 -enablememfwd -enableexefwd -bpredpolicy 2 ../traces/sml.ptr.gz  > ../results/B2.sml.res
########## ---------------  GenReport ---------------- ################

grep LAB2_CPI ../results/A?.*.res > report.txt
grep LAB2_CPI ../results/B?.*.res >> report.txt
grep LAB2_MISPRED_RATE ../results/B?.*.res >> report.txt

######### ------- Goodbye -------- ##################

echo "Done. Check report.txt, and .res files in ../results";

