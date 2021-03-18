#ifndef edwNEPALStreamTreeManager_h
#define edwNEPALStreamTreeManager_h

#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Fixed size dimensions of array or collections stored in the TTree if any.

#include "edwBaseTreeManager.h"


class edwNEPALStreamTreeManager : public edwBaseTreeManager {
private :



  // ------------- EVENT TREES -------------------------------

  TTree          *fEvent_TR_Tree; // Trig Normal Raw

   // Declaration of leaf types
   Double_t        Energy_OF_TR[6];
   Double_t        Time_OF_TR;
   Double_t        chi2_OF_TR[6];
   Double_t        Energy_OF_t0_TR[6];
   Double_t        Time_OF_t0_TR;
   Double_t        chi2_OF_t0_TR[6];
   Double_t        chi2_NULL_TR[6];
   Double_t        Amp_TR[6];
   Double_t        RMS_TR[6];
   Double_t        Off_TR[6];
   Double_t        Slope_Ion_TR[4];
   Int_t           index_OF_table_TR[38];
   Float_t         Energy_OF_table_TR[38][6];
   Float_t         chi2_OF_table_TR[38][6];
   Int_t           Event_Number;
   Int_t           Event_Owner;
   Int_t           Event_bitpattern;
   Int_t           MegaStp;
   Int_t           MicroStp;
   Int_t           NumRun;
   Int_t           NumPart;
/*    string          *NameRun; */

   // List of branches
   TBranch        *b_TR_Energy_OF;   //!
   TBranch        *b_TR_Time_OF;   //!
   TBranch        *b_TR_chi2_OF;   //!
   TBranch        *b_TR_Energy_OF_t0;   //!
   TBranch        *b_TR_Time_OF_t0;   //!
   TBranch        *b_TR_chi2_OF_t0;   //!
   TBranch        *b_TR_chi2_NULL;   //!
   TBranch        *b_TR_Amp;   //!
   TBranch        *b_TR_RMS;   //!
   TBranch        *b_TR_Off;   //!
   TBranch        *b_TR_Slope_Ion;   //!
   TBranch        *b_TR_index_OF_table;   //!
   TBranch        *b_TR_Energy_OF_table;   //!
   TBranch        *b_TR_chi2_OF_table;   //!
   TBranch        *b_TR_Event_Number;   //!
   TBranch        *b_TR_Event_Owner;   //!
   TBranch        *b_TR_Event_bitpattern;   //!
   TBranch        *b_TR_MegaStp;   //!
   TBranch        *b_TR_MicroStp;   //!
   TBranch        *b_TR_NumRun;   //!
   TBranch        *b_TR_NumPart;   //!
   TBranch        *b_TR_NameRun;   //!

   TTree          *fEvent_TF_Tree; // Trig Normal Filt

   // Declaration of leaf types
   Double_t        Energy_OF_TF[6];
   Double_t        Time_OF_TF;
   Double_t        chi2_OF_TF[6];
   Double_t        Energy_OF_t0_TF[6];
   Double_t        Time_OF_t0_TF;
   Double_t        chi2_OF_t0_TF[6];
   Double_t        chi2_NULL_TF[6];
   Double_t        Amp_TF[6];
   Double_t        RMS_TF[6];
   Double_t        Off_TF[6];
   Double_t        Slope_Ion_TF[4];
   Int_t           index_OF_table_TF[38];
   Float_t         Energy_OF_table_TF[38][6];
   Float_t         chi2_OF_table_TF[38][6];

