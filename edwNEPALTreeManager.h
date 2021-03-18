#ifndef edwNEPALTreeManager_h
#define edwNEPALTreeManager_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Fixed size dimensions of array or collections stored in the TTree if any.

#include "edwBaseTreeManager.h"

class edwNEPALTreeManager : public edwBaseTreeManager {
private :

  // ------------- EVENT TREE --------------------------------

   TTree          *fEventTree;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Double_t        Energy_OF[10];
   Double_t        Time_OF_Out;
   Double_t        chi2_OF[10];
   Double_t        Energy_OF_NoXPSD[10];
   Double_t        Time_OF_Out_NoXPSD;
   Double_t        chi2_OF_NoXPSD[10];
   Double_t        Energy_OF_NoXPSD_t0[10];
   Double_t        Time_OF_Out_NoXPSD_t0;
   Double_t        chi2_OF_NoXPSD_t0[10];
   Double_t        Energy_Heat_NoXPSD[2];
   Double_t        Time_Heat_Out_NoXPSD;
   Double_t        chi2_Heat_NoXPSD[2];
   Double_t        Energy_Ion_NoXPSD[8];
   Double_t        Time_Ion_Out_NoXPSD;
   Double_t        chi2_Ion_NoXPSD[8];
   Double_t        chi2_NULL_NoXPSD[10];
   Double_t        Energy_OF_NoXPSD_Filt[10];
   Double_t        Time_OF_Out_NoXPSD_Filt;
   Double_t        chi2_OF_NoXPSD_Filt[10];
   Double_t        Energy_OF_NoXPSD_t0_Filt[10];
   Double_t        Time_OF_Out_NoXPSD_t0_Filt;
   Double_t        chi2_OF_NoXPSD_t0_Filt[10];
   Double_t        Energy_Heat_NoXPSD_Filt[2];
   Double_t        Time_Heat_Out_NoXPSD_Filt;
   Double_t        chi2_Heat_NoXPSD_Filt[2];
   Double_t        Energy_Ion_NoXPSD_Filt[8];
   Double_t        Time_Ion_Out_NoXPSD_Filt;
   Double_t        chi2_Ion_NoXPSD_Filt[8];
   Double_t        chi2_NULL_NoXPSD_Filt[10];
   Double_t        Amp_preprocess[10];
   Double_t        Offset_preprocess[10];
   Double_t        Slope_Ion[4];
   Int_t           Event_Number;
   Int_t           Event_Owner;
   Int_t           Event_bitpattern;
   Int_t           MegaStp;
   Int_t           MicroStp;
   string          *NameRun;
   Int_t           N_hour;
   Int_t           runAnax;
   Int_t           sambaNPart;
   Int_t           evtinPart;
   Float_t         cryorunV;
   Int_t           maxtrigCh;
   Int_t           firstUT;
   Int_t           secondUT;
   Int_t           thirdUT;
   Double_t        sinceStartD;
   Int_t           bitPatChalA;
   Int_t           bitPatChalB;
   Double_t        sinceLastS;
   Double_t        Tbolo;
   Double_t        resetFetS;
   Double_t        amplOwnA;
   Double_t        amplOwnB;
   Double_t        thtrigA;
   Double_t        thtrigB;
   Int_t           boloID;
   string          *boloType;
   Int_t           Enabled_Heat_A;
   Int_t           Enabled_Heat_B;
   Int_t           Enabled_Ion_A;
   Int_t           Enabled_Ion_B;
   Int_t           Enabled_Ion_C;
   Int_t           Enabled_Ion_D;
   Int_t           Enabled_Slow_A;
   Int_t           Enabled_Slow_B;
   Int_t           Enabled_Slow_C;
   Int_t           Enabled_Slow_D;


   //   string          m_sambaRun;

