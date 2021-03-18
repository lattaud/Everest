#ifndef edwRData_h
#define edwRData_h

#include "TString.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class edwIonCalibData {

 public:

  edwIonCalibData()    {
    fAnaRunNumber = 0;
    fIndex = 0;
    fGainA = 0.;
    fGainB = 0.;
    fGainC = 0.;
    fGainD = 0.;
    fCrossTalkAB = 0.;
    fCrossTalkAC = 0.;
    fCrossTalkAD = 0.;
    fCrossTalkBA = 0.;
    fCrossTalkBC = 0.;
    fCrossTalkBD = 0.;
    fCrossTalkCA = 0.;
    fCrossTalkCB = 0.;
    fCrossTalkCD = 0.;
    fCrossTalkDA = 0.;
    fCrossTalkDB = 0.;
    fCrossTalkDC = 0.;
  }
  edwIonCalibData(int n)   {
    fAnaRunNumber = n;
    fIndex = 0;
    fGainA = 0.;
    fGainB = 0.;
    fGainC = 0.;
    fGainD = 0.;
    fCrossTalkAB = 0.;
    fCrossTalkAC = 0.;
    fCrossTalkAD = 0.;
    fCrossTalkBA = 0.;
    fCrossTalkBC = 0.;
    fCrossTalkBD = 0.;
    fCrossTalkCA = 0.;
    fCrossTalkCB = 0.;
    fCrossTalkCD = 0.;
    fCrossTalkDA = 0.;
    fCrossTalkDB = 0.;
    fCrossTalkDC = 0.;
  }
  ~edwIonCalibData() {}
  
  int getAnaRunNumber(){ return fAnaRunNumber; }
  int getIndex() { return fIndex; }
  double getGainA() {return fGainA; }
  double getGainB() {return fGainB; }
  double getGainC() {return fGainC; }
  double getGainD() {return fGainD; }
  double getGain(TString ch);

  double getCrossTalkAB() {return fCrossTalkAB; }
  double getCrossTalkAC() {return fCrossTalkAC; }
  double getCrossTalkAD() {return fCrossTalkAD; }
  double getCrossTalkBA() {return fCrossTalkBA; }
  double getCrossTalkBC() {return fCrossTalkBC; }
  double getCrossTalkBD() {return fCrossTalkBD; }
  double getCrossTalkCA() {return fCrossTalkCA; }
  double getCrossTalkCB() {return fCrossTalkCB; }
  double getCrossTalkCD() {return fCrossTalkCD; }
  double getCrossTalkDA() {return fCrossTalkDA; }
  double getCrossTalkDB() {return fCrossTalkDB; }
  double getCrossTalkDC() {return fCrossTalkDC; }
  double getCrossTalkXandA(TString X);
  double getCrossTalkXandB(TString X);
  double getCrossTalkXandC(TString X);
  double getCrossTalkXandD(TString X);
  
  void setAnaRunNumber(int value)       { fAnaRunNumber = value;   } 
  void setIndex(int value)              { fIndex = value; }
  void setGainA(double g) { fGainA = g; }
  void setGainB(double g) { fGainB = g; }
  void setGainC(double g) { fGainC = g; }
  void setGainD(double g) { fGainD = g; }
  
  void setCrossTalkAB(double xt) { fCrossTalkAB = xt; }
  void setCrossTalkAC(double xt) { fCrossTalkAC = xt; }
  void setCrossTalkAD(double xt) { fCrossTalkAD = xt; }
  void setCrossTalkBA(double xt) { fCrossTalkBA = xt; }
  void setCrossTalkBC(double xt) { fCrossTalkBC = xt; }
  void setCrossTalkBD(double xt) { fCrossTalkBD = xt; }
  void setCrossTalkCA(double xt) { fCrossTalkCA = xt; }
  void setCrossTalkCB(double xt) { fCrossTalkCB = xt; }
  void setCrossTalkCD(double xt) { fCrossTalkCD = xt; }
  void setCrossTalkDA(double xt) { fCrossTalkDA = xt; }
  void setCrossTalkDB(double xt) { fCrossTalkDB = xt; }
  void setCrossTalkDC(double xt) { fCrossTalkDC = xt; }
  

  friend ostream& operator<<(ostream& flux, const edwIonCalibData& aICD);


 private:

  int fAnaRunNumber;
  int fIndex;
  double fGainA;
  double fGainB;
  double fGainC;
  double fGainD;
  
  double fCrossTalkAB;
  double fCrossTalkAC;
  double fCrossTalkAD;
  double fCrossTalkBA;
  double fCrossTalkBC;
  double fCrossTalkBD;
  double fCrossTalkCA;
  double fCrossTalkCB;
  double fCrossTalkCD;
  double fCrossTalkDA;
  double fCrossTalkDB;
  double fCrossTalkDC;
  
};

class edwHeatCalibData  {
  
 public : 

  edwHeatCalibData() {
    fAnaRunNumber = 0;
    fIndex = 0;
    fVoltage = 0.;
    fGainA = 0.;
    fGainB = 0.;
    fHeatTimeDependence = 0;
  }
  edwHeatCalibData(int n, double v,double gA,double gB, double t) {
    fAnaRunNumber = n;
    fIndex = 0;
    fVoltage = v;
    fGainA = gA;
    fGainB = gB;
    fHeatTimeDependence = t;
  }
  ~edwHeatCalibData() {}

