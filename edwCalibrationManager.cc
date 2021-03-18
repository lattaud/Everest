#include "edwCalibrationManager.h"
#include "edwRData.h"

#include <string>

#include <cmath>
using namespace std;

#include "TString.h"


////////////////////// edwCalibrationManager ///////////////////////

// edwCalibrationManager* edwCalibrationManager::fCalibManager = NULL;


// constructor - destructor

edwCalibrationManager::edwCalibrationManager() {
}


edwCalibrationManager::edwCalibrationManager(string heatFileName, string ionFileName,string paramFileName,string strucFileName) {
  readHeatCalibFile(heatFileName);
  readIonCalibFile(ionFileName);
  readParamCalibFile(paramFileName);
  readStrucCalibFile(strucFileName);
}

edwCalibrationManager::edwCalibrationManager(edwBaseTreeManager* nepalTreeManager, edwEverestTreeOutManager* everestTreeManager, string heatFileName, string ionFileName,string paramFileName,string strucFileName) {

  fNepalTreeManager =  nepalTreeManager;
  fEverestTreeManager  = everestTreeManager;

  readHeatCalibFile(heatFileName);
  readIonCalibFile(ionFileName);
  readParamCalibFile(paramFileName);
  readStrucCalibFile(strucFileName);
}

edwCalibrationManager::~edwCalibrationManager() {
  for (edwIonCalibDataMapIterator it=fIonCalibDataMap.begin(); it!=fIonCalibDataMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      delete (*it).second[i];
    }
    (*it).second.clear();
  }
  fIonCalibDataMap.clear();

  for (edwHeatCalibDataMapIterator it=fHeatCalibDataMap.begin(); it!=fHeatCalibDataMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      delete (*it).second[i];
    }
    (*it).second.clear();
  }
  fHeatCalibDataMap.clear();

  for (edwParamCalibDataMapIterator it=fParamCalibDataMap.begin(); it!=fParamCalibDataMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      delete (*it).second[i];
    }
    (*it).second.clear();
  }
  fParamCalibDataMap.clear();

}


// read input files

void edwCalibrationManager::readIonCalibFile(string fileName){

  ifstream f(fileName.c_str());
  if(!f.is_open()) {
    cout << "edwCalibrationManager::readIonCalibFile file " << fileName << " not found" << endl;
  }

  string dummyString;
  getline(f,dummyString);
  getline(f,dummyString);
  getline(f,dummyString);

  int dummyInt;
  int boloID;

  int anaRunNumber = 0;
  double gainA,gainB,gainC,gainD;
  double xtAB,xtBA,xtCD,xtDC,xtAC,xtCA,xtBD,xtDB,xtAD,xtDA,xtCB,xtBC;

  while(f>>dummyInt >> boloID ) {

    if(boloID/100 == 5) {
        // cupid detector
        do {
                f>> anaRunNumber;
                getline(f,dummyString);
        } while(anaRunNumber!=-1);
    } else {


        f>> anaRunNumber >> gainA >> gainB >> gainC >> gainD
         >> xtAB >> xtBA >> xtCD >> xtDC >> xtAC >> xtCA >> xtBD >> xtDB >> xtAD >> xtDA >> xtCB >> xtBC;

        while(anaRunNumber!=-1) {


            edwIonCalibData* aID = new edwIonCalibData(anaRunNumber);
            aID->setGainA(gainA);
            aID->setGainB(gainB);
            aID->setGainC(gainC);
            aID->setGainD(gainD);

            aID->setCrossTalkAB(xtAB);
            aID->setCrossTalkAC(xtAC);
            aID->setCrossTalkAD(xtAD);
            aID->setCrossTalkBA(xtBA);
            aID->setCrossTalkBC(xtBC);
            aID->setCrossTalkBD(xtBD);
            aID->setCrossTalkCA(xtCA);
            aID->setCrossTalkCB(xtCB);
            aID->setCrossTalkCD(xtCD);
            aID->setCrossTalkDA(xtDA);
            aID->setCrossTalkDB(xtDB);
            aID->setCrossTalkDC(xtDC);

            fIonCalibDataMap[boloID].push_back(aID);

            f>> anaRunNumber >> gainA >> gainB >> gainC >> gainD
             >> xtAB >> xtBA >> xtCD >> xtDC >> xtAC >> xtCA >> xtBD >> xtDB >> xtAD >> xtDA >> xtCB >> xtBC;
      }
    }
  }
  f.close();

  int index = 0;
  for (edwIonCalibDataMapIterator it=fIonCalibDataMap.begin(); it!=fIonCalibDataMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      (*it).second[i]->setIndex(index++);
    }
  }

}