   // List of branches
   TBranch        *b_TF_Energy_OF;   //!
   TBranch        *b_TF_Time_OF;   //!
   TBranch        *b_TF_chi2_OF;   //!
   TBranch        *b_TF_Energy_OF_t0;   //!
   TBranch        *b_TF_Time_OF_t0;   //!
   TBranch        *b_TF_chi2_OF_t0;   //!
   TBranch        *b_TF_chi2_NULL;   //!
   TBranch        *b_TF_Amp;   //!
   TBranch        *b_TF_RMS;   //!
   TBranch        *b_TF_Off;   //!
   TBranch        *b_TF_Slope_Ion;   //!
   TBranch        *b_TF_index_OF_table;   //!
   TBranch        *b_TF_Energy_OF_table;   //!
   TBranch        *b_TF_chi2_OF_table;   //!
   TBranch        *b_TF_Event_Number;   //!
   TBranch        *b_TF_Event_Owner;   //!
   TBranch        *b_TF_Event_bitpattern;   //!
   TBranch        *b_TF_MegaStp;   //!
   TBranch        *b_TF_MicroStp;   //!
   TBranch        *b_TF_NumRun;   //!
   TBranch        *b_TF_NumPart;   //!
   TBranch        *b_TF_NameRun;   //!

   TTree          *fEvent_TFD_Tree; // Trig Normal Filt Decor

   // Declaration of leaf types
   Double_t        Energy_OF_TFD[6];
   Double_t        Time_OF_TFD;
   Double_t        chi2_OF_TFD[6];
   Double_t        Energy_OF_t0_TFD[6];
   Double_t        Time_OF_t0_TFD;
   Double_t        chi2_OF_t0_TFD[6];
   Double_t        chi2_NULL_TFD[6];
   Double_t        Amp_TFD[6];
   Double_t        RMS_TFD[6];
   Double_t        Off_TFD[6];
   Double_t        Slope_Ion_TFD[4];
   Int_t           index_OF_table_TFD[38];
   Float_t         Energy_OF_table_TFD[38][6];
   Float_t         chi2_OF_table_TFD[38][6];

   // List of branches
   TBranch        *b_TFD_Energy_OF;   //!
   TBranch        *b_TFD_Time_OF;   //!
   TBranch        *b_TFD_chi2_OF;   //!
   TBranch        *b_TFD_Energy_OF_t0;   //!
   TBranch        *b_TFD_Time_OF_t0;   //!
   TBranch        *b_TFD_chi2_OF_t0;   //!
   TBranch        *b_TFD_chi2_NULL;   //!
   TBranch        *b_TFD_Amp;   //!
   TBranch        *b_TFD_RMS;   //!
   TBranch        *b_TFD_Off;   //!
   TBranch        *b_TFD_Slope_Ion;   //!
   TBranch        *b_TFD_index_OF_table;   //!
   TBranch        *b_TFD_Energy_OF_table;   //!
   TBranch        *b_TFD_chi2_OF_table;   //!
   TBranch        *b_TFD_Event_Number;   //!
   TBranch        *b_TFD_Event_Owner;   //!
   TBranch        *b_TFD_Event_bitpattern;   //!
   TBranch        *b_TFD_MegaStp;   //!
   TBranch        *b_TFD_MicroStp;   //!
   TBranch        *b_TFD_NumRun;   //!
   TBranch        *b_TFD_NumPart;   //!
   TBranch        *b_TFD_NameRun;   //!

   TTree          *fEvent_TFF_Tree; // Trig Fast Filt

   // Declaration of leaf types
   Double_t        Energy_OF_TFF[6];
   Double_t        Time_OF_TFF;
   Double_t        chi2_OF_TFF[6];
   Double_t        Energy_OF_t0_TFF[6];
   Double_t        Time_OF_t0_TFF;
   Double_t        chi2_OF_t0_TFF[6];
   Double_t        chi2_NULL_TFF[6];
   Double_t        Amp_TFF[6];
   Double_t        RMS_TFF[6];
   Double_t        Off_TFF[6];
   Double_t        Slope_Ion_TFF[4];
   Int_t           index_OF_table_TFF[38];
   Float_t         Energy_OF_table_TFF[38][6];
   Float_t         chi2_OF_table_TFF[38][6];

