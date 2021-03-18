#!/bin/bash

echo "---------------------------------"
date
echo "---------------------------------"

#
#  Do calibration on CCA
#

#export STUDY="TOTO"
#export STUDY="ULTIMATE_2"

export EDWDATADIR="/sps/edelweis/rootDataRun317/streams/prodg"

#export SIMUDIR="/sps/edelweis/rootDataRun317/streams/test/$STUDY/Data"
export SIMUDIR="/sps/edelweis/rootDataRun317/streams/prodg"

export bigRunNb="317"

export DETECTOR="RED30" # NbSi209
export EVEREST_PROG_DIR="/pbs/home/h/hlattaud/Everest_from_git"

echo "calibration for run $bigRunNb"
for detPath in `ls -d1 $SIMUDIR/td*/$DETECTOR` ; do
#for detPath in `ls -d1 $EDWDATADIR/t*/*/` ; do
  echo "DETPATH="$detPath
  export INDIR=$detPath
  export OUTDIR=$detPath/CalibratedData
  export runNb=`echo $detPath | awk -F"/" '{print $(NF-2)}' `
  echo "runNb $runNb"
  export det=`echo ${detPath} | awk -F"/" '{print $(NF-1)}'`

  if [ ! -d $OUTDIR ]; then
  echo "mkdir -p ${OUTDIR}"
  mkdir -p ${OUTDIR}
  fi

  for inFile in `ls -1 ${INDIR}/Processed*.root` ; do
    echo "runNb $runNb"
    echo "det $det"
    export outFile=`echo "$inFile" | awk -F"/" '{print $NF}' | sed -e 's/ProcessedData/CalibratedData/g'`
    echo "everest.exe -d $EDWDATADIR -r $bigRunNb -i $inFile -o $OUTDIR/$outFile -s $runNb"
    ./everest.exe -d $EDWDATADIR -r $bigRunNb -i $inFile -o $OUTDIR/$outFile -s $runNb

 echo "----------------------------------------------------------------------------------------------"
  done
done

exit
