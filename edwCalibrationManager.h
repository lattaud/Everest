#ifndef edwCalibrationManager_h
#define edwCalibrationManager_h

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "TTree.h"
#include "TH1F.h"
#include "TObject.h"


#include "edwRData.h"
#include "edwNEPALTreeManager.h"
#include "edwEverestTreeOutManager.h"


class edwCalibrationManager {
  
 public:

  edwCalibrationManager();
  edwCalibrationManager(string heatFileName,string ionFileName, string paramFileName,string structFileName);
  edwCalibrationManager(edwBaseTreeManager* nepalTreeManager, edwEverestTreeOutManager* everestTreeManager, string heatFileName,string ionFileName, string paramFileName,string structFileName);
  ~edwCalibrationManager();

  void readHeatCalibFile(string fileName);
  void readIonCalibFile(string fileName);
  void readParamCalibFile(string fileName);
  void readStrucCalibFile(string fileName);
  void setNEPALTreeManager(edwBaseTreeManager* tree) { fNepalTreeManager = tree; }
  void setEVERESTTreeManager(edwEverestTreeOutManager* tree) { fEverestTreeManager  = tree; }


  edwIonCalibData* getIonCalibData(int eventID,int boloID);
  edwHeatCalibData* getHeatCalibData(int eventID,int boloID);
  edwParamCalibData* getParamCalibData(int eventID,int boloID);
  edwStrucCalibData* getStrucCalibData(int eventID,int boloID);
  edwBaseTreeManager* getNEPALTreeManager(){return fNepalTreeManager;}

  void printIonCalibData(ostream& flux);
  void printHeatCalibData(ostream& flux);
  void printParamCalibData(ostream& flux);
  void printStrucCalibData(ostream& flux);
  void print();

  void saveCalibData();


  void calibrateAll();
  edwEnergies* getEnergiesForOption(string option, edwIonCalibData* ionCalibData, edwHeatCalibData* heatCalibData, edwParamCalibData* paramCalibData,int polMode);
  edwAmplitudes*  getAmplitudesForOption(string option);
  
  double linearHeatCalibration(string ch, double adu, edwHeatCalibData* heatCalibData,edwParamCalibData* paramCalibData );
  double nonLinearityCorrection(string ch, double linearHeat, edwHeatCalibData* heatCalibData,edwParamCalibData* paramCalibData );
  
  double ionADU2keVee(string ch, string shaper, string option, edwIonCalibData* ionCalibData);
  
 private:
  
  edwBaseTreeManager* fNepalTreeManager;
  edwEverestTreeOutManager* fEverestTreeManager;
  edwIonCalibDataMap fIonCalibDataMap;
  edwHeatCalibDataMap fHeatCalibDataMap;
  edwParamCalibDataMap fParamCalibDataMap;
  edwStrucCalibDataMap fStrucCalibDataMap;
};

#endif //edwCalibrationManager
