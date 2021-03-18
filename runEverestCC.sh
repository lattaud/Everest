#!/bin/bash

echo "---------------------------------"
date
echo "---------------------------------"

#
#  Do calibration on CCA
#
export EDWDATADIR="/sps/edelweis/rootDataRun317/streams/prodk"
export bigRunNb="317"

echo "calibration for run $bigRunNb"
for detPath in `ls -d1 $EDWDATADIR/u*/*/` ; do
  echo $detPath
  export INDIR=$detPath
  export OUTDIR=$detPath/CalibratedData
  export runNb=`echo $detPath | awk -F"/" '{print $7}' `
#      echo "runNb $runNb"
  export det=`echo ${detPath} | awk -F"/" '{print $(NF-1)}'`
#      echo "mkdir -p $detPath/CalibratedData"
  if [ ! -d $OUTDIR ]; then
  echo "mkdir -p ${OUTDIR}"
  mkdir -p ${OUTDIR}
  fi
  export jobNb="${runNb}_${det}"
  qsub -v bigRunNb,INDIR,OUTDIR,runNb,det,EDWDATADIR -N $jobNb -P P_edelweis -l vmem=4G -l sps=1 -j y -o /pbs/home/h/hlattaud/Everest_from_git/Data_log/job_${jobNb}.log ./everest2.sh
  #fi
done

exit
