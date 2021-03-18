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
echo "env $bigRunNb, $INDIR, $OUTDIR, $EDWDATADIR"
echo "... Program copying ... #########################################"
echo "cp -r /pbs/home/h/hlattaud/Everest_from_git/everest.exe ."
cp  /pbs/home/h/hlattaud/Everest_from_git/everest.exe .
echo "cp $EDWDATADIR/*.NEPALcalib ."
cp  $EDWDATADIR/*.NEPALcalib .
echo "cp $EDWDATADIR/chi*.cut ."
cp  $EDWDATADIR/*.cut .
echo "cp $INDIR/Processed*.root ."
cp $INDIR/Processed*.root .

ls -lrt

#export ROOTSYS=/pbs/throng/edelweis/Ricochet/soft/root-6.16.00/
export PATH=$ROOTSYS/bin:$PATH
#export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
ccenv root 6.08.02
echo "... Program running ... `date` ###########"


for inFile in `ls -1 Processed*.root` ; do
    export outFile=`echo "$inFile" | sed -e 's/ProcessedData/CalibratedData/g'`
    echo "./everest.exe -d ./ -r $bigRunNb -i $inFile -o $outFile -s $runNb"
    ./everest.exe -d ./ -r $bigRunNb -i $inFile -o $outFile -s $runNb
done    


echo "--> done !"
ls -lrt
echo " "
echo " "
echo "... Saving output files ... #####################################"
echo "Copying files ..."
echo "cp Calibrated*.root $OUTDIR/"
cp Calibrated*.root $OUTDIR/
echo "--> done !"
echo " "
echo "... End of job ##################################################"

exit