   // List of branches
   TBranch        *b_TFF_Energy_OF;   //!
   TBranch        *b_TFF_Time_OF;   //!
   TBranch        *b_TFF_chi2_OF;   //!
   TBranch        *b_TFF_Energy_OF_t0;   //!
   TBranch        *b_TFF_Time_OF_t0;   //!
   TBranch        *b_TFF_chi2_OF_t0;   //!
   TBranch        *b_TFF_chi2_NULL;   //!
   TBranch        *b_TFF_Amp;   //!
   TBranch        *b_TFF_RMS;   //!
   TBranch        *b_TFF_Off;   //!
   TBranch        *b_TFF_Slope_Ion;   //!
   TBranch        *b_TFF_index_OF_table;   //!
   TBranch        *b_TFF_Energy_OF_table;   //!
   TBranch        *b_TFF_chi2_OF_table;   //!
   TBranch        *b_TFF_Event_Number;   //!
   TBranch        *b_TFF_Event_Owner;   //!
   TBranch        *b_TFF_Event_bitpattern;   //!
   TBranch        *b_TFF_MegaStp;   //!
   TBranch        *b_TFF_MicroStp;   //!
   TBranch        *b_TFF_NumRun;   //!
   TBranch        *b_TFF_NumPart;   //!
   TBranch        *b_TFF_NameRun;   //!


   TTree          *fEvent_NR_Tree; // Noise Normal Raw

   // Declaration of leaf types
   Double_t        Energy_OF_NR[6];
   Double_t        Time_OF_NR;
   Double_t        chi2_OF_NR[6];
   Double_t        Energy_OF_t0_NR[6];
   Double_t        Time_OF_t0_NR;
   Double_t        chi2_OF_t0_NR[6];
   Double_t        chi2_NULL_NR[6];
   Double_t        Amp_NR[6];
   Double_t        RMS_NR[6];
   Double_t        Off_NR[6];
   Double_t        Slope_Ion_NR[4];
   Int_t           index_OF_table_NR[38];
   Float_t         Energy_OF_table_NR[38][6];
   Float_t         chi2_OF_table_NR[38][6];

   // List of branches
   TBranch        *b_NR_Energy_OF;   //!
   TBranch        *b_NR_Time_OF;   //!
   TBranch        *b_NR_chi2_OF;   //!
   TBranch        *b_NR_Energy_OF_t0;   //!
   TBranch        *b_NR_Time_OF_t0;   //!
   TBranch        *b_NR_chi2_OF_t0;   //!
   TBranch        *b_NR_chi2_NULL;   //!
   TBranch        *b_NR_Amp;   //!
   TBranch        *b_NR_RMS;   //!
   TBranch        *b_NR_Off;   //!
   TBranch        *b_NR_Slope_Ion;   //!
   TBranch        *b_NR_index_OF_table;   //!
   TBranch        *b_NR_Energy_OF_table;   //!
   TBranch        *b_NR_chi2_OF_table;   //!
   TBranch        *b_NR_Event_Number;   //!
   TBranch        *b_NR_Event_Owner;   //!
   TBranch        *b_NR_Event_bitpattern;   //!
   TBranch        *b_NR_MegaStp;   //!
   TBranch        *b_NR_MicroStp;   //!
   TBranch        *b_NR_NumRun;   //!
   TBranch        *b_NR_NumPart;   //!
   TBranch        *b_NR_NameRun;   //!

   TTree          *fEvent_NF_Tree; // Noise Normal Filt

   // Declaration of leaf types
   Double_t        Energy_OF_NF[6];
   Double_t        Time_OF_NF;
   Double_t        chi2_OF_NF[6];
   Double_t        Energy_OF_t0_NF[6];
   Double_t        Time_OF_t0_NF;
   Double_t        chi2_OF_t0_NF[6];
   Double_t        chi2_NULL_NF[6];
   Double_t        Amp_NF[6];
   Double_t        RMS_NF[6];
   Double_t        Off_NF[6];
   Double_t        Slope_Ion_NF[4];
   Int_t           index_OF_table_NF[38];
   Float_t         Energy_OF_table_NF[38][6];
   Float_t         chi2_OF_table_NF[38][6];