  int getAnaRunNumber(){ return fAnaRunNumber; }
  int getIndex() { return fIndex; }
  double getVoltage() { return fVoltage; }
  double getGainA()   { return fGainA;   }
  double getGainB()   { return fGainB;   }
  double getGain(TString ch);
  double getHeatTimeDependence() { return fHeatTimeDependence; }

  void setAnaRunNumber(int value)       { fAnaRunNumber = value;   } 
  void setIndex(int value)              { fIndex = value; }
  void setVoltage(double v) { fVoltage = v; }
  void setGainA(double g)   { fGainA   = g; }
  void setGainB(double g)   { fGainB   = g; }
  void setHeatTimeDependence(double t) { fHeatTimeDependence = t;}
  
  friend ostream& operator<<(ostream& flux, const edwHeatCalibData& aHCD);

 private:
  int fAnaRunNumber;
  int fIndex;
  double fVoltage;
  double fGainA;
  double fGainB;
  double fHeatTimeDependence;
 
};


class edwParamCalibData {

 public:

  edwParamCalibData() {
    fAnaRunNumber = 0;
    fIndex = 0;
    fFiducialVoltage=0.;
    fVetoVoltage=0.;
    fIoniXtalkCutA=0.;
    fIoniXtalkCutB=0.;
    fIoniXtalkCutC=0.;
    fIoniXtalkCutD=0.;
    fHeatCorrA=0.;
    fHeatCorrB=0.;
    for(int i=0;i<5;i++)fNonLinearityA[i]=0.;
    fThresholdCorrA=0.;
    fThresholdCorrB=0.;
    for(int i=0;i<5;i++)fNonLinearityB[i]=0.;
    fHeatAweight=0.;
    fIonBweight=0.;
  }
  edwParamCalibData(int n) {
    fAnaRunNumber = n;
    fIndex = 0;
    fFiducialVoltage=0.;
    fVetoVoltage=0.;
    fIoniXtalkCutA=0.;
    fIoniXtalkCutB=0.;
    fIoniXtalkCutC=0.;
    fIoniXtalkCutD=0.;
    fHeatCorrA=0.;
    fHeatCorrB=0.;
    for(int i=0;i<5;i++)fNonLinearityA[i]=0.;
    fThresholdCorrA=0.;
    fThresholdCorrB=0.;
    for(int i=0;i<5;i++)fNonLinearityB[i]=0.;
    fHeatAweight=0.;
    fIonBweight=0.;
  }
  ~edwParamCalibData() {}

  int getAnaRunNumber(){ return fAnaRunNumber; }
  int getIndex() { return fIndex; }
  double getFiducialVoltage() {return fFiducialVoltage;}
  double getVetoVoltage() {return fVetoVoltage;}
  double getIoniXtalkCutA() {return fIoniXtalkCutA;}
  double getIoniXtalkCutB() {return fIoniXtalkCutB;}
  double getIoniXtalkCutC() {return fIoniXtalkCutC;}
  double getIoniXtalkCutD() {return fIoniXtalkCutD;}
  double getIoniXtalkCut(TString ch);
  double getHeatCorrA() {return fHeatCorrA;}
  double getHeatCorrB() {return fHeatCorrB;}
  double getHeatCorr(TString ch);
  double getThresholdCorrA() {return fThresholdCorrA;}
  double getThresholdCorrB() {return fThresholdCorrB;}
  double getNonLinearityA(int i) {return fNonLinearityA[i];}
  double getNonLinearityB(int i) {return fNonLinearityB[i];}
  double getHeatAweight() {return fHeatAweight;}
  double getIonBweight() {return fIonBweight;}
  double getNonLinearity(TString ch, int i);

  void setAnaRunNumber(int value)       { fAnaRunNumber = value;   } 
  void setIndex(int value)              { fIndex = value; }
  void setFiducialVoltage(double value) { fFiducialVoltage = value;}
  void setVetoVoltage(double value) { fVetoVoltage = value;}
  void setIoniXtalkCutA(double value) { fIoniXtalkCutA = value;}
  void setIoniXtalkCutB(double value) { fIoniXtalkCutB = value;}
  void setIoniXtalkCutC(double value) { fIoniXtalkCutC = value;}
  void setIoniXtalkCutD(double value) { fIoniXtalkCutD = value;}
  void setHeatCorrA(double value) { fHeatCorrA = value;}
  void setHeatCorrB(double value) { fHeatCorrB = value;}
  void setThresholdCorrA(double value) {fThresholdCorrA = value;}
  void setThresholdCorrB(double value) {fThresholdCorrB = value;}
  void setNonLinearityA(int i, double value) { fNonLinearityA[i] = value;}
  void setNonLinearityB(int i, double value) { fNonLinearityB[i] = value;}
  void setHeatAweight(double value) { fHeatAweight = value;}
  void setIonBweight(double value) { fIonBweight = value;}


  friend ostream& operator<<(ostream& flux, const edwParamCalibData& aPCD);

 private:

  int fAnaRunNumber;
  int fIndex;
  double fFiducialVoltage;
  double fVetoVoltage;
  
  double fIoniXtalkCutA;
  double fIoniXtalkCutB;
  double fIoniXtalkCutC;
  double fIoniXtalkCutD;