void edwCalibrationManager::readHeatCalibFile(string fileName){

  ifstream f(fileName.c_str());
  if(!f.is_open()) {
    cout << "edwCalibrationManager::readHeatCalibFile file " << fileName << " not found" << endl;
  }

  string dummyString;
  getline(f,dummyString);
  getline(f,dummyString);
  getline(f,dummyString);

  int dummyInt;
  int boloID;

  int anaRunNumber = 0;
  double voltage,gainA,gainB;
  double dummyDouble;
  double heatTimeDependence;

  while(f>>dummyInt >> boloID ) {

    f>> anaRunNumber >> voltage >> gainA >> gainB >> heatTimeDependence >> dummyDouble >> dummyDouble >> dummyDouble >> dummyDouble ;
    while (anaRunNumber!=-1){
      edwHeatCalibData* aHD = new edwHeatCalibData(anaRunNumber,voltage,gainA,gainB,heatTimeDependence);
      fHeatCalibDataMap[boloID].push_back(aHD);
      f>> anaRunNumber >> voltage >> gainA >> gainB >> heatTimeDependence >> dummyDouble >> dummyDouble >> dummyDouble >> dummyDouble ;
    }

  }

  f.close();

  int index = 0;
  for (edwHeatCalibDataMapIterator it=fHeatCalibDataMap.begin(); it!=fHeatCalibDataMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      (*it).second[i]->setIndex(index++);
    }
  }


}

void edwCalibrationManager::readParamCalibFile(string fileName){

  ifstream f(fileName.c_str());
  if(!f.is_open()) {
    cout << "edwCalibrationManager::readParamCalibFile file " << fileName << " not found" << endl;
  }
  string dummyString;
  getline(f,dummyString);
  getline(f,dummyString);
  getline(f,dummyString);

  int dummyInt;
  int boloID;

  int anaRunNumber = 0;
  double dummyDouble;

  double FiducialVoltage;
  double VetoVoltage;

  double IoniXtalkCutA;
  double IoniXtalkCutB;
  double IoniXtalkCutC;
  double IoniXtalkCutD;

  double HeatCorrA;
  double HeatCorrB;
  double NonLinearityA[5];
  double ThresholdCorrA;// renommer Samba2ADU
  double ThresholdCorrB;// renommer Samba2ADU
  //  double ThresholdCorr;
  double NonLinearityB[5];
  double HeatAweight;
  double IonBweight;

  while(f>>dummyInt >> boloID ) {

    f>> anaRunNumber >> FiducialVoltage >> VetoVoltage >> dummyDouble >> IonBweight >> dummyDouble >> IoniXtalkCutA >> IoniXtalkCutB >> IoniXtalkCutC >> IoniXtalkCutD >> HeatCorrA >> HeatCorrB;
    for(int i=0;i<5;i++)  f>> NonLinearityA[i];
    f >> ThresholdCorrA;
    for(int i=0;i<5;i++)  f>> NonLinearityB[i];
    f>> ThresholdCorrB >> HeatAweight >> dummyDouble;

    while (anaRunNumber!=-1){
      edwParamCalibData* aPD = new edwParamCalibData(anaRunNumber);

      aPD->setFiducialVoltage(FiducialVoltage);
      aPD->setVetoVoltage(VetoVoltage);
      aPD->setIoniXtalkCutA(IoniXtalkCutA);
      aPD->setIoniXtalkCutB(IoniXtalkCutB);
      aPD->setIoniXtalkCutC(IoniXtalkCutC);
      aPD->setIoniXtalkCutD(IoniXtalkCutD);
      aPD->setHeatCorrA(HeatCorrA);
      aPD->setHeatCorrB(HeatCorrB);
      for(int i=0;i<5;i++) aPD->setNonLinearityA(i, NonLinearityA[i]);
      aPD->setThresholdCorrA(ThresholdCorrA);
      for(int i=0;i<5;i++) aPD->setNonLinearityB(i, NonLinearityB[i]);
      aPD->setThresholdCorrB(ThresholdCorrB);
      aPD->setHeatAweight(HeatAweight);
      aPD->setIonBweight(IonBweight);

      fParamCalibDataMap[boloID].push_back(aPD);

      f>> anaRunNumber >> FiducialVoltage >> VetoVoltage >> dummyDouble >> dummyDouble >> dummyDouble >> IoniXtalkCutA >> IoniXtalkCutB >> IoniXtalkCutC >> IoniXtalkCutD >> HeatCorrA >> HeatCorrB;
      for(int i=0;i<5;i++)  f>> NonLinearityA[i];
      f >> ThresholdCorrA;
      for(int i=0;i<5;i++)  f>> NonLinearityB[i];
      f >> ThresholdCorrB >> HeatAweight >> dummyDouble;

    }

  }

  f.close();

  int index = 0;
  for (edwParamCalibDataMapIterator it=fParamCalibDataMap.begin(); it!=fParamCalibDataMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      (*it).second[i]->setIndex(index++);
    }
  }

}