   // List of branches
   TBranch        *b_NF_Energy_OF;   //!
   TBranch        *b_NF_Time_OF;   //!
   TBranch        *b_NF_chi2_OF;   //!
   TBranch        *b_NF_Energy_OF_t0;   //!
   TBranch        *b_NF_Time_OF_t0;   //!
   TBranch        *b_NF_chi2_OF_t0;   //!
   TBranch        *b_NF_chi2_NULL;   //!
   TBranch        *b_NF_Amp;   //!
   TBranch        *b_NF_RMS;   //!
   TBranch        *b_NF_Off;   //!
   TBranch        *b_NF_Slope_Ion;   //!
   TBranch        *b_NF_index_OF_table;   //!
   TBranch        *b_NF_Energy_OF_table;   //!
   TBranch        *b_NF_chi2_OF_table;   //!
   TBranch        *b_NF_Event_Number;   //!
   TBranch        *b_NF_Event_Owner;   //!
   TBranch        *b_NF_Event_bitpattern;   //!
   TBranch        *b_NF_MegaStp;   //!
   TBranch        *b_NF_MicroStp;   //!
   TBranch        *b_NF_NumRun;   //!
   TBranch        *b_NF_NumPart;   //!
   TBranch        *b_NF_NameRun;   //!

   TTree          *fEvent_NFD_Tree; // Noise Normal Filt Decor

   // Declaration of leaf types
   Double_t        Energy_OF_NFD[6];
   Double_t        Time_OF_NFD;
   Double_t        chi2_OF_NFD[6];
   Double_t        Energy_OF_t0_NFD[6];
   Double_t        Time_OF_t0_NFD;
   Double_t        chi2_OF_t0_NFD[6];
   Double_t        chi2_NULL_NFD[6];
   Double_t        Amp_NFD[6];
   Double_t        RMS_NFD[6];
   Double_t        Off_NFD[6];
   Double_t        Slope_Ion_NFD[4];
   Int_t           index_OF_table_NFD[38];
   Float_t         Energy_OF_table_NFD[38][6];
   Float_t         chi2_OF_table_NFD[38][6];

   // List of branches
   TBranch        *b_NFD_Energy_OF;   //!
   TBranch        *b_NFD_Time_OF;   //!
   TBranch        *b_NFD_chi2_OF;   //!
   TBranch        *b_NFD_Energy_OF_t0;   //!
   TBranch        *b_NFD_Time_OF_t0;   //!
   TBranch        *b_NFD_chi2_OF_t0;   //!
   TBranch        *b_NFD_chi2_NULL;   //!
   TBranch        *b_NFD_Amp;   //!
   TBranch        *b_NFD_RMS;   //!
   TBranch        *b_NFD_Off;   //!
   TBranch        *b_NFD_Slope_Ion;   //!
   TBranch        *b_NFD_index_OF_table;   //!
   TBranch        *b_NFD_Energy_OF_table;   //!
   TBranch        *b_NFD_chi2_OF_table;   //!
   TBranch        *b_NFD_Event_Number;   //!
   TBranch        *b_NFD_Event_Owner;   //!
   TBranch        *b_NFD_Event_bitpattern;   //!
   TBranch        *b_NFD_MegaStp;   //!
   TBranch        *b_NFD_MicroStp;   //!
   TBranch        *b_NFD_NumRun;   //!
   TBranch        *b_NFD_NumPart;   //!
   TBranch        *b_NFD_NameRun;   //!

   TTree          *fEvent_NFF_Tree; // Noise Fast Filt

   // Declaration of leaf types
   Double_t        Energy_OF_NFF[6];
   Double_t        Time_OF_NFF;
   Double_t        chi2_OF_NFF[6];
   Double_t        Energy_OF_t0_NFF[6];
   Double_t        Time_OF_t0_NFF;
   Double_t        chi2_OF_t0_NFF[6];
   Double_t        chi2_NULL_NFF[6];
   Double_t        Amp_NFF[6];
   Double_t        RMS_NFF[6];
   Double_t        Off_NFF[6];
   Double_t        Slope_Ion_NFF[4];
   Int_t           index_OF_table_NFF[38];
   Float_t         Energy_OF_table_NFF[38][6];
   Float_t         chi2_OF_table_NFF[38][6];