  double fHeatCorrA;
  double fHeatCorrB;
  double fThresholdCorrA;
  double fThresholdCorrB;
  double fNonLinearityA[5];
  double fNonLinearityB[5];
  double fHeatAweight;
  double fIonBweight;


};

class edwStrucCalibData {

 public:

  edwStrucCalibData()  {
    fAnaRunNumber = 0;
    fIndex = 0;
    fBoloIndexInSamba = -1;
    fHeatAbitNumber = 0;
    fHeatBbitNumber = 0;
    fPolarisationMode = 0;
  }
  edwStrucCalibData(int n)   {
    fAnaRunNumber = n;
    fIndex = 0;
    fBoloIndexInSamba = -1;
    fHeatAbitNumber = 0;
    fHeatBbitNumber = 0;
    fPolarisationMode = 0;
  }
  ~edwStrucCalibData() {}

  int getAnaRunNumber()    { return fAnaRunNumber;    }
  int getIndex() { return fIndex; }
  int getBoloIndexInSamba(){ return fBoloIndexInSamba;}
  int getHeatAbitNumber()  { return fHeatAbitNumber;  }
  int getHeatBbitNumber()  { return fHeatBbitNumber;  }
  int getPolarisationMode(){ return fPolarisationMode;}

  void setAnaRunNumber(int value)     { fAnaRunNumber = value;    } 
  void setIndex(int value)              { fIndex = value; }
  void setBoloIndexInSamba(int value) { fBoloIndexInSamba = value;} 
  void setHeatAbitNumber(int value)   { fHeatAbitNumber = value;  } 
  void setHeatBbitNumber(int value)   { fHeatBbitNumber = value;  } 
  void setPolarisationMode(int value) { fPolarisationMode = value;} 

  friend ostream& operator<<(ostream& flux, const edwStrucCalibData& aSCD);

 private:

  int fAnaRunNumber;
  int fIndex;
  int fBoloIndexInSamba;
  int fHeatAbitNumber;
  int fHeatBbitNumber;
  int fPolarisationMode;


};


typedef std::vector<edwIonCalibData*> edwIonCalibDataVector;
typedef std::vector<edwHeatCalibData*> edwHeatCalibDataVector;
typedef std::vector<edwParamCalibData*> edwParamCalibDataVector;
typedef std::vector<edwStrucCalibData*> edwStrucCalibDataVector;

typedef std::map<int,edwIonCalibDataVector> edwIonCalibDataMap;
typedef std::map<int,edwIonCalibDataVector>::iterator edwIonCalibDataMapIterator;
typedef std::map<int,edwHeatCalibDataVector> edwHeatCalibDataMap;
typedef std::map<int,edwHeatCalibDataVector>::iterator edwHeatCalibDataMapIterator;
typedef std::map<int,edwParamCalibDataVector> edwParamCalibDataMap;
typedef std::map<int,edwParamCalibDataVector>::iterator edwParamCalibDataMapIterator;
typedef std::map<int,edwStrucCalibDataVector> edwStrucCalibDataMap;
typedef std::map<int,edwStrucCalibDataVector>::iterator edwStrucCalibDataMapIterator;



class edwHeatChi2Cut  {
  
 public : 

  edwHeatChi2Cut() {
    fStartAnaRunNumber = 0;
    fEndAnaRunNumber = 1999999;
    fIndex = 0;
    fDi1 = 0.;
    fDi2 = 0.;
    fBA = 0.; 
    fBB = 0.; 
    fPA = 0.; 
    fPB = 0.; 
    fXA = 0.; 
    fXB = 0.; 
    fX1 = 0.;
    fX2 = 0.;
  }
  edwHeatChi2Cut(int n1, int n2, double di1,double di2,double bA, double bB,double pA, double pB,double xA, double xB, double x1, double x2) {
    fStartAnaRunNumber = n1;
    fEndAnaRunNumber = n2;
    fIndex = 0;
    fDi1 = di1;
    fDi2 = di2;
    fBA = bA; 
    fBB = bB; 
    fPA = pA; 
    fPB = pB; 
    fXA = xA; 
    fXB = xB; 
    fX1 = x1;
    fX2 = x2;
  }
  ~edwHeatChi2Cut() {}

  bool compareRunNumber(int runNumber) {
    return (runNumber>=fStartAnaRunNumber && runNumber <= fEndAnaRunNumber);
  }
  int getIndex() { return fIndex; }
  void setIndex(int value)              { fIndex = value; }
  bool isChi2OK(double chi2, double E, string ch);


  friend ostream& operator<<(ostream& flux, const edwHeatChi2Cut& aHX2C);

 private:
  int fStartAnaRunNumber;
  int fEndAnaRunNumber;
  int fIndex;
  double fDi1;
  double fDi2;
  double fBA; 
  double fBB; 
  double fPA; 
  double fPB; 
  double fXA; 
  double fXB; 
  double fX1; 
  double fX2; 

 
};


class edwIonChi2Cut  {
  
 public : 