void edwCalibrationManager::saveCalibData(){

  if(!fEverestTreeManager) {
    cout << " edwCalibrationManager::FillCalib no fEverestTreeManager found, filling impossible" << endl;
    return;
  }

  fEverestTreeManager->FillCalib(fIonCalibDataMap);
  fEverestTreeManager->FillCalib(fHeatCalibDataMap);
  fEverestTreeManager->FillCalib(fParamCalibDataMap);
  fEverestTreeManager->FillCalib(fStrucCalibDataMap);

  fEverestTreeManager->WriteCalibTree();

}


void edwCalibrationManager::readStrucCalibFile(string fileName){

  ifstream f(fileName.c_str());
  if(!f.is_open()) {
    cout << "edwCalibrationManager::readStrucCalibFile file " << fileName << " not found" << endl;
  }
  string dummyString;
  getline(f,dummyString);
  getline(f,dummyString);
  getline(f,dummyString);

  int dummyInt;
  int boloID;

  int anaRunNumber = 0;
  int boloIndexInSamba;
  int heatAbitNumber;
  int heatBbitNumber;
  int polarisationMode;

  while(f>>dummyInt) {

    f>> anaRunNumber >> dummyInt >> boloIndexInSamba >> dummyInt >> dummyInt >> dummyInt >> heatAbitNumber >> heatBbitNumber >> polarisationMode >> boloID;

    while (anaRunNumber!=-1){
      edwStrucCalibData* aSD = new edwStrucCalibData(anaRunNumber);

      aSD->setBoloIndexInSamba(boloIndexInSamba);
      aSD->setHeatAbitNumber(heatAbitNumber);
      aSD->setHeatBbitNumber(heatBbitNumber);
      aSD->setPolarisationMode(polarisationMode);

      fStrucCalibDataMap[boloID].push_back(aSD);

      f>> anaRunNumber >> dummyInt >> boloIndexInSamba >> dummyInt >> dummyInt >> dummyInt >> heatAbitNumber >> heatBbitNumber >> polarisationMode >> boloID;

    }

  }

  f.close();

  int index = 0;
  for (edwStrucCalibDataMapIterator it=fStrucCalibDataMap.begin(); it!=fStrucCalibDataMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      (*it).second[i]->setIndex(index++);
    }
  }


}


// getter

edwIonCalibData* edwCalibrationManager::getIonCalibData(int anaRunNumber,int boloID) {

  if(fIonCalibDataMap[boloID].empty()) {
    cout << "no ion calibration data for bolo " << boloID << endl;
    exit(0);
  }

  for(unsigned int i = 0;i<fIonCalibDataMap[boloID].size();i++) {
    if(fIonCalibDataMap[boloID][i]->getAnaRunNumber()>anaRunNumber) {
      if(i==0) {
	return fIonCalibDataMap[boloID][i];
      } else {
        //std::cout<<fIonCalibDataMap[boloID][i-1]->getAnaRunNumber()<<std::endl;
	return fIonCalibDataMap[boloID][i-1];
      }
    }
  }

  
  return fIonCalibDataMap[boloID].back();

}


