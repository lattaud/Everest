#ifndef edwBaseTreeManager_h
#define edwBaseTreeManager_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Fixed size dimensions of array or collections stored in the TTree if any.

class edwBaseTreeManager {
 protected :

   vector<string>  processingMethodes;
   string          m_sambaRun;
   string          *runNumber;

 public:

  // ------------- METHODS -----------------------------------


   edwBaseTreeManager();
   virtual ~edwBaseTreeManager();

   //   Int_t GetAnaRunNumber(int RUN);
   virtual Int_t GetEntries() = 0;
   virtual void GetEntry(int ientry) = 0;


   virtual Double_t getHeatADU(string ch, string option) = 0;
   virtual Double_t getIonADU(string ch,string shaper, string option) = 0;
   virtual Double_t getHeatChi2(string ch, string option) = 0;
   virtual Double_t getIonChi2(string ch,string shaper, string option) = 0;
   virtual Double_t getHeatResolution(string ch, string option) = 0;
   virtual Double_t getIonResolution(string ch,string shaper, string option) = 0;

   virtual Double_t getTimeSinceCryorunStart() = 0;
   virtual Double_t getTimeSinceLastEvent() = 0;
   virtual Double_t getSambaBoloTemperature() = 0;

   virtual Int_t    getAnaRunNumber()= 0;
   virtual Int_t    getEventNb() = 0;
   virtual Int_t    getBoloID() = 0;
   virtual Int_t    getPartitionNb() = 0;
   virtual Bool_t   getIsDecor(string option) = 0;
   virtual string   getBoloName() = 0;
   virtual Double_t   getHeatThresholdA() = 0;
   virtual Double_t   getHeatThresholdB() = 0;
   virtual Double_t   getNormalizedStep() = 0;

   virtual Bool_t isEntryOK(string s) { return true; }


   vector<string> getProcessingMethodes() {
     return processingMethodes;
   }

   void setSambaRun(string s) { m_sambaRun = s; }

};



#endif


