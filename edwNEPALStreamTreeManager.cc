#include "edwNEPALStreamTreeManager.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


edwNEPALStreamTreeManager::edwNEPALStreamTreeManager(TFile *f) : edwBaseTreeManager()
{

  fEvent_TR_Tree = 0; // Trig Normal Raw
  fEvent_TF_Tree = 0; // Trig Normal Filt
  fEvent_TFD_Tree = 0; // Trig Normal Filt Decor
  fEvent_TFF_Tree = 0; // Trig Fast Filt
  fEvent_NR_Tree = 0; // Noise Normal Raw
  fEvent_NF_Tree = 0; // Noise Normal Filt
  fEvent_NFD_Tree = 0; // Noise Normal Filt Decor
  fEvent_NFF_Tree = 0; // Noise Fast Filt
  fRunTree = 0;   //!pointer to the analyzed TTree or TChain
  
  TTree* tree;

  f->GetObject("EventTree_trig_Normal_raw",tree);
  InitEvent_TR_Tree(tree);
  f->GetObject("EventTree_trig_Normal_filt",tree);
  InitEvent_TF_Tree(tree);
  f->GetObject("EventTree_trig_Normal_filt_decor",tree);
  InitEvent_TFD_Tree(tree);
  f->GetObject("EventTree_trig_Fast_filt",tree);
  InitEvent_TFF_Tree(tree);

  f->GetObject("EventTree_noise_Normal_raw",tree);
  InitEvent_NR_Tree(tree);
  f->GetObject("EventTree_noise_Normal_filt",tree);
  InitEvent_NF_Tree(tree);
  f->GetObject("EventTree_noise_Normal_filt_decor",tree);
  InitEvent_NFD_Tree(tree);
  f->GetObject("EventTree_noise_Fast_filt",tree);
  InitEvent_NFF_Tree(tree);


  f->GetObject("RunTree_Normal",tree);
  InitRunTree(tree);

  entryTR_OK = false; 
  entryTF_OK = false; 
  entryTFD_OK = false;
  entryTFF_OK = false; 
  entryNR_OK = false; 
  entryNF_OK = false; 
  entryNFD_OK = false;
  entryNFF_OK = false; 

}
edwNEPALStreamTreeManager::edwNEPALStreamTreeManager(string name) : edwBaseTreeManager(),fileName(name) 
{
  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(fileName.c_str());
  if (!f || !f->IsOpen()) {
    f = new TFile(fileName.c_str());
  }

  fEvent_TR_Tree = 0; // Trig Normal Raw
  fEvent_TF_Tree = 0; // Trig Normal Filt
  fEvent_TFD_Tree = 0; // Trig Normal Filt Decor
  fEvent_TFF_Tree = 0; // Trig Fast Filt
  fEvent_NR_Tree = 0; // Noise Normal Raw
  fEvent_NF_Tree = 0; // Noise Normal Filt
  fEvent_NFD_Tree = 0; // Noise Normal Filt Decor
  fEvent_NFF_Tree = 0; // Noise Fast Filt
  fRunTree = 0;   //!pointer to the analyzed TTree or TChain
  

  TTree* tree;

  f->GetObject("EventTree_trig_Normal_raw",tree);
  InitEvent_TR_Tree(tree);
  f->GetObject("EventTree_trig_Normal_filt",tree);
  InitEvent_TF_Tree(tree);
  f->GetObject("EventTree_trig_Normal_filt_decor",tree);
  InitEvent_TFD_Tree(tree);
  f->GetObject("EventTree_trig_Fast_filt",tree);
  InitEvent_TFF_Tree(tree);

  f->GetObject("EventTree_noise_Normal_raw",tree);
  InitEvent_NR_Tree(tree);
  f->GetObject("EventTree_noise_Normal_filt",tree);
  InitEvent_NF_Tree(tree);
  f->GetObject("EventTree_noise_Normal_filt_decor",tree);
  InitEvent_NFD_Tree(tree);
  f->GetObject("EventTree_noise_Fast_filt",tree);
  InitEvent_NFF_Tree(tree);


  f->GetObject("RunTree_Normal",tree);
  InitRunTree(tree);

  entryTR_OK = false; 
  entryTF_OK = false; 
  entryTFD_OK = false;
  entryTFF_OK = false; 
  entryNR_OK = false; 
  entryNF_OK = false; 
  entryNFD_OK = false;
  entryNFF_OK = false; 

}

edwNEPALStreamTreeManager::~edwNEPALStreamTreeManager()
{
}