edwHeatCalibData* edwCalibrationManager::getHeatCalibData(int anaRunNumber,int boloID) {

  if(fHeatCalibDataMap[boloID].empty()) {
    cout << "no heat calibration data for bolo " << boloID << endl;
    exit(0);
  }

  for(unsigned int i = 0;i<fHeatCalibDataMap[boloID].size();i++) {
    if(fHeatCalibDataMap[boloID][i]->getAnaRunNumber()>anaRunNumber) {
      if(i==0) {
	return fHeatCalibDataMap[boloID][i];
      } else {
        // std::cout<<fHeatCalibDataMap[boloID][i-1]->getGainA()<<std::endl;
	return fHeatCalibDataMap[boloID][i-1];	
      }
    }
  }

  return fHeatCalibDataMap[boloID].back();

}


edwParamCalibData* edwCalibrationManager::getParamCalibData(int anaRunNumber,int boloID) {

  if(fParamCalibDataMap[boloID].empty()) {
    cout << "no param calibration data for bolo " << boloID << endl;
    exit(0);
  }

  for(unsigned int i = 0;i<fParamCalibDataMap[boloID].size();i++) {
    if(fParamCalibDataMap[boloID][i]->getAnaRunNumber()>anaRunNumber) {
      if(i==0) {
	return fParamCalibDataMap[boloID][i];
      } else {
       // std::cout<<fParamCalibDataMap[boloID][i-1]->getAnaRunNumber()<<std::endl;
	return fParamCalibDataMap[boloID][i-1];
      }
    }
  }

  return fParamCalibDataMap[boloID].back();

}

edwStrucCalibData* edwCalibrationManager::getStrucCalibData(int anaRunNumber,int boloID) {

  if(fStrucCalibDataMap[boloID].empty()) {
    cout << "no struc calibration data for bolo " << boloID << endl;
    exit(0);
  }

  for(unsigned int i = 0;i<fStrucCalibDataMap[boloID].size();i++) {
    if(fStrucCalibDataMap[boloID][i]->getAnaRunNumber()>anaRunNumber) {
      if(i==0) {
	return fStrucCalibDataMap[boloID][i];
      } else {
       // std::cout<<fStrucCalibDataMap[boloID][i-1]->getAnaRunNumber()<<std::endl;
	return fStrucCalibDataMap[boloID][i-1];
      }
    }
  }

  return fStrucCalibDataMap[boloID].back();

}

// print all data

void edwCalibrationManager::printIonCalibData(ostream& flux) {

  flux << "C   -----Runs----"<<endl;
  flux << "C Debut  ------- Gains --------         1     2     3     4     5     6     7     8     9    10    11    12"<<endl;
  flux << "C        A      B      C     D         AB    BA    CD    DC    AC    CA    BD    DB    AD    DA    CB    BC"<<endl;
  int i = 1;
  for (edwIonCalibDataMapIterator it=fIonCalibDataMap.begin(); it!=fIonCalibDataMap.end(); ++it) {
    flux << i++ << " " <<  (*it).first << endl;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      flux << (*(*it).second[i]) << endl;
    }
    flux << "-1  -1. -1. -1. -1.  -1. -1. -1. -1.  -1. -1. -1. -1.  -1. -1. -1. -1."<<endl;
  }

}

void edwCalibrationManager::printHeatCalibData(ostream& flux) {

  flux << "C   -----Runs----    06.12.2016"<<endl;
  flux << "C B  Debut    Fin Mac  n /N"<<endl;
  flux << "C         --V-- -GainA-GainB- -Temps - -- Chi2 A - Chi2 B -"<<endl;
  int i = 1;
  for (edwHeatCalibDataMapIterator it=fHeatCalibDataMap.begin(); it!=fHeatCalibDataMap.end(); ++it) {
    flux << i++ << " " << (*it).first << endl;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      flux << (*(*it).second[i]) << endl;
    }
    flux << "-1 0. 0. 0. 0. 0. 0. 0. 0." << endl;
  }

}