  edwIonChi2Cut() {
    fStartAnaRunNumber = 0;
    fEndAnaRunNumber = 1999999;
    fIndex = 0;
    fBA = 0.;
    fBB = 0.;
    fBC = 0.;
    fBD = 0.;
    fPA = 0.;
    fPB = 0.;
    fPC = 0.;
    fPD = 0.;
  }
  edwIonChi2Cut(int n1, int n2, double bA, double pA, double bB, double pB, double bC, double pC, double bD, double pD) {
    fStartAnaRunNumber = n1;
    fEndAnaRunNumber = n2;
    fIndex = 0;
    fBA = bA;
    fBB = bB;
    fBC = bC;
    fBD = bD;
    fPA = pA;
    fPB = pB;
    fPC = pC;
    fPD = pD;
  }
  ~edwIonChi2Cut() {}

  int getIndex() { return fIndex; }
  void setIndex(int value)              { fIndex = value; }
  inline bool compareRunNumber(int runNumber) {
    return (runNumber>=fStartAnaRunNumber && runNumber <= fEndAnaRunNumber);
  }
  bool isChi2OK(double chi2, double E,string ch);

  friend ostream& operator<<(ostream& flux, const edwIonChi2Cut& aIX2C);

 private:
  int fStartAnaRunNumber;
  int fEndAnaRunNumber;
  int fIndex;
  double fBA; 
  double fBB; 
  double fBC; 
  double fBD; 
  double fPA; 
  double fPB; 
  double fPC; 
  double fPD; 
 
};

class edwElectrodCut  {
  
 public : 

  edwElectrodCut() {
    fStartAnaRunNumber = 0;
    fEndAnaRunNumber = 1999999;
    fIndex = 0;
    fZA = 0.;
    fZB = 0.;
    fZC = 0.;
    fZD = 0.;
    fPA = 0.;
    fPB = 0.;
    fPC = 0.;
    fPD = 0.;
    fQslot = 0.;
  }
  edwElectrodCut(int n1, int n2, double zA, double pA, double zB, double pB, double zC, double pC, double zD, double pD, double qs) {
    fStartAnaRunNumber = n1;
    fEndAnaRunNumber = n2;
    fIndex = 0;
    fZA = zA;
    fZB = zB;
    fZC = zC;
    fZD = zD;
    fPA = pA;
    fPB = pB;
    fPC = pC;
    fPD = pD;
    fQslot = qs;
  }
  ~edwElectrodCut() {}

  bool compareRunNumber(int runNumber) {
    return (runNumber>=fStartAnaRunNumber && runNumber <= fEndAnaRunNumber);
  }
  int getIndex() { return fIndex; }
  void setIndex(int value)              { fIndex = value; }

  friend ostream& operator<<(ostream& flux, const edwElectrodCut& aEC);

 private:
  int fStartAnaRunNumber;
  int fEndAnaRunNumber;
  int fIndex;
  double fZA; 
  double fZB; 
  double fZC; 
  double fZD; 
  double fPA; 
  double fPB; 
  double fPC; 
  double fPD; 
  double fQslot;
 
};


typedef std::vector<edwHeatChi2Cut*> edwHeatChi2CutVector;
typedef std::vector<edwIonChi2Cut*> edwIonChi2CutVector;
typedef std::vector<edwElectrodCut*> edwElectrodCutVector;

typedef std::map<int,edwHeatChi2CutVector> edwHeatChi2CutMap;
typedef std::map<int,edwHeatChi2CutVector>::iterator edwHeatChi2CutMapIterator;
typedef std::map<int,edwIonChi2CutVector> edwIonChi2CutMap;
typedef std::map<int,edwIonChi2CutVector>::iterator edwIonChi2CutMapIterator;
typedef std::map<int,edwElectrodCutVector> edwElectrodCutMap;
typedef std::map<int,edwElectrodCutVector>::iterator edwElectrodCutMapIterator;



class edwAmplitudes {

 public:

  edwAmplitudes();
  edwAmplitudes(TString name);
  edwAmplitudes(TString name, Double_t ha, Double_t hb, 
		Double_t ia, Double_t ib, Double_t ic, Double_t id,
		Double_t fia, Double_t fib, Double_t fic, Double_t fid);
  edwAmplitudes(TString name, Double_t* array);
  ~edwAmplitudes() {}

  void setAmplitudesOption(TString s) { amplitudesOption = s; }
  void setHeatA(double value)       { heatA = value;       }   
  void setHeatB(double value)       { heatB = value;       }   
  void setIonA(double value)        { ionA = value;        }    
  void setIonB(double value)        { ionB = value;        }    
  void setIonC(double value)        { ionC = value;        }    
  void setIonD(double value)        { ionD = value;        }    
  void setFastIonA(double value)    { fastIonA = value;    }
  void setFastIonB(double value)    { fastIonB = value;    }
  void setFastIonC(double value)    { fastIonC = value;    }
  void setFastIonD(double value)    { fastIonD = value;    }
  void setHeatChi2A(double value)   { heatChi2A = value;   }   
  void setHeatChi2B(double value)   { heatChi2B = value;   }   
  void setIonChi2A(double value)    { ionChi2A = value;    }    
  void setIonChi2B(double value)    { ionChi2B = value;    }    
  void setIonChi2C(double value)    { ionChi2C = value;    }    
  void setIonChi2D(double value)    { ionChi2D = value;    }    
  void setFastIonChi2A(double value){ fastIonChi2A = value;}
  void setFastIonChi2B(double value){ fastIonChi2B = value;}
  void setFastIonChi2C(double value){ fastIonChi2C = value;}
  void setFastIonChi2D(double value){ fastIonChi2D = value;}
  void setHeatResoA(double value)   { heatResoA = value;   }   
  void setHeatResoB(double value)   { heatResoB = value;   }   
  void setIonResoA(double value)    { ionResoA = value;    }    
  void setIonResoB(double value)    { ionResoB = value;    }    
  void setIonResoC(double value)    { ionResoC = value;    }    
  void setIonResoD(double value)    { ionResoD = value;    }    
  void setFastIonResoA(double value){ fastIonAReso = value;}
  void setFastIonResoB(double value){ fastIonBReso = value;}
  void setFastIonResoC(double value){ fastIonCReso = value;}
  void setFastIonResoD(double value){ fastIonDReso = value;}
  void setIsDecorrelated(bool value){ isDecorr = value;    }