void edwNEPALStreamTreeManager::InitEvent_TR_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_TR_Tree = tree;
   fEvent_TR_Tree->SetMakeClass(1);

   fEvent_TR_Tree->SetBranchAddress("Energy_OF", Energy_OF_TR, &b_TF_Energy_OF);
   fEvent_TR_Tree->SetBranchAddress("Time_OF", &Time_OF_TR, &b_TF_Time_OF);
   fEvent_TR_Tree->SetBranchAddress("chi2_OF", chi2_OF_TR, &b_TF_chi2_OF);
   fEvent_TR_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_TR, &b_TF_Energy_OF_t0);
   fEvent_TR_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_TR, &b_TF_Time_OF_t0);
   fEvent_TR_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_TR, &b_TF_chi2_OF_t0);
   fEvent_TR_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_TR, &b_TF_chi2_NULL);
   fEvent_TR_Tree->SetBranchAddress("Amp", Amp_TR, &b_TF_Amp);
   fEvent_TR_Tree->SetBranchAddress("RMS", RMS_TR, &b_TF_RMS);
   fEvent_TR_Tree->SetBranchAddress("Off", Off_TR, &b_TF_Off);
   fEvent_TR_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_TR, &b_TF_Slope_Ion);
   fEvent_TR_Tree->SetBranchAddress("index_OF_table", index_OF_table_TR, &b_TF_index_OF_table);
   fEvent_TR_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_TR, &b_TF_Energy_OF_table);
   fEvent_TR_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_TR, &b_TF_chi2_OF_table);
   fEvent_TR_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_TF_Event_Number);
   fEvent_TR_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_TF_Event_Owner);
   fEvent_TR_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_TF_Event_bitpattern);
   fEvent_TR_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_TF_MegaStp);
   fEvent_TR_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_TF_MicroStp);
   fEvent_TR_Tree->SetBranchAddress("NumRun", &NumRun, &b_TF_NumRun);
   fEvent_TR_Tree->SetBranchAddress("NumPart", &NumPart, &b_TF_NumPart);
   fEvent_TR_Tree->SetBranchAddress("NameRun", &runNumber, &b_TF_NameRun);

   processingMethodes.push_back("trig_Normal_raw");
 
}

void edwNEPALStreamTreeManager::InitEvent_TF_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_TF_Tree = tree;
   fEvent_TF_Tree->SetMakeClass(1);

   fEvent_TF_Tree->SetBranchAddress("Energy_OF", Energy_OF_TF, &b_TF_Energy_OF);
   fEvent_TF_Tree->SetBranchAddress("Time_OF", &Time_OF_TF, &b_TF_Time_OF);
   fEvent_TF_Tree->SetBranchAddress("chi2_OF", chi2_OF_TF, &b_TF_chi2_OF);
   fEvent_TF_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_TF, &b_TF_Energy_OF_t0);
   fEvent_TF_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_TF, &b_TF_Time_OF_t0);
   fEvent_TF_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_TF, &b_TF_chi2_OF_t0);
   fEvent_TF_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_TF, &b_TF_chi2_NULL);
   fEvent_TF_Tree->SetBranchAddress("Amp", Amp_TF, &b_TF_Amp);
   fEvent_TF_Tree->SetBranchAddress("RMS", RMS_TF, &b_TF_RMS);
   fEvent_TF_Tree->SetBranchAddress("Off", Off_TF, &b_TF_Off);
   fEvent_TF_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_TF, &b_TF_Slope_Ion);
   fEvent_TF_Tree->SetBranchAddress("index_OF_table", index_OF_table_TF, &b_TF_index_OF_table);
   fEvent_TF_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_TF, &b_TF_Energy_OF_table);
   fEvent_TF_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_TF, &b_TF_chi2_OF_table);
   fEvent_TF_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_TF_Event_Number);
   fEvent_TF_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_TF_Event_Owner);
   fEvent_TF_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_TF_Event_bitpattern);
   fEvent_TF_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_TF_MegaStp);
   fEvent_TF_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_TF_MicroStp);
   fEvent_TF_Tree->SetBranchAddress("NumRun", &NumRun, &b_TF_NumRun);
   fEvent_TF_Tree->SetBranchAddress("NumPart", &NumPart, &b_TF_NumPart);
   fEvent_TF_Tree->SetBranchAddress("NameRun", &runNumber, &b_TF_NameRun);

   processingMethodes.push_back("trig_Normal_filt");
 
   
}

void edwNEPALStreamTreeManager::InitEvent_TFD_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_TFD_Tree = tree;
   fEvent_TFD_Tree->SetMakeClass(1);

   fEvent_TFD_Tree->SetBranchAddress("Energy_OF", Energy_OF_TFD, &b_TFD_Energy_OF);
   fEvent_TFD_Tree->SetBranchAddress("Time_OF", &Time_OF_TFD, &b_TFD_Time_OF);
   fEvent_TFD_Tree->SetBranchAddress("chi2_OF", chi2_OF_TFD, &b_TFD_chi2_OF);
   fEvent_TFD_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_TFD, &b_TFD_Energy_OF_t0);
   fEvent_TFD_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_TFD, &b_TFD_Time_OF_t0);
   fEvent_TFD_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_TFD, &b_TFD_chi2_OF_t0);
   fEvent_TFD_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_TFD, &b_TFD_chi2_NULL);
   fEvent_TFD_Tree->SetBranchAddress("Amp", Amp_TFD, &b_TFD_Amp);
   fEvent_TFD_Tree->SetBranchAddress("RMS", RMS_TFD, &b_TFD_RMS);
   fEvent_TFD_Tree->SetBranchAddress("Off", Off_TFD, &b_TFD_Off);
   fEvent_TFD_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_TFD, &b_TFD_Slope_Ion);
   fEvent_TFD_Tree->SetBranchAddress("index_OF_table", index_OF_table_TFD, &b_TFD_index_OF_table);
   fEvent_TFD_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_TFD, &b_TFD_Energy_OF_table);
   fEvent_TFD_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_TFD, &b_TFD_chi2_OF_table);
   fEvent_TFD_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_TFD_Event_Number);
   fEvent_TFD_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_TFD_Event_Owner);
   fEvent_TFD_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_TFD_Event_bitpattern);
   fEvent_TFD_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_TFD_MegaStp);
   fEvent_TFD_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_TFD_MicroStp);
   fEvent_TFD_Tree->SetBranchAddress("NumRun", &NumRun, &b_TFD_NumRun);
   fEvent_TFD_Tree->SetBranchAddress("NumPart", &NumPart, &b_TFD_NumPart);
   fEvent_TFD_Tree->SetBranchAddress("NameRun", &runNumber, &b_TFD_NameRun);

   processingMethodes.push_back("trig_Normal_filt_decor");
 
   
}