void edwCalibrationManager::printParamCalibData(ostream& flux) {

  flux << "C   -----Runs----"<<endl;
  flux << "C Bolo"<<endl;
  flux << "C"<<endl;
  int i = 1;
  for (edwParamCalibDataMapIterator it=fParamCalibDataMap.begin(); it!=fParamCalibDataMap.end(); ++it) {
    flux << i++ << " " << (*it).first << endl;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      flux << (*(*it).second[i]) << endl;
    }
    flux << "-1 0. 0. 0. 0. 0. 0. 0. 0." << endl;
  }

}

void edwCalibrationManager::printStrucCalibData(ostream& flux) {

  flux << "C   -----Runs----"<<endl;
  flux << "C Bolo 1 2 3"<<endl;
  flux << "C  --Run--Mac---i-/-n-voie-bit-ch1-ch2-type-nom"<<endl;
  int i = 1;
  for (edwStrucCalibDataMapIterator it=fStrucCalibDataMap.begin(); it!=fStrucCalibDataMap.end(); ++it) {
    flux << i++ << endl;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      flux << (*(*it).second[i]) << endl;
    }
    flux << "-1 0. 0. 0. 0. 0. 0. 0. 0." << endl;
  }

}

void edwCalibrationManager::print() {

  cout << "== edwCalibrationManager ==" << endl;
  printIonCalibData(cout);
  cout << "---------------------------" << endl;
  printHeatCalibData(cout);
  cout << "---------------------------" << endl;
  printParamCalibData(cout);
  cout << "---------------------------" << endl;
  printStrucCalibData(cout);


}


void edwCalibrationManager::calibrateAll() {

  /* This was only used in few runs, at 18 mK */
  // Reference temperature for a given CryoRun

  int runNumber = fNepalTreeManager->getAnaRunNumber();
  int nbOfEvent = fNepalTreeManager->GetEntries();
  vector<string> processingMethodes = fNepalTreeManager->getProcessingMethodes();

   // cout << "Calibrate run " << runNumber << " and from file " << fNepalTreeManager->getAnaRunNumber() << " nEntries " << nbOfEvent << " Bolo "<<fNepalTreeManager->getBoloID() << endl;


  for(int i=0; i<nbOfEvent;i++) {
    fNepalTreeManager->GetEntry(i);

    if(i%100==0) cout << "Calibrate Event " << i << "\r" << flush;

    int boloID = fNepalTreeManager->getBoloID();
    edwIonCalibData* ionCalibData =  getIonCalibData(runNumber,boloID);
    edwHeatCalibData* heatCalibData =  getHeatCalibData(runNumber,boloID);
    edwParamCalibData* paramCalibData =  getParamCalibData(runNumber,boloID);
    edwStrucCalibData* strucCalibData =  getStrucCalibData(runNumber,boloID);
    fEverestTreeManager->resetBolometer();
    edwBolometer* aBolo = fEverestTreeManager->GetBolo();

    
    aBolo->setBoloName(fNepalTreeManager->getBoloName());
    aBolo->setAnaRunNumber(runNumber);
    aBolo->setIonCalibDataIndex(ionCalibData->getIndex());
    aBolo->setHeatCalibDataIndex(heatCalibData->getIndex());
    aBolo->setParamCalibDataIndex(paramCalibData->getIndex());
    aBolo->setStrucCalibDataIndex(strucCalibData->getIndex());
    aBolo->setTimeFirstDay(fNepalTreeManager->getTimeSinceCryorunStart());
    aBolo->setBoloNb(fNepalTreeManager->getBoloID());
    aBolo->setPartitionNb(fNepalTreeManager->getPartitionNb());
    aBolo->setEventNb(fNepalTreeManager->getEventNb());
    aBolo->setNormalizedStep(fNepalTreeManager->getNormalizedStep());

    Double_t thA = fNepalTreeManager->getHeatThresholdA();
    Double_t thAuncorr = linearHeatCalibration("A",thA,heatCalibData,paramCalibData);
    Double_t thAcorrected = nonLinearityCorrection("A",thAuncorr,heatCalibData,paramCalibData);
    aBolo->setHeatThresholdA(thAcorrected);

    Double_t thB = fNepalTreeManager->getHeatThresholdB();
    Double_t thBuncorr = linearHeatCalibration("B",thB,heatCalibData,paramCalibData);
    Double_t thBcorrected = nonLinearityCorrection("B",thBuncorr,heatCalibData,paramCalibData);
    aBolo->setHeatThresholdB(thBcorrected);

    edwEnergies* anEnergies = NULL;
    edwAmplitudes* anAmplitudes = NULL;
    for(int j = 0; j< processingMethodes.size() ; j++) {
      if(fNepalTreeManager->isEntryOK(processingMethodes[j])) {
	anEnergies = getEnergiesForOption(processingMethodes[j],ionCalibData,heatCalibData,paramCalibData,strucCalibData->getPolarisationMode());
	aBolo->addEnergies(anEnergies);
	anAmplitudes = getAmplitudesForOption(processingMethodes[j]);
	aBolo->addAmplitudes(anAmplitudes);
	//if(processingMethodes[j] == "noise_Normal_filt_decor" && i == 631)std::cout<< "Event "<<i<< " "<< processingMethodes[j] <<" Ephonon "<<aBolo->getEnergies(processingMethodes[j])->getEh()*(1.+fabs(heatCalibData->getVoltage())/3.)<<" volt "<<heatCalibData->getVoltage()<< " Amplitude "<<anAmplitudes->getHeatA()<<std::endl;
	
      }
    }

    
    fEverestTreeManager->FillEvent();
  }
  cout << "done " << endl;

  fEverestTreeManager->Write();


}