  TString  getAmplitudesOption(){ return amplitudesOption;}
  Double_t getHeatA()         { return heatA;         }   
  Double_t getHeatB()         { return heatB;         }   
  Double_t getIonA()          { return ionA;          }    
  Double_t getIonB()          { return ionB;          }    
  Double_t getIonC()          { return ionC;          }    
  Double_t getIonD()          { return ionD;          }    
  Double_t getFastIonA()      { return fastIonA;      }
  Double_t getFastIonB()      { return fastIonB;      }
  Double_t getFastIonC()      { return fastIonC;      }
  Double_t getFastIonD()      { return fastIonD;      }
  Double_t getHeatChi2A()     { return heatChi2A;     }   
  Double_t getHeatChi2B()     { return heatChi2B;     }   
  Double_t getIonChi2A()      { return ionChi2A;      }    
  Double_t getIonChi2B()      { return ionChi2B;      }    
  Double_t getIonChi2C()      { return ionChi2C;      }    
  Double_t getIonChi2D()      { return ionChi2D;      }    
  Double_t getFastIonChi2A()  { return fastIonChi2A;  }
  Double_t getFastIonChi2B()  { return fastIonChi2B;  }
  Double_t getFastIonChi2C()  { return fastIonChi2C;  }
  Double_t getFastIonChi2D()  { return fastIonChi2D;  }
  Double_t getHeatResoA()     { return heatResoA;     }   
  Double_t getHeatResoB()     { return heatResoB;     }   
  Double_t getIonResoA()      { return ionResoA;      }    
  Double_t getIonResoB()      { return ionResoB;      }    
  Double_t getIonResoC()      { return ionResoC;      }    
  Double_t getIonResoD()      { return ionResoD;      }    
  Double_t getFastIonResoA()  { return fastIonAReso;  }
  Double_t getFastIonResoB()  { return fastIonBReso;  }
  Double_t getFastIonResoC()  { return fastIonCReso;  }
  Double_t getFastIonResoD()  { return fastIonDReso;  }
  Bool_t   isDecorrelated()   { return isDecorr;      }
  void dump();


 private:

  TString amplitudesOption;

  Double_t heatA;
  Double_t heatB;
  Double_t ionA;
  Double_t ionB;
  Double_t ionC;
  Double_t ionD;
  Double_t fastIonA;
  Double_t fastIonB;
  Double_t fastIonC;
  Double_t fastIonD;

  Double_t heatChi2A;
  Double_t heatChi2B;
  Double_t ionChi2A;
  Double_t ionChi2B;
  Double_t ionChi2C;
  Double_t ionChi2D;
  Double_t fastIonChi2A;
  Double_t fastIonChi2B;
  Double_t fastIonChi2C;
  Double_t fastIonChi2D;

  Double_t heatResoA;
  Double_t heatResoB;
  Double_t ionResoA;
  Double_t ionResoB;
  Double_t ionResoC;
  Double_t ionResoD;
  Double_t fastIonAReso;
  Double_t fastIonBReso;
  Double_t fastIonCReso;
  Double_t fastIonDReso;


  Bool_t   isDecorr;


};


class edwEnergies {

 public:

  edwEnergies();
  edwEnergies(TString name);
  edwEnergies(TString name, Double_t lha, Double_t lhb, Double_t ha, Double_t hb, 
	      Double_t ia, Double_t ib, Double_t ic, Double_t id,
	      Double_t fia, Double_t fib, Double_t fic, Double_t fid);
  ~edwEnergies() {}

  void setEnergiesOption(TString s)   { energiesOption = s;   }
  void setEhAuncorr(double value) { EhAuncorr = value;}   
  void setEhBuncorr(double value) { EhBuncorr = value;}   
  void setEhA(double value)       { EhA = value;      }   
  void setEhB(double value)       { EhB = value;      }   
  void setEiA(double value)       { EiA = value;      }    
  void setEiB(double value)       { EiB = value;      }    
  void setEiC(double value)       { EiC = value;      }    
  void setEiD(double value)       { EiD = value;      }    
  void setFastEiA(double value)   { fastEiA = value;  }
  void setFastEiB(double value)   { fastEiB = value;  }
  void setFastEiC(double value)   { fastEiC = value;  }
  void setFastEiD(double value)   { fastEiD = value;  }
  void setFWhA(double value)      { FWhA = value;     }   
  void setFWhB(double value)      { FWhB = value;     }   
  void setFWiA(double value)      { FWiA = value;     }    
  void setFWiB(double value)      { FWiB = value;     }    
  void setFWiC(double value)      { FWiC = value;     }    
  void setFWiD(double value)      { FWiD = value;     }    
  void setFWfastIA(double value)  { FWfastIA = value; }
  void setFWfastIB(double value)  { FWfastIB = value; }
  void setFWfastIC(double value)  { FWfastIC = value; }
  void setFWfastID(double value)  { FWfastID = value; }