void edwNEPALStreamTreeManager::InitEvent_TFF_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_TFF_Tree = tree;
   fEvent_TFF_Tree->SetMakeClass(1);

   fEvent_TFF_Tree->SetBranchAddress("Energy_OF", Energy_OF_TFF, &b_TFF_Energy_OF);
   fEvent_TFF_Tree->SetBranchAddress("Time_OF", &Time_OF_TFF, &b_TFF_Time_OF);
   fEvent_TFF_Tree->SetBranchAddress("chi2_OF", chi2_OF_TFF, &b_TFF_chi2_OF);
   fEvent_TFF_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_TFF, &b_TFF_Energy_OF_t0);
   fEvent_TFF_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_TFF, &b_TFF_Time_OF_t0);
   fEvent_TFF_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_TFF, &b_TFF_chi2_OF_t0);
   fEvent_TFF_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_TFF, &b_TFF_chi2_NULL);
   fEvent_TFF_Tree->SetBranchAddress("Amp", Amp_TFF, &b_TFF_Amp);
   fEvent_TFF_Tree->SetBranchAddress("RMS", RMS_TFF, &b_TFF_RMS);
   fEvent_TFF_Tree->SetBranchAddress("Off", Off_TFF, &b_TFF_Off);
   fEvent_TFF_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_TFF, &b_TFF_Slope_Ion);
   fEvent_TFF_Tree->SetBranchAddress("index_OF_table", index_OF_table_TFF, &b_TFF_index_OF_table);
   fEvent_TFF_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_TFF, &b_TFF_Energy_OF_table);
   fEvent_TFF_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_TFF, &b_TFF_chi2_OF_table);
   fEvent_TFF_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_TFF_Event_Number);
   fEvent_TFF_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_TFF_Event_Owner);
   fEvent_TFF_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_TFF_Event_bitpattern);
   fEvent_TFF_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_TFF_MegaStp);
   fEvent_TFF_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_TFF_MicroStp);
   fEvent_TFF_Tree->SetBranchAddress("NumRun", &NumRun, &b_TFF_NumRun);
   fEvent_TFF_Tree->SetBranchAddress("NumPart", &NumPart, &b_TFF_NumPart);
   fEvent_TFF_Tree->SetBranchAddress("NameRun", &runNumber, &b_TFF_NameRun);

   processingMethodes.push_back("trig_Fast_filt");
 
   
}


void edwNEPALStreamTreeManager::InitEvent_NR_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_NR_Tree = tree;
   fEvent_NR_Tree->SetMakeClass(1);

   fEvent_NR_Tree->SetBranchAddress("Energy_OF", Energy_OF_NR, &b_NR_Energy_OF);
   fEvent_NR_Tree->SetBranchAddress("Time_OF", &Time_OF_NR, &b_NR_Time_OF);
   fEvent_NR_Tree->SetBranchAddress("chi2_OF", chi2_OF_NR, &b_NR_chi2_OF);
   fEvent_NR_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_NR, &b_NR_Energy_OF_t0);
   fEvent_NR_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_NR, &b_NR_Time_OF_t0);
   fEvent_NR_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_NR, &b_NR_chi2_OF_t0);
   fEvent_NR_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_NR, &b_NR_chi2_NULL);
   fEvent_NR_Tree->SetBranchAddress("Amp", Amp_NR, &b_NR_Amp);
   fEvent_NR_Tree->SetBranchAddress("RMS", RMS_NR, &b_NR_RMS);
   fEvent_NR_Tree->SetBranchAddress("Off", Off_NR, &b_NR_Off);
   fEvent_NR_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_NR, &b_NR_Slope_Ion);
   fEvent_NR_Tree->SetBranchAddress("index_OF_table", index_OF_table_NR, &b_NR_index_OF_table);
   fEvent_NR_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_NR, &b_NR_Energy_OF_table);
   fEvent_NR_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_NR, &b_NR_chi2_OF_table);
   fEvent_NR_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_NR_Event_Number);
   fEvent_NR_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_NR_Event_Owner);
   fEvent_NR_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_NR_Event_bitpattern);
   fEvent_NR_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_NR_MegaStp);
   fEvent_NR_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_NR_MicroStp);
   fEvent_NR_Tree->SetBranchAddress("NumRun", &NumRun, &b_NR_NumRun);
   fEvent_NR_Tree->SetBranchAddress("NumPart", &NumPart, &b_NR_NumPart);
   fEvent_NR_Tree->SetBranchAddress("NameRun", &runNumber, &b_NR_NameRun);

   processingMethodes.push_back("noise_Normal_raw");
 
   
}