edwEnergies* edwCalibrationManager::getEnergiesForOption(string option, edwIonCalibData* ionCalibData, edwHeatCalibData* heatCalibData, edwParamCalibData* paramCalibData, int polMode) {

  Double_t adu = fNepalTreeManager->getHeatADU("A",option);
  Double_t heatAuncorr = linearHeatCalibration("A",adu,heatCalibData,paramCalibData);
  Double_t correctedHeatA = nonLinearityCorrection("A",heatAuncorr,heatCalibData,paramCalibData);

  adu = fNepalTreeManager->getHeatADU("B",option);
  Double_t heatBuncorr = linearHeatCalibration("B",adu,heatCalibData,paramCalibData);
  Double_t correctedHeatB = nonLinearityCorrection("B",heatBuncorr,heatCalibData,paramCalibData);

  Double_t fastIonA = ionADU2keVee("A","fast",option,ionCalibData);
  Double_t fastIonB = ionADU2keVee("B","fast",option,ionCalibData);
  Double_t fastIonC = ionADU2keVee("C","fast",option,ionCalibData);
  Double_t fastIonD = ionADU2keVee("D","fast",option,ionCalibData);

  Double_t ionA = ionADU2keVee("A","slow",option,ionCalibData);
  Double_t ionB = ionADU2keVee("B","slow",option,ionCalibData);
  Double_t ionC = ionADU2keVee("C","slow",option,ionCalibData);
  Double_t ionD = ionADU2keVee("D","slow",option,ionCalibData);

  edwEnergies* anEnergies = new edwEnergies(option,
					    heatAuncorr,heatBuncorr,correctedHeatA,correctedHeatB,
					    ionA,ionB,ionC,ionD,
					    fastIonA,fastIonB,fastIonC,fastIonD);

  adu = fNepalTreeManager->getHeatResolution("A",option);
  Double_t heatResoA = linearHeatCalibration("A",adu,heatCalibData,paramCalibData);
  anEnergies->setFWhA(nonLinearityCorrection("A",heatResoA,heatCalibData,paramCalibData));
  adu = fNepalTreeManager->getHeatResolution("B",option);
  Double_t heatResoB = linearHeatCalibration("B",adu,heatCalibData,paramCalibData);
  anEnergies->setFWhB(nonLinearityCorrection("B",heatResoB,heatCalibData,paramCalibData));

  anEnergies->setFWfastIA(fNepalTreeManager->getIonResolution("A","fast",option)*fabs(ionCalibData->getGain("A")));
  anEnergies->setFWfastIB(fNepalTreeManager->getIonResolution("B","fast",option)*fabs(ionCalibData->getGain("B")));
  anEnergies->setFWfastIC(fNepalTreeManager->getIonResolution("C","fast",option)*fabs(ionCalibData->getGain("C")));
  anEnergies->setFWfastID(fNepalTreeManager->getIonResolution("D","fast",option)*fabs(ionCalibData->getGain("D")));

  anEnergies->setFWiA(fNepalTreeManager->getIonResolution("A","slow",option)*fabs(ionCalibData->getGain("A")));
  anEnergies->setFWiB(fNepalTreeManager->getIonResolution("B","slow",option)*fabs(ionCalibData->getGain("B")));
  anEnergies->setFWiC(fNepalTreeManager->getIonResolution("C","slow",option)*fabs(ionCalibData->getGain("C")));
  anEnergies->setFWiD(fNepalTreeManager->getIonResolution("D","slow",option)*fabs(ionCalibData->getGain("D")));

  anEnergies->computePhysicalVariables(ionCalibData,heatCalibData,paramCalibData,polMode);

  return anEnergies;

}

