#ifndef edwResolutionComputer_h
#define edwResolutionComputer_h


#include "edwRData.h"
#include "edwEverestTreeOutManager.h"
#include "edwCalibrationManager.h"

class edwResolutionComputer{


 public:

  edwResolutionComputer();
  ~edwResolutionComputer();

  bool readHeatChi2CutFile(string fileName); 
  bool readIonChi2CutFile(string fileName);
  bool readElectrodCutFile(string fileName); 

  edwHeatChi2Cut* getHeatChi2Cut(int boloID, int runNumber);
  edwIonChi2Cut* getIonChi2Cut(int boloID, int runNumber);
  edwElectrodCut* getElectrodCut(int boloID, int runNumber);

  void setEVERESTTreeManager(edwEverestTreeOutManager* tree) { fEverestTreeManager  = tree; }
  void setCalibrationManager(edwCalibrationManager* cm)      { fCalibrationManager = cm;    }
  
  void computeResolutions(int boloID);
  

 private:

  edwHeatChi2CutMap fHeatChi2CutMap;
  edwIonChi2CutMap fIonChi2CutMap;
  edwElectrodCutMap fElectrodCutMap;

  edwEverestTreeOutManager* fEverestTreeManager;
  edwCalibrationManager* fCalibrationManager;


};


#endif //edwResolutionComputer_h