   // List of branches
   TBranch        *b_NFF_Energy_OF;   //!
   TBranch        *b_NFF_Time_OF;   //!
   TBranch        *b_NFF_chi2_OF;   //!
   TBranch        *b_NFF_Energy_OF_t0;   //!
   TBranch        *b_NFF_Time_OF_t0;   //!
   TBranch        *b_NFF_chi2_OF_t0;   //!
   TBranch        *b_NFF_chi2_NULL;   //!
   TBranch        *b_NFF_Amp;   //!
   TBranch        *b_NFF_RMS;   //!
   TBranch        *b_NFF_Off;   //!
   TBranch        *b_NFF_Slope_Ion;   //!
   TBranch        *b_NFF_index_OF_table;   //!
   TBranch        *b_NFF_Energy_OF_table;   //!
   TBranch        *b_NFF_chi2_OF_table;   //!
   TBranch        *b_NFF_Event_Number;   //!
   TBranch        *b_NFF_Event_Owner;   //!
   TBranch        *b_NFF_Event_bitpattern;   //!
   TBranch        *b_NFF_MegaStp;   //!
   TBranch        *b_NFF_MicroStp;   //!
   TBranch        *b_NFF_NumRun;   //!
   TBranch        *b_NFF_NumPart;   //!
   TBranch        *b_NFF_NameRun;   //!

  // ------------- RUN TREE --------------------------------

   TTree          *fRunTree;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Double_t        BestFitHeat[2][9];
   Double_t        PSD_Raw[1024][6];
   Double_t        PSD_Filt[1024][6];
   Double_t        PSD_Decor[1024][6];
   Double_t        PSD_Filt_Decor[1024][6];
   Double_t        OF_Raw[1024];
   Double_t        OF_Filt[1024][6];
   Double_t        OF_Decor[1024];
   Double_t        OF_Filt_Decor[1024][6];
   Double_t        Template_Heat_Raw[1024][2];
   Double_t        Template_Heat_Filt[1024][2];
   Double_t        PSD_Freq[1024];
   Double_t        OF_resolutions[6];
   Double_t        OF_Filt_resolutions[6];
   Double_t        OF_Decor_resolutions[6];
   Double_t        OF_Filt_Decor_resolutions[6];
   Double_t        OF_Window_Low;
   Double_t        OF_Window_Up;
   Int_t           N_delta;
   Double_t        t0_vector[201];
   Double_t        t0_heat_shift;
   Int_t           N_Selected_Randoms;
   string          *select_detector;
/*    Int_t           NumRun; */
   Int_t           trigger_channel;
/*    Int_t           NumPart; */
   Int_t           N_samples_Heat;
   Int_t           N_samples_Ion;
   Double_t        f_max_heat;
   Double_t        f_max_ion;
   Double_t        TimeWindow_Heat;
   Double_t        TimeWindow_Ion;
   Double_t        cutoff_freq;
   Int_t           filter_order;
   Int_t           Chan_ON[6];
   Double_t        Chan_Gain[6];
   string          *TemplateRun;
   string          *TemplateType;
   Int_t           Rt;
   Int_t           Date_sec;
   Int_t           Date_microsec;
   Int_t           GigaStamp0;
   Int_t           TimeStamp0;
   Int_t           GigaStampN;
   Int_t           TimeStampN;
   Int_t           N_maint_In_part;
   Double_t        T_inf_vector[10];
   Double_t        T_sup_vector[10];
   Double_t        MaintenanceCycle;
   Double_t        MaintenanceDuration;

