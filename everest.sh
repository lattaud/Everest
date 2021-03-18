#!/bin/sh
#PBS -l platform=LINUX
#PBS -l T=1:00
#PBS -l M=4G
#PBS -l scratch=2048MB
#PBS -l spool=4096KB
#PBS -l vmem=4G
#PBS -eo
#PBS -mb
#PBS -me


echo " "
echo "Start of job ... ########################################"
echo " "
echo "env $bigRunNb, $inputFile, $OUTDIR, $runNb, $det,  ${EDWDATADIR}"
echo "... Program copying ... #########################################"
echo "cp -r /pbs/throng/edelweis/cazes/EDW3/Processing/calib/EVEREST/everest.exe ."
cp  /pbs/throng/edelweis/cazes/EDW3/Processing/calib/EVEREST/everest.exe .
echo "cp $EDWDATADIR/*.NEPALcalib ."
cp  $EDWDATADIR/*.NEPALcalib .
echo "cp $inFile ."
cp $inputFile .

ls -lrt

export ROOTSYS=/pbs/throng/edelweis/Ricochet/soft/root-6.16.00/
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH

echo "... Program running ... `date` ###########"

export inFileShort=`echo ${inputFile} | awk -F"/" '{print $NF}'`
export outFileShort=`echo "$inFileShort" | sed -e 's/ProcessedData/CalibratedData/g'`


echo "./everest.exe -d ./ -r $bigRunNb -i $inFileShort -o $outFileShort -s $runNb"
./everest.exe -d ./ -r $bigRunNb -i $inFileShort -o $outFileShort -s $runNb

echo "--> done !"
ls -lrt
echo " "
echo " "
echo "... Saving output files ... #####################################"
echo "Copying files ..."
echo "cp $outFileShort $OUTDIR/"
cp $outFileShort $OUTDIR/
echo "--> done !"
echo " "
echo "... End of job ##################################################"

exit