   // List of branches
   TBranch        *b_Energy_OF;   //!
   TBranch        *b_Time_OF_Out;   //!
   TBranch        *b_chi2_OF;   //!
   TBranch        *b_Energy_OF_NoXPSD;   //!
   TBranch        *b_Time_OF_Out_NoXPSD;   //!
   TBranch        *b_chi2_OF_NoXPSD;   //!
   TBranch        *b_Energy_OF_NoXPSD_t0;   //!
   TBranch        *b_Time_OF_Out_NoXPSD_t0;   //!
   TBranch        *b_chi2_OF_NoXPSD_t0;   //!
   TBranch        *b_Energy_Heat_NoXPSD;   //!
   TBranch        *b_Time_Heat_Out_NoXPSD;   //!
   TBranch        *b_chi2_Heat_NoXPSD;   //!
   TBranch        *b_Energy_Ion_NoXPSD;   //!
   TBranch        *b_Time_Ion_Out_NoXPSD;   //!
   TBranch        *b_chi2_Ion_NoXPSD;   //!
   TBranch        *b_chi2_NULL_NoXPSD;   //!
   TBranch        *b_Energy_OF_NoXPSD_Filt;   //!
   TBranch        *b_Time_OF_Out_NoXPSD_Filt;   //!
   TBranch        *b_chi2_OF_NoXPSD_Filt;   //!
   TBranch        *b_Energy_OF_NoXPSD_t0_Filt;   //!
   TBranch        *b_Time_OF_Out_NoXPSD_t0_Filt;   //!
   TBranch        *b_chi2_OF_NoXPSD_t0_Filt;   //!
   TBranch        *b_Energy_Heat_NoXPSD_Filt;   //!
   TBranch        *b_Time_Heat_Out_NoXPSD_Filt;   //!
   TBranch        *b_chi2_Heat_NoXPSD_Filt;   //!
   TBranch        *b_Energy_Ion_NoXPSD_Filt;   //!
   TBranch        *b_Time_Ion_Out_NoXPSD_Filt;   //!
   TBranch        *b_chi2_Ion_NoXPSD_Filt;   //!
   TBranch        *b_chi2_NULL_NoXPSD_Filt;   //!
   TBranch        *b_Amp_preprocess;   //!
   TBranch        *b_Offset_preprocess;   //!
   TBranch        *b_Slope_Ion;   //!
   TBranch        *b_Event_Number;   //!
   TBranch        *b_Event_Owner;   //!
   TBranch        *b_Event_bitpattern;   //!
   TBranch        *b_MegaStp;   //!
   TBranch        *b_MicroStp;   //!
   TBranch        *b_NameRun;   //!
   TBranch        *b_N_hour;   //!
   TBranch        *b_runAnax;   //!
   TBranch        *b_sambaNPart;   //!
   TBranch        *b_evtinPart;   //!
   TBranch        *b_cryorunV;   //!
   TBranch        *b_maxtrigCh;   //!
   TBranch        *b_firstUT;   //!
   TBranch        *b_secondUT;   //!
   TBranch        *b_thirdUT;   //!
   TBranch        *b_sinceStartD;   //!
   TBranch        *b_bitPatChalA;   //!
   TBranch        *b_bitPatChalB;   //!
   TBranch        *b_sinceLastS;   //!
   TBranch        *b_Tbolo;   //!
   TBranch        *b_resetFetS;   //!
   TBranch        *b_amplOwnA;   //!
   TBranch        *b_amplOwnB;   //!
   TBranch        *b_thtrigA;   //!
   TBranch        *b_thtrigB;   //!
   TBranch        *b_boloID;   //!
   TBranch        *b_boloType;   //!
   TBranch        *b_Enabled_Heat_A;
   TBranch        *b_Enabled_Heat_B;
   TBranch        *b_Enabled_Ion_A;
   TBranch        *b_Enabled_Ion_B;
   TBranch        *b_Enabled_Ion_C;
   TBranch        *b_Enabled_Ion_D;
   TBranch        *b_Enabled_Slow_A;
   TBranch        *b_Enabled_Slow_B;
   TBranch        *b_Enabled_Slow_C;
   TBranch        *b_Enabled_Slow_D;

  // ------------- RUN TREE --------------------------------

   TTree          *fRunTree;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Double_t        HeatParameter_A[9];
   Double_t        HeatParameter_B[9];
   Double_t        PSD_Heat_A[1024];
   Double_t        PSD_Heat_B[1024];
   Double_t        OF_Heat_A[1024];
   Double_t        OF_Heat_B[1024];
   Double_t        Template_Heat_A[1024];
   Double_t        Template_Heat_B[1024];
   Double_t        PSD_Heat_Freq[1024];
   Double_t        PSD_Slow_A[1024];
   Double_t        PSD_Slow_B[1024];
   Double_t        PSD_Slow_C[1024];
   Double_t        PSD_Slow_D[1024];
   Double_t        OF_Slow_A[1024];
   Double_t        OF_Slow_B[1024];
   Double_t        OF_Slow_C[1024];
   Double_t        OF_Slow_D[1024];
   Double_t        Template_Slow[1024];
   Double_t        PSD_Slow_Freq[1024];
   Double_t        PSD_Fast_A[4096];
   Double_t        PSD_Fast_B[4096];
   Double_t        PSD_Fast_C[4096];
   Double_t        PSD_Fast_D[4096];
   Double_t        OF_Fast_A[4096];
   Double_t        OF_Fast_B[4096];
   Double_t        OF_Fast_C[4096];
   Double_t        OF_Fast_D[4096];
   Double_t        Template_Fast[4096];
   Double_t        PSD_Fast_Freq[4096];
   Double_t        OF_resolutions[10];
   Double_t        OF_Filt_resolutions[10];
   Double_t        t0_heat_shift;
   Int_t           N_Selected_Randoms;
/*    string          *runNumber; */
   Int_t           N_hour_header;

