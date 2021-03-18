///ooooooOOOOOOOO Programme analyse MV modifiee par Antoine pour EDWII -> EDW3
//oooooooOOOOOOOOOOOOOOOOOOOOOOO

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cfloat>

using namespace std;

#include "edwCalibrationManager.h"
#include "edwNEPALTreeManager.h"
#include "edwNEPALStreamTreeManager.h"
#include "edwEverestTreeOutManager.h"
#include "edwResolutionComputer.h"

int main(int argc, char** argv) {

  string calibFileDirectory = "";
  string runName = "311";
  string inputFileName = "empty";
  string outputFileName = "empty";
  string sambaRun;

  for(int iParam=1 ; iParam<argc ; iParam++){
    if(argv[iParam][0]=='-') {
      switch(argv[iParam][1]) {
      case 'd':
	if(iParam+1<argc && argv[iParam+1][0]!='-') {
	  calibFileDirectory = argv[iParam+1];
	} else {
	  cout << "directory name missing" << endl;
	  exit(1);
	}
	break;
      case 'r':
	if(iParam+1<argc && argv[iParam+1][0]!='-') {
	  runName = argv[iParam+1];
	} else {
	  cout << "big run number missing" << endl;
	  exit(1);
	}
	break;
      case 'i':
	if(iParam+1<argc && argv[iParam+1][0]!='-') {
	  inputFileName = argv[iParam+1];
	} else {
	  cout << "input file name missing" << endl;
	  exit(1);
	}
	break;
      case 'o':
	if(iParam+1<argc && argv[iParam+1][0]!='-') {
	  outputFileName = argv[iParam+1];
	} else {
	  cout << "output file name missing" << endl;
	  exit(1);
	}
	break;
      case 's':
	if(iParam+1<argc && argv[iParam+1][0]!='-') {
	  sambaRun = argv[iParam+1];
	} else {
	  cout << "output file name missing" << endl;
	  exit(1);
	}
	break;
      case 'h':
	cout << "EDELWEISS CAIBRATION PROGRAM" << endl;
	cout << "commands are : " << endl;
	cout << "      -d <calib dir>   : calib files directory" << endl;
	cout << "      -r <runNb>       : big run number (defautlt 311)" << endl;
	cout << "      -i <inFileName>  : input File Name" << endl;
	cout << "      -o <outFileName> : output File Name" << endl;
	cout << "      -s <samba run>   : samba run" << endl;
	cout << "      -h               : Print the help" << endl;
	exit(0);
      default:
	cout << "unknown command " << argv[iParam] << " , use the -h command for help" << endl;
	exit(1);
      }
    }
  }

  if(inputFileName=="empty") {
    cout << "EVEREST : ERROR :  input File Name missing" << endl;
    exit(1);
  }
  if(outputFileName=="empty") {
    cout << "EVEREST : ERROR :  output File Name missing" << endl;
    exit(1);
  }

  TFile *f = new TFile(inputFileName.c_str());
  TTree* t = (TTree*) f->Get("EventTree_trig_Normal_filt"); 
  bool isStreamFile = t;
  if(t) t->Delete();
  f->Close();

  string suffix = isStreamFile ? ".NEPALcalib" : ".calib"; 


  string chalFile = calibFileDirectory + "/chal" + runName + suffix;
  string ionFile = calibFileDirectory + "/ion" + runName + suffix;
  string paraFile = calibFileDirectory + "/para" + runName + suffix;
  string strucFile = calibFileDirectory + "/struc" + runName + suffix;

  edwCalibrationManager* theCalibrationManager = new edwCalibrationManager();
  theCalibrationManager->readHeatCalibFile(chalFile);
  theCalibrationManager->readIonCalibFile(ionFile);
  theCalibrationManager->readParamCalibFile(paraFile);
  theCalibrationManager->readStrucCalibFile(strucFile);
  //  theCalibrationManager->print();


  bool doResolution = true;
  edwBaseTreeManager* inputTree;
  if(isStreamFile) {
    inputTree = new edwNEPALStreamTreeManager(inputFileName.c_str());
  } else {
    inputTree = new edwNEPALTreeManager(inputFileName.c_str());
    if(inputFileName.find("trig") != string::npos ) doResolution = false; 
  }

  inputTree->setSambaRun(sambaRun);
  theCalibrationManager->setNEPALTreeManager(inputTree);


  edwEverestTreeOutManager* outputTree = new edwEverestTreeOutManager(outputFileName);
  outputTree->SetProcessingMethods(inputTree->getProcessingMethodes());
  theCalibrationManager->setEVERESTTreeManager(outputTree);

  cout << "calibration " << endl;


  theCalibrationManager->saveCalibData();
  theCalibrationManager->calibrateAll();

  cout << "done" << endl;

  if(doResolution) {

    cout << "resolution" << endl;
    
    string heatCutFile = calibFileDirectory + "/chiheat.cut";
    string ionCutFile =  calibFileDirectory + "/chiioni.cut";

    edwResolutionComputer* theResolutionComputer = new edwResolutionComputer();
    theResolutionComputer->setEVERESTTreeManager(outputTree);
    doResolution = theResolutionComputer->readHeatChi2CutFile(heatCutFile);
    
    if(doResolution) doResolution = theResolutionComputer->readIonChi2CutFile(ionCutFile);
    theResolutionComputer->setCalibrationManager(theCalibrationManager);

    if(doResolution) theResolutionComputer->computeResolutions(inputTree->getBoloID());
    else cout << "resolution file not found. Resolution not computed." << endl;

  }

  outputTree->Close();

  return 0;


}