void edwNEPALStreamTreeManager::InitEvent_NF_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_NF_Tree = tree;
   fEvent_NF_Tree->SetMakeClass(1);

   fEvent_NF_Tree->SetBranchAddress("Energy_OF", Energy_OF_NF, &b_NF_Energy_OF);
 //  fEvent_NF_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_NF, &b_NF_Energy_OF);
   fEvent_NF_Tree->SetBranchAddress("Time_OF", &Time_OF_NF, &b_NF_Time_OF);
   fEvent_NF_Tree->SetBranchAddress("chi2_OF", chi2_OF_NF, &b_NF_chi2_OF);
   fEvent_NF_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_NF, &b_NF_Energy_OF_t0);
   fEvent_NF_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_NF, &b_NF_Time_OF_t0);
   fEvent_NF_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_NF, &b_NF_chi2_OF_t0);
   fEvent_NF_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_NF, &b_NF_chi2_NULL);
   fEvent_NF_Tree->SetBranchAddress("Amp", Amp_NF, &b_NF_Amp);
   fEvent_NF_Tree->SetBranchAddress("RMS", RMS_NF, &b_NF_RMS);
   fEvent_NF_Tree->SetBranchAddress("Off", Off_NF, &b_NF_Off);
   fEvent_NF_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_NF, &b_NF_Slope_Ion);
   fEvent_NF_Tree->SetBranchAddress("index_OF_table", index_OF_table_NF, &b_NF_index_OF_table);
   fEvent_NF_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_NF, &b_NF_Energy_OF_table);
   fEvent_NF_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_NF, &b_NF_chi2_OF_table);
   fEvent_NF_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_NF_Event_Number);
   fEvent_NF_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_NF_Event_Owner);
   fEvent_NF_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_NF_Event_bitpattern);
   fEvent_NF_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_NF_MegaStp);
   fEvent_NF_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_NF_MicroStp);
   fEvent_NF_Tree->SetBranchAddress("NumRun", &NumRun, &b_NF_NumRun);
   fEvent_NF_Tree->SetBranchAddress("NumPart", &NumPart, &b_NF_NumPart);
   fEvent_NF_Tree->SetBranchAddress("NameRun", &runNumber, &b_NF_NameRun);

   processingMethodes.push_back("noise_Normal_filt");
 
   
}

void edwNEPALStreamTreeManager::InitEvent_NFD_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_NFD_Tree = tree;
   fEvent_NFD_Tree->SetMakeClass(1);

   fEvent_NFD_Tree->SetBranchAddress("Energy_OF", Energy_OF_NFD, &b_NFD_Energy_OF);
   fEvent_NFD_Tree->SetBranchAddress("Time_OF", &Time_OF_NFD, &b_NFD_Time_OF);
   fEvent_NFD_Tree->SetBranchAddress("chi2_OF", chi2_OF_NFD, &b_NFD_chi2_OF);
   fEvent_NFD_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_NFD, &b_NFD_Energy_OF_t0);
   fEvent_NFD_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_NFD, &b_NFD_Time_OF_t0);
   fEvent_NFD_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_NFD, &b_NFD_chi2_OF_t0);
   fEvent_NFD_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_NFD, &b_NFD_chi2_NULL);
   fEvent_NFD_Tree->SetBranchAddress("Amp", Amp_NFD, &b_NFD_Amp);
   fEvent_NFD_Tree->SetBranchAddress("RMS", RMS_NFD, &b_NFD_RMS);
   fEvent_NFD_Tree->SetBranchAddress("Off", Off_NFD, &b_NFD_Off);
   fEvent_NFD_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_NFD, &b_NFD_Slope_Ion);
   fEvent_NFD_Tree->SetBranchAddress("index_OF_table", index_OF_table_NFD, &b_NFD_index_OF_table);
   fEvent_NFD_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_NFD, &b_NFD_Energy_OF_table);
   fEvent_NFD_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_NFD, &b_NFD_chi2_OF_table);
   fEvent_NFD_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_NFD_Event_Number);
   fEvent_NFD_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_NFD_Event_Owner);
   fEvent_NFD_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_NFD_Event_bitpattern);
   fEvent_NFD_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_NFD_MegaStp);
   fEvent_NFD_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_NFD_MicroStp);
   fEvent_NFD_Tree->SetBranchAddress("NumRun", &NumRun, &b_NFD_NumRun);
   fEvent_NFD_Tree->SetBranchAddress("NumPart", &NumPart, &b_NFD_NumPart);
   fEvent_NFD_Tree->SetBranchAddress("NameRun", &runNumber, &b_NFD_NameRun);

   processingMethodes.push_back("noise_Normal_filt_decor");
 
}