   // List of branches
   TBranch        *b_HeatParameter_A;   //!
   TBranch        *b_HeatParameter_B;   //!
   TBranch        *b_PSD_Heat_A;   //!
   TBranch        *b_PSD_Heat_B;   //!
   TBranch        *b_OF_Heat_A;   //!
   TBranch        *b_OF_Heat_B;   //!
   TBranch        *b_Template_Heat_A;   //!
   TBranch        *b_Template_Heat_B;   //!
   TBranch        *b_PSD_Heat_Freq;   //!
   TBranch        *b_PSD_Slow_A;   //!
   TBranch        *b_PSD_Slow_B;   //!
   TBranch        *b_PSD_Slow_C;   //!
   TBranch        *b_PSD_Slow_D;   //!
   TBranch        *b_OF_Slow_A;   //!
   TBranch        *b_OF_Slow_B;   //!
   TBranch        *b_OF_Slow_C;   //!
   TBranch        *b_OF_Slow_D;   //!
   TBranch        *b_Template_Slow;   //!
   TBranch        *b_PSD_Slow_Freq;   //!
   TBranch        *b_PSD_Fast_A;   //!
   TBranch        *b_PSD_Fast_B;   //!
   TBranch        *b_PSD_Fast_C;   //!
   TBranch        *b_PSD_Fast_D;   //!
   TBranch        *b_OF_Fast_A;   //!
   TBranch        *b_OF_Fast_B;   //!
   TBranch        *b_OF_Fast_C;   //!
   TBranch        *b_OF_Fast_D;   //!
   TBranch        *b_Template_Fast;   //!
   TBranch        *b_PSD_Fast_Freq;   //!
   TBranch        *b_OF_resolutions;   //!
   TBranch        *b_OF_Filt_resolutions;   //!
   TBranch        *b_t0_heat_shift;   //!
   TBranch        *b_N_Selected_Randoms;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_N_hour_header;   //!

  // ------------- Usefull Variables --------------------------------
   string          fileName;

 public:

  // ------------- METHODS -----------------------------------


   edwNEPALTreeManager(TFile *f);
   edwNEPALTreeManager(TString name);
   virtual ~edwNEPALTreeManager();


   virtual void     InitEventTree(TTree *tree);
   virtual void     InitRunTree(TTree *tree);

   Int_t GetEntries();
   void GetEntry(int ientry);
   Double_t getHeatAadu();
   Double_t getHeatBadu();
   Double_t getFastIonAadu();
   Double_t getFastIonBadu();
   Double_t getFastIonCadu();
   Double_t getFastIonDadu();
   Double_t getSlowIonAadu();
   Double_t getSlowIonBadu();
   Double_t getSlowIonCadu();
   Double_t getSlowIonDadu();

   Double_t getHeatADU(string ch, string option);
   Double_t getIonADU(string ch,string shaper, string option);
   Double_t getHeatChi2(string ch, string option);
   Double_t getIonChi2(string ch,string shaper, string option);
   Double_t getHeatResolution(string ch, string option);
   Double_t getIonResolution(string ch,string shaper, string option);

   Double_t getTimeSinceCryorunStart();
   Double_t getTimeSinceLastEvent();
   Double_t getSambaBoloTemperature();
   Int_t    getAnaRunNumber();
   Int_t    getEventNb();
   Int_t    getBoloID();
   Int_t    getPartitionNb();
   Bool_t   getIsDecor(string option="");
   string   getBoloName();
   Double_t   getHeatThresholdA();
   Double_t   getHeatThresholdB();
   Double_t   getNormalizedStep();

};

#endif