   // List of branches
   TBranch        *b_BestFitHeat;   //!
   TBranch        *b_PSD_Raw;   //!
   TBranch        *b_PSD_Filt;   //!
   TBranch        *b_PSD_Decor;   //!
   TBranch        *b_PSD_Filt_Decor;   //!
   TBranch        *b_OF_Raw;   //!
   TBranch        *b_OF_Filt;   //!
   TBranch        *b_OF_Decor;   //!
   TBranch        *b_OF_Filt_Decor;   //!
   TBranch        *b_Template_Heat_Raw;   //!
   TBranch        *b_Template_Heat_Filt;   //!
   TBranch        *b_PSD_Freq;   //!
   TBranch        *b_OF_resolutions;   //!
   TBranch        *b_OF_Filt_resolutions;   //!
   TBranch        *b_OF_Decor_resolutions;   //!
   TBranch        *b_OF_Filt_Decor_resolutions;   //!
   TBranch        *b_OF_Window_Low;   //!
   TBranch        *b_OF_Window_Up;   //!
   TBranch        *b_N_delta;   //!
   TBranch        *b_t0_vector;   //!
   TBranch        *b_t0_heat_shift;   //!
   TBranch        *b_N_Selected_Randoms;   //!
   TBranch        *b_run;   //!
   TBranch        *b_select_detector;   //!
   TBranch        *b_NumRun;   //!
   TBranch        *b_trigger_channel;   //!
   TBranch        *b_NumPart;   //!
   TBranch        *b_N_samples_Heat;   //!
   TBranch        *b_N_samples_Ion;   //!
   TBranch        *b_f_max_heat;   //!
   TBranch        *b_f_max_ion;   //!
   TBranch        *b_TimeWindow_Heat;   //!
   TBranch        *b_TimeWindow_Ion;   //!
   TBranch        *b_cutoff_freq;   //!
   TBranch        *b_filter_order;   //!
   TBranch        *b_Chan_ON;   //!
   TBranch        *b_Chan_Gain;   //!
   TBranch        *b_TemplateRun;   //!
   TBranch        *b_TemplateType;   //!
   TBranch        *b_Rt;   //!
   TBranch        *b_Date_sec;   //!
   TBranch        *b_Date_microsec;   //!
   TBranch        *b_GigaStamp0;   //!
   TBranch        *b_TimeStamp0;   //!
   TBranch        *b_GigaStampN;   //!
   TBranch        *b_TimeStampN;   //!
   TBranch        *b_N_maint_In_part;   //!
   TBranch        *b_T_inf_vector;   //!
   TBranch        *b_T_sup_vector;   //!
   TBranch        *b_MaintenanceCycle;   //!
   TBranch        *b_MaintenanceDuration;   //!


   bool entryTR_OK; 
   bool entryTF_OK; 
   bool entryTFD_OK;
   bool entryTFF_OK; 
   bool entryNR_OK; 
   bool entryNF_OK; 
   bool entryNFD_OK;
   bool entryNFF_OK; 



  // ------------- Usefull Variables --------------------------------
   string          fileName;
/*    vector<string>  processingMethodes; */

 public:

  // ------------- METHODS -----------------------------------


   edwNEPALStreamTreeManager(TFile *f);
   edwNEPALStreamTreeManager(string name);
   virtual ~edwNEPALStreamTreeManager();


   void     InitEvent_TR_Tree(TTree *tree);
   void     InitEvent_TF_Tree(TTree *tree);
   void     InitEvent_TFD_Tree(TTree *tree);
   void     InitEvent_TFF_Tree(TTree *tree);
   void     InitEvent_NR_Tree(TTree *tree);
   void     InitEvent_NF_Tree(TTree *tree);
   void     InitEvent_NFD_Tree(TTree *tree);
   void     InitEvent_NFF_Tree(TTree *tree);
   void     InitRunTree(TTree *tree);

/*    Int_t GetAnaRunNumber(int RUN); */
   Int_t GetEntries();

   void GetEntry(int ientry);
   Bool_t isEntryOK(string s);

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
   Bool_t   getIsDecor(string option);
   string   getBoloName();
   Double_t   getHeatThresholdA();
   Double_t   getHeatThresholdB();
   Double_t   getNormalizedStep();



};

#endif