void edwNEPALStreamTreeManager::InitEvent_NFF_Tree(TTree *tree)
{

  // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEvent_NFF_Tree = tree;
   fEvent_NFF_Tree->SetMakeClass(1);

   fEvent_NFF_Tree->SetBranchAddress("Energy_OF", Energy_OF_NFF, &b_NFF_Energy_OF);
   fEvent_NFF_Tree->SetBranchAddress("Time_OF", &Time_OF_NFF, &b_NFF_Time_OF);
   fEvent_NFF_Tree->SetBranchAddress("chi2_OF", chi2_OF_NFF, &b_NFF_chi2_OF);
   fEvent_NFF_Tree->SetBranchAddress("Energy_OF_t0", Energy_OF_t0_NFF, &b_NFF_Energy_OF_t0);
   fEvent_NFF_Tree->SetBranchAddress("Time_OF_t0", &Time_OF_t0_NFF, &b_NFF_Time_OF_t0);
   fEvent_NFF_Tree->SetBranchAddress("chi2_OF_t0", chi2_OF_t0_NFF, &b_NFF_chi2_OF_t0);
   fEvent_NFF_Tree->SetBranchAddress("chi2_NULL", chi2_NULL_NFF, &b_NFF_chi2_NULL);
   fEvent_NFF_Tree->SetBranchAddress("Amp", Amp_NFF, &b_NFF_Amp);
   fEvent_NFF_Tree->SetBranchAddress("RMS", RMS_NFF, &b_NFF_RMS);
   fEvent_NFF_Tree->SetBranchAddress("Off", Off_NFF, &b_NFF_Off);
   fEvent_NFF_Tree->SetBranchAddress("Slope_Ion", Slope_Ion_NFF, &b_NFF_Slope_Ion);
   fEvent_NFF_Tree->SetBranchAddress("index_OF_table", index_OF_table_NFF, &b_NFF_index_OF_table);
   fEvent_NFF_Tree->SetBranchAddress("Energy_OF_table", Energy_OF_table_NFF, &b_NFF_Energy_OF_table);
   fEvent_NFF_Tree->SetBranchAddress("chi2_OF_table", chi2_OF_table_NFF, &b_NFF_chi2_OF_table);
   fEvent_NFF_Tree->SetBranchAddress("Event_Number", &Event_Number, &b_NFF_Event_Number);
   fEvent_NFF_Tree->SetBranchAddress("Event_Owner", &Event_Owner, &b_NFF_Event_Owner);
   fEvent_NFF_Tree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_NFF_Event_bitpattern);
   fEvent_NFF_Tree->SetBranchAddress("MegaStp", &MegaStp, &b_NFF_MegaStp);
   fEvent_NFF_Tree->SetBranchAddress("MicroStp", &MicroStp, &b_NFF_MicroStp);
   fEvent_NFF_Tree->SetBranchAddress("NumRun", &NumRun, &b_NFF_NumRun);
   fEvent_NFF_Tree->SetBranchAddress("NumPart", &NumPart, &b_NFF_NumPart);
   fEvent_NFF_Tree->SetBranchAddress("NameRun", &runNumber, &b_NFF_NameRun);

   processingMethodes.push_back("noise_Fast_filt");
 
   
}

