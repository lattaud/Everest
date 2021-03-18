CC=g++
CFLAGS=-Wall -fPIC -pipe -O -std=c++11
ROOTFLAGS=`root-config --glibs`

OBJ = everest.o edwBaseTreeManager.o edwNEPALStreamTreeManager.o edwRData.o edwEverestTreeOutManager.o edwCalibrationManager.o edwResolutionComputer.o edwNEPALTreeManager.o
#INC=-I"/usr/include/" -I"${G4WORDIR}/../include/" -I"${ROOTSYS}/include" -I"${CLHEP_INCLUDE_DIR}"
INC=-I"/usr/include/" -I"${ROOTSYS}/include/root"  -I"./"

all:  $(OBJ)
	$(CC) -o everest.exe $(OBJ) ${ROOTFLAGS} 
#	rm -f ${OBJ}
.cc.o:
	$(CC) ${INC} -c ${CFLAGS} -o $@ $<
clean:
	rm -f $(OBJ) everest.exe monitoring.exe