  void computePhysicalVariables(edwIonCalibData* ionCalibData, edwHeatCalibData* heatCalibData, edwParamCalibData* paramCalibData,int polMode);

  TString  getEnergiesOption()  { return energiesOption;}
  Double_t getEhAuncorr()   { return EhAuncorr; }   
  Double_t getEhBuncorr()   { return EhBuncorr; }   
  Double_t getEhA()         { return EhA;       }   
  Double_t getEhB()         { return EhB;       }   
  Double_t getEiA()         { return EiA;       }    
  Double_t getEiB()         { return EiB;       }    
  Double_t getEiC()         { return EiC;       }    
  Double_t getEiD()         { return EiD;       }    
  Double_t getFastEiA()     { return fastEiA;   }
  Double_t getFastEiB()     { return fastEiB;   }
  Double_t getFastEiC()     { return fastEiC;   }
  Double_t getFastEiD()     { return fastEiD;   }
  Double_t getFWhA()        { return FWhA;      }   
  Double_t getFWhB()        { return FWhB;      }   
  Double_t getFWiA()        { return FWiA;      }    
  Double_t getFWiB()        { return FWiB;      }    
  Double_t getFWiC()        { return FWiC;      }    
  Double_t getFWiD()        { return FWiD;      }    
  Double_t getFWfastIA()    { return FWfastIA;  }
  Double_t getFWfastIB()    { return FWfastIB;  }
  Double_t getFWfastIC()    { return FWfastIC;  }
  Double_t getFWfastID()    { return FWfastID;  }

  Double_t  getEi()       { return Ei;       }	     
  Double_t  getEiFID()    { return EiFID;    }    
  Double_t  getEiFIDunweighted(){ return EiFIDunweighted;}    
  Double_t  getEiVETO()   { return EiVETO;   }   
  Double_t  getEiVETO1()  { return EiVETO1;  }   
  Double_t  getEiVETO2()  { return EiVETO2;  }   
  Double_t  getEhUncorr() { return EhUncorr; } 
  Double_t  getEh()       { return Eh;       }	     
  Double_t  getErFID()    { return ErFID;    }    
  Double_t  getEr()       { return Er;       }	     
  Double_t  getQFID()     { return QFID;     }     
  Double_t  getQ()        { return Q;        }        

  void dump();

 private:

  TString energiesOption;
  Double_t EhAuncorr;
  Double_t EhBuncorr;
  Double_t EhA;
  Double_t EhB;
  Double_t EiA;
  Double_t EiB;
  Double_t EiC;
  Double_t EiD;
  Double_t fastEiA;
  Double_t fastEiB;
  Double_t fastEiC;
  Double_t fastEiD;

  Double_t FWhA;
  Double_t FWhB;
  Double_t FWiA;
  Double_t FWiB;
  Double_t FWiC;
  Double_t FWiD;
  Double_t FWfastIA;
  Double_t FWfastIB;
  Double_t FWfastIC;
  Double_t FWfastID;
  

  Double_t Ei;
  Double_t EiFID;
  Double_t EiFIDunweighted;
  Double_t EiVETO;
  Double_t EiVETO1;
  Double_t EiVETO2;
  Double_t EhUncorr;
  Double_t Eh;
  Double_t ErFID;
  Double_t Er;
  Double_t QFID;
  Double_t Q;


};



class edwBolometer {

 public:

  edwBolometer() {
    boloName = "undefined";
    boloNb = -1;
    partitionNb = -1;
    timeFirstDay = 0;
    heatThresholdA = 0.;
    heatThresholdB = 0.;
    normalizedStep = 0.;
    AmpOF = NULL;
    AmpNoXPSD = NULL;
    AmpNoXPSD_t0 = NULL;
    AmpNoXPSD_Filt = NULL;
    AmpNoXPSD_t0_Filt = NULL;
    AmpIndNoXPSD = NULL;
    AmpIndNoXPSD_Filt = NULL;
    Amp_Trig = NULL;
    Amp_Trig_Filt = NULL;
    Amp_Trig_Filt_Decor = NULL;
    Amp_Trig_Fast_Filt = NULL;
    Amp_Noise = NULL;
    Amp_Noise_Filt = NULL;
    Amp_Noise_Filt_Decor = NULL;
    Amp_Noise_Fast_Filt = NULL;
    EnerOF = NULL;
    EnerNoXPSD = NULL;
    EnerNoXPSD_t0 = NULL;
    EnerNoXPSD_Filt = NULL;
    EnerNoXPSD_t0_Filt = NULL;
    EnerIndNoXPSD = NULL;
    EnerIndNoXPSD_Filt = NULL;
    Ener_Trig = NULL;
    Ener_Trig_Filt = NULL;
    Ener_Trig_Filt_Decor = NULL;
    Ener_Trig_Fast_Filt = NULL;
    Ener_Noise = NULL;
    Ener_Noise_Filt = NULL;
    Ener_Noise_Filt_Decor = NULL;
    Ener_Noise_Fast_Filt = NULL;
    /*     ionCalibData = NULL; */
    /*     heatCalibData = NULL; */
/*     paramCalibData = NULL;  */
/*     strucCalibData = NULL; */
  }