void edwNEPALStreamTreeManager::InitRunTree(TTree *tree)
{
    
   // Set object pointer
   runNumber = 0;
   select_detector = 0;
   TemplateRun = 0;
   TemplateType = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fRunTree = tree;

   fRunTree->SetMakeClass(1);

   fRunTree->SetBranchAddress("BestFitHeat", BestFitHeat, &b_BestFitHeat);
   fRunTree->SetBranchAddress("PSD_Raw", PSD_Raw, &b_PSD_Raw);
   fRunTree->SetBranchAddress("PSD_Filt", PSD_Filt, &b_PSD_Filt);
   fRunTree->SetBranchAddress("PSD_Decor", PSD_Decor, &b_PSD_Decor);
   fRunTree->SetBranchAddress("PSD_Filt_Decor", PSD_Filt_Decor, &b_PSD_Filt_Decor);
   fRunTree->SetBranchAddress("OF_Raw", OF_Raw, &b_OF_Raw);
   fRunTree->SetBranchAddress("OF_Filt", OF_Filt, &b_OF_Filt);
   fRunTree->SetBranchAddress("OF_Decor", OF_Decor, &b_OF_Decor);
   fRunTree->SetBranchAddress("OF_Filt_Decor", OF_Filt_Decor, &b_OF_Filt_Decor);
   fRunTree->SetBranchAddress("Template_Heat_Raw", Template_Heat_Raw, &b_Template_Heat_Raw);
   fRunTree->SetBranchAddress("Template_Heat_Filt", Template_Heat_Filt, &b_Template_Heat_Filt);
   fRunTree->SetBranchAddress("PSD_Freq", PSD_Freq, &b_PSD_Freq);
   fRunTree->SetBranchAddress("OF_resolutions", OF_resolutions, &b_OF_resolutions);
   fRunTree->SetBranchAddress("OF_Filt_resolutions", OF_Filt_resolutions, &b_OF_Filt_resolutions);
   fRunTree->SetBranchAddress("OF_Decor_resolutions", OF_Decor_resolutions, &b_OF_Decor_resolutions);
   fRunTree->SetBranchAddress("OF_Filt_Decor_resolutions", OF_Filt_Decor_resolutions, &b_OF_Filt_Decor_resolutions);
   fRunTree->SetBranchAddress("OF_Window_Low", &OF_Window_Low, &b_OF_Window_Low);
   fRunTree->SetBranchAddress("OF_Window_Up", &OF_Window_Up, &b_OF_Window_Up);
   fRunTree->SetBranchAddress("N_delta", &N_delta, &b_N_delta);
   fRunTree->SetBranchAddress("t0_vector", t0_vector, &b_t0_vector);
   fRunTree->SetBranchAddress("t0_heat_shift", &t0_heat_shift, &b_t0_heat_shift);
   fRunTree->SetBranchAddress("N_Selected_Randoms", &N_Selected_Randoms, &b_N_Selected_Randoms);
   fRunTree->SetBranchAddress("run", &runNumber, &b_run);
   fRunTree->SetBranchAddress("select_detector", &select_detector, &b_select_detector);
   fRunTree->SetBranchAddress("NumRun", &NumRun, &b_NumRun);
   fRunTree->SetBranchAddress("trigger_channel", &trigger_channel, &b_trigger_channel);
   fRunTree->SetBranchAddress("NumPart", &NumPart, &b_NumPart);
   fRunTree->SetBranchAddress("N_samples_Heat", &N_samples_Heat, &b_N_samples_Heat);
   fRunTree->SetBranchAddress("N_samples_Ion", &N_samples_Ion, &b_N_samples_Ion);
   fRunTree->SetBranchAddress("f_max_heat", &f_max_heat, &b_f_max_heat);
   fRunTree->SetBranchAddress("f_max_ion", &f_max_ion, &b_f_max_ion);
   fRunTree->SetBranchAddress("TimeWindow_Heat", &TimeWindow_Heat, &b_TimeWindow_Heat);
   fRunTree->SetBranchAddress("TimeWindow_Ion", &TimeWindow_Ion, &b_TimeWindow_Ion);
   fRunTree->SetBranchAddress("cutoff_freq", &cutoff_freq, &b_cutoff_freq);
   fRunTree->SetBranchAddress("filter_order", &filter_order, &b_filter_order);
   fRunTree->SetBranchAddress("Chan_ON", Chan_ON, &b_Chan_ON);
   fRunTree->SetBranchAddress("Chan_Gain", Chan_Gain, &b_Chan_Gain);
   fRunTree->SetBranchAddress("TemplateRun", &TemplateRun, &b_TemplateRun);
   fRunTree->SetBranchAddress("TemplateType", &TemplateType, &b_TemplateType);
   fRunTree->SetBranchAddress("Rt", &Rt, &b_Rt);
   fRunTree->SetBranchAddress("Date_sec", &Date_sec, &b_Date_sec);
   fRunTree->SetBranchAddress("Date_microsec", &Date_microsec, &b_Date_microsec);
   fRunTree->SetBranchAddress("GigaStamp0", &GigaStamp0, &b_GigaStamp0);
   fRunTree->SetBranchAddress("TimeStamp0", &TimeStamp0, &b_TimeStamp0);
   fRunTree->SetBranchAddress("GigaStampN", &GigaStampN, &b_GigaStampN);
   fRunTree->SetBranchAddress("TimeStampN", &TimeStampN, &b_TimeStampN);
   fRunTree->SetBranchAddress("N_maint_In_part", &N_maint_In_part, &b_N_maint_In_part);
   fRunTree->SetBranchAddress("T_inf_vector", T_inf_vector, &b_T_inf_vector);
   fRunTree->SetBranchAddress("T_sup_vector", T_sup_vector, &b_T_sup_vector);
   fRunTree->SetBranchAddress("MaintenanceCycle", &MaintenanceCycle, &b_MaintenanceCycle);
   fRunTree->SetBranchAddress("MaintenanceDuration", &MaintenanceDuration, &b_MaintenanceDuration);

   fRunTree->GetEntry(0);

}

Int_t edwNEPALStreamTreeManager::GetEntries() {

  int nEntries = fEvent_TR_Tree ? fEvent_TR_Tree->GetEntries() : 0;
  if(fEvent_TF_Tree &&  fEvent_TF_Tree->GetEntries() > nEntries ) nEntries = fEvent_TF_Tree->GetEntries();
  if(fEvent_TFD_Tree &&  fEvent_TFD_Tree->GetEntries() > nEntries ) nEntries = fEvent_TFD_Tree->GetEntries();
  if(fEvent_TFF_Tree &&  fEvent_TFF_Tree->GetEntries() > nEntries ) nEntries = fEvent_TFF_Tree->GetEntries();
  if(fEvent_NR_Tree &&  fEvent_NR_Tree->GetEntries() > nEntries ) nEntries = fEvent_NR_Tree->GetEntries();
  if(fEvent_NF_Tree &&  fEvent_NF_Tree->GetEntries() > nEntries ) nEntries = fEvent_NF_Tree->GetEntries();
  if(fEvent_NFD_Tree &&  fEvent_NFD_Tree->GetEntries() > nEntries ) nEntries = fEvent_NFD_Tree->GetEntries();
  if(fEvent_NFF_Tree &&  fEvent_NFF_Tree->GetEntries() > nEntries ) nEntries = fEvent_NFF_Tree->GetEntries();

  return nEntries;

}

void edwNEPALStreamTreeManager::GetEntry(int ientry) {
  
  if(fEvent_TR_Tree) entryTR_OK = fEvent_TR_Tree->GetEntry(ientry);
  if(fEvent_TF_Tree) entryTF_OK = fEvent_TF_Tree->GetEntry(ientry);
  if(fEvent_TFD_Tree) entryTFD_OK = fEvent_TFD_Tree->GetEntry(ientry);
  if(fEvent_TFF_Tree) entryTFF_OK = fEvent_TFF_Tree->GetEntry(ientry);
  if(fEvent_NR_Tree) entryNR_OK = fEvent_NR_Tree->GetEntry(ientry);
  if(fEvent_NF_Tree) entryNF_OK = fEvent_NF_Tree->GetEntry(ientry);
  if(fEvent_NFD_Tree) entryNFD_OK = fEvent_NFD_Tree->GetEntry(ientry);
  if(fEvent_NFF_Tree) entryNFF_OK = fEvent_NFF_Tree->GetEntry(ientry);
 
}


