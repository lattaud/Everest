#ifndef edwEverestTreeOutManager_h
#define edwEverestTreeOutManager_h

#include "edwRData.h"
#include <string>
#include <vector>
using namespace std;


#include "TFile.h"
#include "TTree.h"


class edwEverestTreeOutManager {


 public:

  // Ctors
  edwEverestTreeOutManager();
  edwEverestTreeOutManager(TString name);

  void SetProcessingMethods(vector<string> value) { fProcessingMethods = value; }
  vector<string> GetProcessingMethods() {
    return fProcessingMethods;
  }

  void FillCalib(edwIonCalibDataMap ionCalibDataMap);
  void FillCalib(edwHeatCalibDataMap heatCalibDataMap);
  void FillCalib(edwParamCalibDataMap paramCalibDataMap);
  void FillCalib(edwStrucCalibDataMap strucCalibDataMap);

  void FillEvent();

  void SetReso(string ch,double reso);
  void FillReso(string procMeth);
  

  Int_t GetEntries(string procMeth);

  void GetEntry(Int_t i,string option);

  void WriteCalibTree() {
    fRootFile->cd();
    fTreeIonCalibData->Write();	     
    fTreeHeatCalibData->Write();	     
    fTreeParamCalibData->Write();	     
    fTreeStrucCalibData->Write();	     
  }

  Double_t GetEhA() { return heatA; }	  
  Double_t GetEhB() { return heatB; }	  
  Double_t GetEiA() { return ionA; }	  
  Double_t GetEiB() { return ionB; }	  
  Double_t GetEiC() { return ionC; }	  
  Double_t GetEiD() { return ionD; }	  
  Double_t GetFastEiA() { return fastIonA; }	
  Double_t GetFastEiB() { return fastIonB; }	
  Double_t GetFastEiC() { return fastIonC; }	
  Double_t GetFastEiD() { return fastIonD; }	
  Double_t GetE(string ch);
  Double_t GetNormalizedChi2(string ch);
  Int_t GetRunNumber() {return fAnaRunNumber;}