  ~edwBolometer();

  void addAmplitudes(edwAmplitudes* anAmplitudes) {
    if(anAmplitudes->getAmplitudesOption() == "OF") {
      AmpOF = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "NoXPSD") {
      AmpNoXPSD = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "NoXPSD_t0") {
      AmpNoXPSD_t0 = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "NoXPSD_Filt") {
      AmpNoXPSD_Filt = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "NoXPSD_t0_Filt") {
      AmpNoXPSD_t0_Filt = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "IndNoXPSD") {
      AmpIndNoXPSD = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "IndNoXPSD_Filt") {
      AmpIndNoXPSD_Filt = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "trig_Normal_raw") {
      Amp_Trig = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "trig_Normal_filt") {
      Amp_Trig_Filt = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "trig_Normal_filt_decor") {
      Amp_Trig_Filt_Decor = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "trig_Fast_filt") {
      Amp_Trig_Fast_Filt = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "noise_Normal_raw") {
      Amp_Noise = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "noise_Normal_filt") {
      Amp_Noise_Filt = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "noise_Normal_filt_decor") {
      Amp_Noise_Filt_Decor = anAmplitudes;
    } else if(anAmplitudes->getAmplitudesOption() == "noise_Fast_filt") {
      Amp_Noise_Fast_Filt = anAmplitudes;
    }
  }
  void addEnergies(edwEnergies* anEnergies) {
    //    anEnergies->setBolometer(this);
    if(anEnergies->getEnergiesOption() == "OF") {
      EnerOF = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "NoXPSD") {
      EnerNoXPSD = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "NoXPSD_t0") {
      EnerNoXPSD_t0 = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "NoXPSD_Filt") {
      EnerNoXPSD_Filt = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "NoXPSD_t0_Filt") {
      EnerNoXPSD_t0_Filt = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "IndNoXPSD") {
      EnerIndNoXPSD = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "IndNoXPSD_Filt") {
      EnerIndNoXPSD_Filt = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "trig_Normal_raw") {
      Ener_Trig = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "trig_Normal_filt") {
      Ener_Trig_Filt = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "trig_Normal_filt_decor") {
      Ener_Trig_Filt_Decor = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "trig_Fast_filt") {
      Ener_Trig_Fast_Filt = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "noise_Normal_raw") {
      Ener_Noise = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "noise_Normal_filt") {
      Ener_Noise_Filt = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "noise_Normal_filt_decor") {
      Ener_Noise_Filt_Decor = anEnergies;
    } else if(anEnergies->getEnergiesOption() == "noise_Fast_filt") {
      Ener_Noise_Fast_Filt = anEnergies;
    }
  }
  edwAmplitudes* getAmplitudes(string option) {
    if(option == "OF") {
      return AmpOF;
    } else if(option == "NoXPSD") {
      return AmpNoXPSD;
    } else if(option == "NoXPSD_t0") {
      return AmpNoXPSD_t0;
    } else if(option == "NoXPSD_Filt") {
      return AmpNoXPSD_Filt;
    } else if(option == "NoXPSD_t0_Filt") {
      return AmpNoXPSD_t0_Filt;
    } else if(option == "IndNoXPSD") {
      return AmpIndNoXPSD;
    } else if(option == "IndNoXPSD_Filt") {
      return AmpIndNoXPSD_Filt;
    } else if(option == "trig_Normal_raw") {
      return Amp_Trig;
    } else if(option == "trig_Normal_filt") {
      return Amp_Trig_Filt;
    } else if(option == "trig_Normal_filt_decor") {
      return Amp_Trig_Filt_Decor;
    } else if(option == "trig_Fast_filt") {
      return Amp_Trig_Fast_Filt;
    } else if(option == "noise_Normal_raw") {
      return Amp_Noise;
    } else if(option == "noise_Normal_filt") {
      return Amp_Noise_Filt;
    } else if(option == "noise_Normal_filt_decor") {
      return Amp_Noise_Filt_Decor;
    } else if(option == "noise_Fast_filt") {
      return Amp_Noise_Fast_Filt;
    } 
    cout << "edwBolometer::getAmplitudes ERROR : unknow " << option << endl;
    return NULL;
  }
  edwEnergies* getEnergies(string option) {
    if(option == "OF") {
      return EnerOF;
    } else if(option == "NoXPSD") {
      return EnerNoXPSD;
    } else if(option == "NoXPSD_t0") {
      return EnerNoXPSD_t0;
    } else if(option == "NoXPSD_Filt") {
      return EnerNoXPSD_Filt;
    } else if(option == "NoXPSD_t0_Filt") {
      return EnerNoXPSD_t0_Filt;
    } else if(option == "IndNoXPSD") {
      return EnerIndNoXPSD;
    } else if(option == "IndNoXPSD_Filt") {
      return EnerIndNoXPSD_Filt;
    } else if(option == "trig_Normal_raw") {
      return Ener_Trig;      
    } else if(option == "trig_Normal_filt") {
      return Ener_Trig_Filt;      
    } else if(option == "trig_Normal_filt_decor") {
      return Ener_Trig_Filt_Decor;      
    } else if(option == "trig_Fast_filt") {
      return Ener_Trig_Fast_Filt;      
    } else if(option == "noise_Normal_raw") {
      return Ener_Noise;      
    } else if(option == "noise_Normal_filt") {
      return Ener_Noise_Filt;      
    } else if(option == "noise_Normal_filt_decor") {
      return Ener_Noise_Filt_Decor;      
    } else if(option == "noise_Fast_filt") {
      return Ener_Noise_Fast_Filt;      
    } 
    cout << "edwBolometer::getEnergies ERROR : unknow " << option << endl;
    return NULL;
  }

