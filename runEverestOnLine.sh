#!/bin/bash

echo "---------------------------------"
date
echo "---------------------------------"

#
#  Do calibration on CCA
#
export EDWDATADIR="/sps/edelweis/rootDataRun317/streams/prodg"
export bigRunNb="317"
export DETECTOR="RED30"

echo "calibration for run $bigRunNb"
for detPath in `ls -d1 $EDWDATADIR/u*/$DETECTOR` ; do
  echo $detPath
  export INDIR=$detPath
  export OUTDIR=$detPath/CalibratedData
  export runNb=`echo $detPath | awk -F"'{print $(NF-2)}' `
  echo "runNb $runNb"
  export det=`echo ${detPath} | awk -F"/" '{print $(NF-1)}'`
  echo "mkdir -p ${OUTDIR}"
  mkdir -p ${OUTDIR}
  for inFile in `ls -1 ${INDIR}/Processed*.root` ; do
    export outFile=`echo "$inFile" | sed -e 's/ProcessedData/CalibratedData/g'`
    echo "./everest.exe -d ${EDWDATADIR} -r $bigRunNb -i $inFile -o $outFile -s $runNb"
    ./everest.exe -d ${EDWDATADIR} -r $bigRunNb -i $inFile -o $outFile -s $runNb
  done
done

exit