  void Write() {
    fRootFile->cd();
    
    fTreeBoloHeader->Write();	     
    
    if(fTreeAmplitudesOF->GetEntries()>0 ) fTreeAmplitudesOF->Write();	     
    if(fTreeAmplitudesNoXPSD->GetEntries()>0 ) fTreeAmplitudesNoXPSD->Write();          
    if(fTreeAmplitudesNoXPSD_t0->GetEntries()>0 ) fTreeAmplitudesNoXPSD_t0->Write();   
    if(fTreeAmplitudesNoXPSD_Filt->GetEntries()>0 ) fTreeAmplitudesNoXPSD_Filt->Write(); 
    if(fTreeAmplitudesNoXPSD_t0_Filt->GetEntries()>0 ) fTreeAmplitudesNoXPSD_t0_Filt->Write();
    if(fTreeAmplitudesIndNoXPSD->GetEntries()>0 ) fTreeAmplitudesIndNoXPSD->Write();   
    if(fTreeAmplitudesIndNoXPSD_Filt->GetEntries()>0 ) fTreeAmplitudesIndNoXPSD_Filt->Write();
                                                                    
    if(fTreeAmplitudes_Trig->GetEntries()>0 ) fTreeAmplitudes_Trig->Write();           
    if(fTreeAmplitudes_Trig_Filt->GetEntries()>0 ) fTreeAmplitudes_Trig_Filt->Write();	     
    if(fTreeAmplitudes_Trig_Filt_Decor->GetEntries()>0 ) fTreeAmplitudes_Trig_Filt_Decor->Write();	     
    if(fTreeAmplitudes_Trig_Fast_Filt->GetEntries()>0 ) fTreeAmplitudes_Trig_Fast_Filt->Write();	     
    if(fTreeAmplitudes_Noise->GetEntries()>0 ) fTreeAmplitudes_Noise->Write();          
    if(fTreeAmplitudes_Noise_Filt->GetEntries()>0 ) fTreeAmplitudes_Noise_Filt->Write();	     
    if(fTreeAmplitudes_Noise_Filt_Decor->GetEntries()>0 ) fTreeAmplitudes_Noise_Filt_Decor->Write();	     
    if(fTreeAmplitudes_Noise_Fast_Filt->GetEntries()>0 ) fTreeAmplitudes_Noise_Fast_Filt->Write();	     
    				    				    
    if(fTreeEnergiesOF->GetEntries()>0 ) fTreeEnergiesOF->Write();	     
    if(fTreeEnergiesNoXPSD->GetEntries()>0 ) fTreeEnergiesNoXPSD->Write();            
    if(fTreeEnergiesNoXPSD_t0->GetEntries()>0 ) fTreeEnergiesNoXPSD_t0->Write();     
    if(fTreeEnergiesNoXPSD_Filt->GetEntries()>0 ) fTreeEnergiesNoXPSD_Filt->Write();   
    if(fTreeEnergiesNoXPSD_t0_Filt->GetEntries()>0 ) fTreeEnergiesNoXPSD_t0_Filt->Write();
    if(fTreeEnergiesIndNoXPSD->GetEntries()>0 ) fTreeEnergiesIndNoXPSD->Write();     
    if(fTreeEnergiesIndNoXPSD_Filt->GetEntries()>0 ) fTreeEnergiesIndNoXPSD_Filt->Write();
                                                                    
    if(fTreeEnergies_Trig->GetEntries()>0 ) fTreeEnergies_Trig->Write();             
    if(fTreeEnergies_Trig_Filt->GetEntries()>0 ) fTreeEnergies_Trig_Filt->Write();	     
    if(fTreeEnergies_Trig_Filt_Decor->GetEntries()>0 ) fTreeEnergies_Trig_Filt_Decor->Write();	     
    if(fTreeEnergies_Trig_Fast_Filt->GetEntries()>0 ) fTreeEnergies_Trig_Fast_Filt->Write();	     
    if(fTreeEnergies_Noise->GetEntries()>0 ) fTreeEnergies_Noise->Write();            
    if(fTreeEnergies_Noise_Filt->GetEntries()>0 ) fTreeEnergies_Noise_Filt->Write();	     
    if(fTreeEnergies_Noise_Filt_Decor->GetEntries()>0 ) fTreeEnergies_Noise_Filt_Decor->Write();	     
    if(fTreeEnergies_Noise_Fast_Filt->GetEntries()>0 ) fTreeEnergies_Noise_Fast_Filt->Write();	     

  }

  void Close() {
    fRootFile->Close();
  }

  edwBolometer* GetBolo() { return fBolometer; }
  void resetBolometer();

 private:

  int fAnaRunNumber;
  int fBoloID;
  vector<string> fProcessingMethods;

  // variable for edwIonCalibData
  double fIonGainA;     
  double fIonGainB;     
  double fIonGainC;     
  double fIonGainD;     
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


  // variable for edwHeatCalibData
  double fVoltage;
  double fHeatGainA;
  double fHeatGainB;
  double fHeatTimeDependence;

  // variable for edwParamCalibData
  double fFiducialVoltage; 
  double fVetoVoltage;	   
  double fIoniXtalkCutA;   
  double fIoniXtalkCutB;   
  double fIoniXtalkCutC;   
  double fIoniXtalkCutD;   
  double fHeatCorrA;	   
  double fHeatCorrB;	   
  double fNonLinearityA[5];
  double fThresholdCorrA;   
  double fThresholdCorrB;   
  double fNonLinearityB[5];
  double fHeatAweight;	   
  double fIonBweight;      

  // variable for edwStrucCalibData
  int fBoloIndexInSamba;
  int fHeatAbitNumber; 
  int fHeatBbitNumber; 
  int fPolarisationMode;


  // variable for ewdAmplitudes
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

  // variable for edwEnergies
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

  // variable for header