Bool_t edwNEPALStreamTreeManager::isEntryOK(string s) {
  if(s == "trig_Normal_raw") {
    return entryTR_OK;
  } else if(s == "trig_Normal_filt") {
    return entryTF_OK;
  } else if(s == "trig_Normal_filt_decor") {
    return entryTFD_OK;
  } else if(s == "trig_Fast_filt") {
    return entryTFF_OK;
  } else if(s == "noise_Normal_raw") {
    return entryNR_OK;
  } else if(s == "noise_Normal_filt") {
    return entryNF_OK;
  } else if(s == "noise_Normal_filt_decor") {
    return entryNFD_OK;
  } else if(s == "noise_Fast_filt") {
    return entryNFF_OK;
  } else {
    return false;
  }
}

Int_t edwNEPALStreamTreeManager::getBoloID() {
  string boloName = getBoloName();
  if(boloName == "RED30") {
    return 30;
  } else if(boloName == "CWO") {
    return 521;
  } if(boloName == "RED11") {
    return 11;
  } if(boloName == "RED70") {
    return 70;
  } if(boloName == "RED80") {
    return 80;
  }
  string boloID = boloName.substr(boloName.length()-3,boloName.length());
  return atoi(boloID.c_str());
}

Int_t  edwNEPALStreamTreeManager::getPartitionNb() {
  return NumPart;
}


Double_t edwNEPALStreamTreeManager::getTimeSinceCryorunStart() {
  return 0;
}

Double_t edwNEPALStreamTreeManager::getTimeSinceLastEvent() {
  return 0;
}

Double_t edwNEPALStreamTreeManager::getSambaBoloTemperature() {
  return 0;
}

Int_t edwNEPALStreamTreeManager::getAnaRunNumber() {
  return NumRun;
}

Int_t edwNEPALStreamTreeManager::getEventNb(){
  return Event_Number;
}

Double_t edwNEPALStreamTreeManager::getIonADU(string ch,string shaper, string option){
  
  if(shaper=="fast") {
    return 0;
  }
  int index = 0;
  if(shaper=="slow") {
    index = 2;
  }  else {
     cout << "WARNING  edwNEPALStreamTreeManager::getIonADU unknown " << shaper << " shaper" << endl;
  }

  if(ch=="A") {
    index += 0;
  } else if(ch=="B") {
    index += 1;
  } else if(ch=="C") {
    index += 2;
  } else if(ch=="D") {
    index += 3;
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getIonADU unknown " << ch << " channel" << endl; 
  }

  if(option == "trig_Normal_raw") {
    return Energy_OF_TR[index];
  } else if(option == "trig_Normal_filt") {
    return Energy_OF_TF[index];
  } else if(option == "trig_Normal_filt_decor") {
    return Energy_OF_TFD[index];
  } else if(option == "trig_Fast_filt") {
    return Energy_OF_TFF[index];
  } else if(option == "noise_Normal_raw") {
    return Energy_OF_NR[index];
  } else if(option == "noise_Normal_filt") {
    return Energy_OF_NF[index];
  } else if(option == "noise_Normal_filt_decor") {
    return Energy_OF_NFD[index];
  } else if(option == "noise_Fast_filt") {
    return Energy_OF_NFF[index];
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getIonADU unknown option " << option << endl; 
    return 0.;
  }
}

Double_t edwNEPALStreamTreeManager::getHeatADU(string ch, string option){
  
  int index = 0;
  if(ch=="A") {
    index = 0;
  } else if(ch=="B") {
    index = 1;
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getHeatADU unknown " << ch << " channel" << endl; 
  }

  if(option == "trig_Normal_raw") {
    return Energy_OF_TR[index];
  } else if(option == "trig_Normal_filt") {
    return Energy_OF_TF[index];
  } else if(option == "trig_Normal_filt_decor") {
    return Energy_OF_TFD[index];
  } else if(option == "trig_Fast_filt") {
    return Energy_OF_TFF[index];
  } else if(option == "noise_Normal_raw") {
    return Energy_OF_t0_NR[index];
  } else if(option == "noise_Normal_filt") {
    return Energy_OF_t0_NF[index];
  } else if(option == "noise_Normal_filt_decor") {
    return Energy_OF_t0_NFD[index];
  } else if(option == "noise_Fast_filt") {
    return Energy_OF_t0_NFF[index];
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getHeatADU unknown option " << option << endl; 
    return 0.;
  }

}