edwAmplitudes* edwCalibrationManager::getAmplitudesForOption(string option){

  edwAmplitudes* anAmplitudes = new edwAmplitudes(option);

  anAmplitudes->setIsDecorrelated(fNepalTreeManager->getIsDecor(option));

  anAmplitudes->setHeatA(fNepalTreeManager->getHeatADU("A",option));
  anAmplitudes->setHeatB(fNepalTreeManager->getHeatADU("B",option));

  anAmplitudes->setIonA(fNepalTreeManager->getIonADU("A","slow",option));
  anAmplitudes->setIonB(fNepalTreeManager->getIonADU("B","slow",option));
  anAmplitudes->setIonC(fNepalTreeManager->getIonADU("C","slow",option));
  anAmplitudes->setIonD(fNepalTreeManager->getIonADU("D","slow",option));

  anAmplitudes->setFastIonA(fNepalTreeManager->getIonADU("A","fast",option));
  anAmplitudes->setFastIonB(fNepalTreeManager->getIonADU("B","fast",option));
  anAmplitudes->setFastIonC(fNepalTreeManager->getIonADU("C","fast",option));
  anAmplitudes->setFastIonD(fNepalTreeManager->getIonADU("D","fast",option));

  anAmplitudes->setHeatChi2A(fNepalTreeManager->getHeatChi2("A",option));
  anAmplitudes->setHeatChi2B(fNepalTreeManager->getHeatChi2("B",option));

  anAmplitudes->setIonChi2A(fNepalTreeManager->getIonChi2("A","slow",option));
  anAmplitudes->setIonChi2B(fNepalTreeManager->getIonChi2("B","slow",option));
  anAmplitudes->setIonChi2C(fNepalTreeManager->getIonChi2("C","slow",option));
  anAmplitudes->setIonChi2D(fNepalTreeManager->getIonChi2("D","slow",option));

  anAmplitudes->setFastIonChi2A(fNepalTreeManager->getIonChi2("A","fast",option));
  anAmplitudes->setFastIonChi2B(fNepalTreeManager->getIonChi2("B","fast",option));
  anAmplitudes->setFastIonChi2C(fNepalTreeManager->getIonChi2("C","fast",option));
  anAmplitudes->setFastIonChi2D(fNepalTreeManager->getIonChi2("D","fast",option));

  anAmplitudes->setHeatResoA(fNepalTreeManager->getHeatResolution("A",option));
  anAmplitudes->setHeatResoB(fNepalTreeManager->getHeatResolution("B",option));

  anAmplitudes->setIonResoA(fNepalTreeManager->getIonResolution("A","slow",option));
  anAmplitudes->setIonResoB(fNepalTreeManager->getIonResolution("B","slow",option));
  anAmplitudes->setIonResoC(fNepalTreeManager->getIonResolution("C","slow",option));
  anAmplitudes->setIonResoD(fNepalTreeManager->getIonResolution("D","slow",option));

  anAmplitudes->setFastIonResoA(fNepalTreeManager->getIonResolution("A","fast",option));
  anAmplitudes->setFastIonResoB(fNepalTreeManager->getIonResolution("B","fast",option));
  anAmplitudes->setFastIonResoC(fNepalTreeManager->getIonResolution("C","fast",option));
  anAmplitudes->setFastIonResoD(fNepalTreeManager->getIonResolution("D","fast",option));


  return anAmplitudes;

}