  string   boloName;	      
  Int_t    boloNb;	      
  Int_t    partitionNb;	      
  Double_t timeFirstDay;      
  Int_t    eventNb;	      
  Double_t heatThresholdA;    
  Double_t heatThresholdB;    
  Double_t normalizedStep;    
  int      indexIonCalibData;  
  int      indexHeatCalibData; 
  int      indexParamCalibData;
  int      indexStrucCalibData;


  // variable for resolution tree

  Double_t resoHeatA;   
  Double_t resoHeatB;  
  Double_t resoHeatTot; 
  Double_t resoIonA;    
  Double_t resoIonB;    
  Double_t resoIonC;    
  Double_t resoIonD;    
  Double_t resoFastIonA;
  Double_t resoFastIonB;
  Double_t resoFastIonC;
  Double_t resoFastIonD;

  // Manager variables

  TString fFileName;
  TFile * fRootFile;

  TTree* fTreeIonCalibData;	     
  TTree* fTreeHeatCalibData;	     
  TTree* fTreeParamCalibData;	     
  TTree* fTreeStrucCalibData;	     
	                             
  TTree* fTreeBoloHeader;	     
                          
  TTree* fTreeAmplitudesOF;	       
  TTree* fTreeAmplitudesNoXPSD;	       
  TTree* fTreeAmplitudesNoXPSD_t0;     
  TTree* fTreeAmplitudesNoXPSD_Filt;   
  TTree* fTreeAmplitudesNoXPSD_t0_Filt;
  TTree* fTreeAmplitudesIndNoXPSD;     
  TTree* fTreeAmplitudesIndNoXPSD_Filt;

  TTree* fTreeAmplitudes_Trig;	     	  
  TTree* fTreeAmplitudes_Trig_Filt;	     
  TTree* fTreeAmplitudes_Trig_Filt_Decor;            
  TTree* fTreeAmplitudes_Trig_Fast_Filt;	     
  TTree* fTreeAmplitudes_Noise;	     	  
  TTree* fTreeAmplitudes_Noise_Filt;	     
  TTree* fTreeAmplitudes_Noise_Filt_Decor;	     
  TTree* fTreeAmplitudes_Noise_Fast_Filt;	     
	                             
  TTree* fTreeEnergiesOF;	     
  TTree* fTreeEnergiesNoXPSD;	     
  TTree* fTreeEnergiesNoXPSD_t0;     
  TTree* fTreeEnergiesNoXPSD_Filt;   
  TTree* fTreeEnergiesNoXPSD_t0_Filt;
  TTree* fTreeEnergiesIndNoXPSD;     
  TTree* fTreeEnergiesIndNoXPSD_Filt;

  TTree* fTreeEnergies_Trig;	     
  TTree* fTreeEnergies_Trig_Filt;	     
  TTree* fTreeEnergies_Trig_Filt_Decor;	     
  TTree* fTreeEnergies_Trig_Fast_Filt;	     
  TTree* fTreeEnergies_Noise;	     
  TTree* fTreeEnergies_Noise_Filt;	     
  TTree* fTreeEnergies_Noise_Filt_Decor;	     
  TTree* fTreeEnergies_Noise_Fast_Filt;	     

  TTree* fTreeResolutionsOF;	       	     
  TTree* fTreeResolutionsNoXPSD;	       	     
  TTree* fTreeResolutionsNoXPSD_t0;                  
  TTree* fTreeResolutionsNoXPSD_Filt;                
  TTree* fTreeResolutionsNoXPSD_t0_Filt;             
  TTree* fTreeResolutionsIndNoXPSD;                  
  TTree* fTreeResolutionsIndNoXPSD_Filt;             
	                                  
  TTree* fTreeResolutions_Noise;	     	  	     
  TTree* fTreeResolutions_Noise_Filt;	  	     
  TTree* fTreeResolutions_Noise_Filt_Decor;	     
  TTree* fTreeResolutions_Noise_Fast_Filt;	  	     


  edwBolometer* fBolometer;
  

};



#endif //edwEverestTreeOutManager_h