Double_t edwNEPALStreamTreeManager::getIonChi2(string ch,string shaper, string option){
  
  if(shaper=="fast") {
    return 0;
  }
  int index = 0;
  if(shaper=="slow") {
    index = 2;
  } else {
     cout << "WARNING  edwNEPALStreamTreeManager::getIonChi2 unknown " << shaper << " shaper" << endl;
  }

  if(ch=="A") {
    index += 0;
  } else if(ch=="B") {
    index += 1;
  } else if(ch=="C") {
    index += 2;
  } else if(ch=="D") {
    index += 3;
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getIonChi2 unknown " << ch << " channel" << endl; 
  }

  if(option == "trig_Normal_raw") {
    return chi2_OF_TR[index];
  } else if(option == "trig_Normal_filt") {
    return chi2_OF_TF[index];
  } else if(option == "trig_Normal_filt_decor") {
    return chi2_OF_TFD[index];
  } else if(option == "trig_Fast_filt") {
    return chi2_OF_TFF[index];
  } else if(option == "noise_Normal_raw") {
    return chi2_OF_NR[index];
  } else if(option == "noise_Normal_filt") {
    return chi2_OF_NF[index];
  } else if(option == "noise_Normal_filt_decor") {
    return chi2_OF_NFD[index];
  } else if(option == "noise_Fast_filt") {
    return chi2_OF_NFF[index];
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getIonChi2 unknown option " << option << endl; 
    return 0.;
  }


}

Double_t edwNEPALStreamTreeManager::getHeatChi2(string ch, string option){
  
  int index = 0;
  if(ch=="A") {
    index = 0;
  } else if(ch=="B") {
    index = 1;
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getHeatChi2 unknown " << ch << " channel" << endl; 
  }


  if(option == "trig_Normal_raw") {
    return chi2_OF_TR[index];
  } else if(option == "trig_Normal_filt") {
    return chi2_OF_TF[index];
  } else if(option == "trig_Normal_filt_decor") {
    return chi2_OF_TFD[index];
  } else if(option == "trig_Fast_filt") {
    return chi2_OF_TFF[index];
  } else if(option == "noise_Normal_raw") {
    return chi2_OF_NR[index];
  } else if(option == "noise_Normal_filt") {
    return chi2_OF_NF[index];
  } else if(option == "noise_Normal_filt_decor") {
    return chi2_OF_NFD[index];
  } else if(option == "noise_Fast_filt") {
    return chi2_OF_NFF[index];
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getHeatChi2 unknown option " << option << endl; 
    return 0.;
  }

}


Double_t edwNEPALStreamTreeManager::getIonResolution(string ch,string shaper, string option){


  if(shaper=="fast") {
    return 0;
  }
  int index = 0;
  if(shaper=="slow") {
    index = 2;
  } else {
     cout << "WARNING  edwNEPALStreamTreeManager::getIonResolution unknown " << shaper << " shaper" << endl;
  }

  if(ch=="A") {
    index += 0;
  } else if(ch=="B") {
    index += 1;
  } else if(ch=="C") {
    index += 2;
  } else if(ch=="D") {
    index += 3;
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getIonResolution unknown " << ch << " channel" << endl; 
  }

  if(option == "trig_Normal_raw") {
    return OF_resolutions[index];
  } else if(option == "trig_Normal_filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "trig_Normal_filt_decor") {
    return OF_Filt_Decor_resolutions[index];
  } else if(option == "trig_Fast_filt") {
    return 0.;//OF_Fast_Filt_resolutions[index];
  } else if(option == "noise_Normal_raw") {
    return OF_resolutions[index];
  } else if(option == "noise_Normal_filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "noise_Normal_filt_decor") {
    return OF_Filt_Decor_resolutions[index];
  } else if(option == "noise_Fast_filt") {
    return 0.;//OF_Fast_Filt_resolutions[index];
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getIonResolution unknown option " << option << endl; 
    return 0.;
  }


}

Double_t edwNEPALStreamTreeManager::getHeatResolution(string ch, string option){

  int index = 0;
  if(ch=="A") {
    index = 0;
  } else if(ch=="B") {
    index = 1;
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getHeatResolution unknown " << ch << " channel" << endl; 
  }

  if(option == "trig_Normal_raw") {
    return OF_resolutions[index];
  } else if(option == "trig_Normal_filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "trig_Normal_filt_decor") {
    return OF_Filt_Decor_resolutions[index];
  } else if(option == "trig_Fast_filt") {
    return 0.;//OF_Fast_Filt_resolutions[index];
  } else if(option == "noise_Normal_raw") {
    return OF_resolutions[index];
  } else if(option == "noise_Normal_filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "noise_Normal_filt_decor") {
    return OF_Filt_Decor_resolutions[index];
  } else if(option == "noise_Fast_filt") {
    return 0.;//OF_Fast_Filt_resolutions[index];
  } else {
    cout << "WARNING edwNEPALStreamTreeManager::getHeatResolution unknown option " << option << endl; 
    return 0.;
  }

}

Bool_t   edwNEPALStreamTreeManager::getIsDecor(string option) {
  return option.find("Decor") != string::npos ;
}
string  edwNEPALStreamTreeManager::getBoloName(){
 return *select_detector;
}


Double_t edwNEPALStreamTreeManager::getHeatThresholdA() {
  return 0.;
}


Double_t edwNEPALStreamTreeManager::getHeatThresholdB() {
  return 0.;
}


Double_t edwNEPALStreamTreeManager::getNormalizedStep() {

  if(Rt==0) return 0.;
  int Reset_value = (int) Rt;  //PB
  return MegaStp%Reset_value + MicroStp*1e-5;

}