// HEAT CALIBRATION

double edwCalibrationManager::linearHeatCalibration(string ch, double adu,  edwHeatCalibData* heatCalibData,edwParamCalibData* paramCalibData ) {

  double tbol = fNepalTreeManager->getSambaBoloTemperature();
  double tregul = 0.018;

  double timeFirstDay =   fNepalTreeManager->getTimeSinceCryorunStart() - fNepalTreeManager->getTimeSinceLastEvent()/(3600*24);
  double timeSinceBegining = ( fNepalTreeManager->getTimeSinceCryorunStart() - timeFirstDay ) *86400.;

  double heat = heatCalibData->getGain(ch) * adu;
  heat *= 1 + heatCalibData->getHeatTimeDependence() * timeSinceBegining  / 3600. ;
  //  cout << ch << " : heat " << heat << " slope " << heatCalibData->getHeatTimeDependence() <<endl;
  if ( (tbol > 0.010) &&
       (tbol < 0.030) ) {
     if ( ( paramCalibData->getHeatCorr(ch) < 0 ) || ( paramCalibData->getHeatCorr(ch) > 10 ) ) {
      heat /= 1 + paramCalibData->getHeatCorr(ch)*(tbol - tregul);
    }
  }


  return heat;

}


double edwCalibrationManager::nonLinearityCorrection(string ch, double linearHeat, edwHeatCalibData* heatCalibData,edwParamCalibData* paramCalibData ) {

    // question
    // tregul
    // ivers
    double ivers = 309;
    double rlog, arg, tmp, gcor;

    double correctedHeat = 0.;

    // 2019-12-04 JG remplaced getFiducialVoltage by getVoltage
    if ( linearHeat!= 0.0 ) {
      if ( (linearHeat > 0.0) &&
	   (paramCalibData->getNonLinearity(ch,1) != 0.0) ) {
	rlog = log( linearHeat * (3.+abs(heatCalibData->getVoltage()))/11. );
	arg  = ( paramCalibData->getNonLinearity(ch,2) -rlog ) / paramCalibData->getNonLinearity(ch,3);
	tmp  = paramCalibData->getNonLinearity(ch,1) * ( rlog - paramCalibData->getNonLinearity(ch,2) );
 	if ( ivers > 308 ) {
 	  tmp *= 1. - paramCalibData->getNonLinearity(ch,4)*(rlog - paramCalibData->getNonLinearity(ch,2));
 	}
	gcor = paramCalibData->getNonLinearity(ch,0) + tmp / ( 1. + exp(arg) ) ;
	correctedHeat = linearHeat/ gcor;
	
      } else {
	correctedHeat = linearHeat/paramCalibData->getNonLinearityA(0);
      }
    }

    return correctedHeat;
}



// ION CALIBRATION

double edwCalibrationManager::ionADU2keVee(string ch, string shaper, string option, edwIonCalibData* ionCalibData) {
  double correctedADU = fNepalTreeManager->getIonADU("A",shaper,option) * ionCalibData->getCrossTalkXandA(ch)
    + fNepalTreeManager->getIonADU("B",shaper,option) * ionCalibData->getCrossTalkXandB(ch)
    + fNepalTreeManager->getIonADU("C",shaper,option) * ionCalibData->getCrossTalkXandC(ch)
    + fNepalTreeManager->getIonADU("D",shaper,option) * ionCalibData->getCrossTalkXandD(ch);
  correctedADU *= -1.;
  return ionCalibData->getGain(ch)*correctedADU;
}