  void setIonCalibDataIndex(int i)    { indexIonCalibData = i;    }
  void setHeatCalibDataIndex(int i)   { indexHeatCalibData = i;   }
  void setParamCalibDataIndex(int i)  { indexParamCalibData = i;  }
  void setStrucCalibDataIndex(int i)  { indexStrucCalibData = i;  }
  
  void setAnaRunNumber(Int_t nb)     { anaRunNumber = nb;  }
  void setBoloName(TString s)        { boloName = s;       }
  void setBoloNb(Int_t nb)           { boloNb = nb;        }
  void setPartitionNb(Int_t nb)      { partitionNb = nb;   }
  void setTimeFirstDay(Double_t t)   { timeFirstDay = t;   }
  void setEventNb(Int_t nb)          { eventNb = nb;       }
  void setHeatThresholdA(Double_t th){ heatThresholdA = th;}
  void setHeatThresholdB(Double_t th){ heatThresholdB = th;}
  void setNormalizedStep(Double_t ns){ normalizedStep = ns;}
  
/*   edwIonCalibData*   getIonCalibData()    { return ionCalibData;    } */
/*   edwHeatCalibData*  getHeatCalibData()   { return heatCalibData;   } */
/*   edwParamCalibData* getParamCalibData()  { return paramCalibData;  } */
/*   edwStrucCalibData* getStrucCalibData()  { return strucCalibData;  } */
  int getIonCalibDataIndex()    { return indexIonCalibData;    }
  int getHeatCalibDataIndex()   { return indexHeatCalibData;   }
  int getParamCalibDataIndex()  { return indexParamCalibData;  }
  int getStrucCalibDataIndex()  { return indexStrucCalibData;  }

  edwEnergies*       getEnergiesOF()      { return EnerOF;          }  
  
  TString  getBoloName()      { return boloName;      }
  Int_t    getBoloNb()        { return boloNb;        }
  Int_t    getPartitionNb()   { return partitionNb;   }
  Double_t getTimeFirstDay()  { return timeFirstDay;  }
  Int_t    getEventNb()       { return eventNb;       }
  Double_t getHeatThresholdA(){ return heatThresholdA;}
  Double_t getHeatThresholdB(){ return heatThresholdB;}
  Double_t getMinHeatThreshold() {
    return heatThresholdA < heatThresholdB ? heatThresholdA : heatThresholdB ;
  }
  Double_t getNormalizedStep(){ return normalizedStep;}
  Int_t    getAnaRunNumber() { return anaRunNumber; }
  void dump();
  void Reset();

 private:


  TString boloName;
  Int_t    anaRunNumber;
  Int_t    boloNb;
  Int_t    partitionNb;
  Double_t timeFirstDay;
  Int_t    eventNb;
  Double_t heatThresholdA;
  Double_t heatThresholdB;
  Double_t normalizedStep;

  edwAmplitudes* AmpOF;		      
  edwAmplitudes* AmpNoXPSD;	      
  edwAmplitudes* AmpNoXPSD_t0;	      
  edwAmplitudes* AmpNoXPSD_Filt;      
  edwAmplitudes* AmpNoXPSD_t0_Filt;   
  edwAmplitudes* AmpIndNoXPSD;	      
  edwAmplitudes* AmpIndNoXPSD_Filt;   
  edwAmplitudes* Amp_Trig;	      
  edwAmplitudes* Amp_Trig_Filt;	      
  edwAmplitudes* Amp_Trig_Filt_Decor; 
  edwAmplitudes* Amp_Trig_Fast_Filt;	      
  edwAmplitudes* Amp_Noise;	      
  edwAmplitudes* Amp_Noise_Filt;      
  edwAmplitudes* Amp_Noise_Filt_Decor;
  edwAmplitudes* Amp_Noise_Fast_Filt;      

  edwEnergies* EnerOF;		     
  edwEnergies* EnerNoXPSD;	     
  edwEnergies* EnerNoXPSD_t0;	     
  edwEnergies* EnerNoXPSD_Filt;	     
  edwEnergies* EnerNoXPSD_t0_Filt;   
  edwEnergies* EnerIndNoXPSD;	     
  edwEnergies* EnerIndNoXPSD_Filt;   
  edwEnergies* Ener_Trig;	     
  edwEnergies* Ener_Trig_Filt;	     
  edwEnergies* Ener_Trig_Filt_Decor; 
  edwEnergies* Ener_Trig_Fast_Filt;	     
  edwEnergies* Ener_Noise;	     
  edwEnergies* Ener_Noise_Filt;	     
  edwEnergies* Ener_Noise_Filt_Decor;
  edwEnergies* Ener_Noise_Fast_Filt;	     

  int indexIonCalibData;
  int indexHeatCalibData;
  int indexParamCalibData;
  int indexStrucCalibData;


};

#endif //edwRData_h
