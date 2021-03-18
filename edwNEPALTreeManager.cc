#define edwNEPALTreeManager_cxx
#include "edwNEPALTreeManager.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

edwNEPALTreeManager::edwNEPALTreeManager(TFile *f) : fEventTree(0), fRunTree(0)
{

  TTree* tree;

  f->GetObject("EventTree",tree);
  InitEventTree(tree);

  f->GetObject("RunTree",tree);
  InitRunTree(tree);

}
edwNEPALTreeManager::edwNEPALTreeManager(TString name) : edwBaseTreeManager(), fEventTree(0),fileName(name) 
{
  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(fileName.c_str());
  if (!f || !f->IsOpen()) {
    f = new TFile(fileName.c_str());
  }
  TTree* tree;
  f->GetObject("EventTree",tree);
  InitEventTree(tree);

  f->GetObject("RunTree",tree);
  InitRunTree(tree);


}

edwNEPALTreeManager::~edwNEPALTreeManager()
{
}


void edwNEPALTreeManager::InitEventTree(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   NameRun = NULL;
   boloType = NULL;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fEventTree = tree;
   fEventTree->SetMakeClass(1);

   fEventTree->SetBranchAddress("Energy_OF", Energy_OF, &b_Energy_OF);
   fEventTree->SetBranchAddress("Time_OF_Out", &Time_OF_Out, &b_Time_OF_Out);
   fEventTree->SetBranchAddress("chi2_OF", chi2_OF, &b_chi2_OF);
   fEventTree->SetBranchAddress("Energy_OF_NoXPSD", Energy_OF_NoXPSD, &b_Energy_OF_NoXPSD);
   fEventTree->SetBranchAddress("Time_OF_Out_NoXPSD", &Time_OF_Out_NoXPSD, &b_Time_OF_Out_NoXPSD);
   fEventTree->SetBranchAddress("chi2_OF_NoXPSD", chi2_OF_NoXPSD, &b_chi2_OF_NoXPSD);
   fEventTree->SetBranchAddress("Energy_OF_NoXPSD_t0", Energy_OF_NoXPSD_t0, &b_Energy_OF_NoXPSD_t0);
   fEventTree->SetBranchAddress("Time_OF_Out_NoXPSD_t0", &Time_OF_Out_NoXPSD_t0, &b_Time_OF_Out_NoXPSD_t0);
   fEventTree->SetBranchAddress("chi2_OF_NoXPSD_t0", chi2_OF_NoXPSD_t0, &b_chi2_OF_NoXPSD_t0);
   fEventTree->SetBranchAddress("Energy_Heat_NoXPSD", Energy_Heat_NoXPSD, &b_Energy_Heat_NoXPSD);
   fEventTree->SetBranchAddress("Time_Heat_Out_NoXPSD", &Time_Heat_Out_NoXPSD, &b_Time_Heat_Out_NoXPSD);
   fEventTree->SetBranchAddress("chi2_Heat_NoXPSD", chi2_Heat_NoXPSD, &b_chi2_Heat_NoXPSD);
   fEventTree->SetBranchAddress("Energy_Ion_NoXPSD", Energy_Ion_NoXPSD, &b_Energy_Ion_NoXPSD);
   fEventTree->SetBranchAddress("Time_Ion_Out_NoXPSD", &Time_Ion_Out_NoXPSD, &b_Time_Ion_Out_NoXPSD);
   fEventTree->SetBranchAddress("chi2_Ion_NoXPSD", chi2_Ion_NoXPSD, &b_chi2_Ion_NoXPSD);
   fEventTree->SetBranchAddress("chi2_NULL_NoXPSD", chi2_NULL_NoXPSD, &b_chi2_NULL_NoXPSD);
   fEventTree->SetBranchAddress("Energy_OF_NoXPSD_Filt", Energy_OF_NoXPSD_Filt, &b_Energy_OF_NoXPSD_Filt);
   fEventTree->SetBranchAddress("Time_OF_Out_NoXPSD_Filt", &Time_OF_Out_NoXPSD_Filt, &b_Time_OF_Out_NoXPSD_Filt);
   fEventTree->SetBranchAddress("chi2_OF_NoXPSD_Filt", chi2_OF_NoXPSD_Filt, &b_chi2_OF_NoXPSD_Filt);
   fEventTree->SetBranchAddress("Energy_OF_NoXPSD_t0_Filt", Energy_OF_NoXPSD_t0_Filt, &b_Energy_OF_NoXPSD_t0_Filt);
   fEventTree->SetBranchAddress("Time_OF_Out_NoXPSD_t0_Filt", &Time_OF_Out_NoXPSD_t0_Filt, &b_Time_OF_Out_NoXPSD_t0_Filt);
   fEventTree->SetBranchAddress("chi2_OF_NoXPSD_t0_Filt", chi2_OF_NoXPSD_t0_Filt, &b_chi2_OF_NoXPSD_t0_Filt);
   fEventTree->SetBranchAddress("Energy_Heat_NoXPSD_Filt", Energy_Heat_NoXPSD_Filt, &b_Energy_Heat_NoXPSD_Filt);
   fEventTree->SetBranchAddress("Time_Heat_Out_NoXPSD_Filt", &Time_Heat_Out_NoXPSD_Filt, &b_Time_Heat_Out_NoXPSD_Filt);
   fEventTree->SetBranchAddress("chi2_Heat_NoXPSD_Filt", chi2_Heat_NoXPSD_Filt, &b_chi2_Heat_NoXPSD_Filt);
   fEventTree->SetBranchAddress("Energy_Ion_NoXPSD_Filt", Energy_Ion_NoXPSD_Filt, &b_Energy_Ion_NoXPSD_Filt);
   fEventTree->SetBranchAddress("Time_Ion_Out_NoXPSD_Filt", &Time_Ion_Out_NoXPSD_Filt, &b_Time_Ion_Out_NoXPSD_Filt);
   fEventTree->SetBranchAddress("chi2_Ion_NoXPSD_Filt", chi2_Ion_NoXPSD_Filt, &b_chi2_Ion_NoXPSD_Filt);
   fEventTree->SetBranchAddress("chi2_NULL_NoXPSD_Filt", chi2_NULL_NoXPSD_Filt, &b_chi2_NULL_NoXPSD_Filt);
   fEventTree->SetBranchAddress("Amp_preprocess", Amp_preprocess, &b_Amp_preprocess);
   fEventTree->SetBranchAddress("Offset_preprocess", Offset_preprocess, &b_Offset_preprocess);
   fEventTree->SetBranchAddress("Slope_Ion", Slope_Ion, &b_Slope_Ion);

   fEventTree->SetBranchAddress("Event_Number", &Event_Number, &b_Event_Number);
   fEventTree->SetBranchAddress("Event_Owner", &Event_Owner, &b_Event_Owner);
   fEventTree->SetBranchAddress("Event_bitpattern", &Event_bitpattern, &b_Event_bitpattern);
   fEventTree->SetBranchAddress("MegaStp", &MegaStp, &b_MegaStp);
   fEventTree->SetBranchAddress("MicroStp", &MicroStp, &b_MicroStp);
   fEventTree->SetBranchAddress("NameRun", &NameRun, &b_NameRun);
   fEventTree->SetBranchAddress("N_hour", &N_hour, &b_N_hour);
   fEventTree->SetBranchAddress("runAnax", &runAnax, &b_runAnax);
   fEventTree->SetBranchAddress("sambaNPart", &sambaNPart, &b_sambaNPart);
   fEventTree->SetBranchAddress("evtinPart", &evtinPart, &b_evtinPart);
   fEventTree->SetBranchAddress("cryorunV", &cryorunV, &b_cryorunV);
   fEventTree->SetBranchAddress("maxtrigCh", &maxtrigCh, &b_maxtrigCh);
   fEventTree->SetBranchAddress("firstUT", &firstUT, &b_firstUT);
   fEventTree->SetBranchAddress("secondUT", &secondUT, &b_secondUT);
   fEventTree->SetBranchAddress("thirdUT", &thirdUT, &b_thirdUT);
   fEventTree->SetBranchAddress("sinceStartD", &sinceStartD, &b_sinceStartD);
   fEventTree->SetBranchAddress("bitPatChalA", &bitPatChalA, &b_bitPatChalA);
   fEventTree->SetBranchAddress("bitPatChalB", &bitPatChalB, &b_bitPatChalB);
   fEventTree->SetBranchAddress("sinceLastS", &sinceLastS, &b_sinceLastS);
   fEventTree->SetBranchAddress("Tbolo", &Tbolo, &b_Tbolo);
   fEventTree->SetBranchAddress("resetFetS", &resetFetS, &b_resetFetS);
   fEventTree->SetBranchAddress("amplOwnA", &amplOwnA, &b_amplOwnA);
   fEventTree->SetBranchAddress("amplOwnB", &amplOwnB, &b_amplOwnB);
   fEventTree->SetBranchAddress("thtrigA", &thtrigA, &b_thtrigA);
   fEventTree->SetBranchAddress("thtrigB", &thtrigB, &b_thtrigB);
   fEventTree->SetBranchAddress("boloID", &boloID, &b_boloID);
   fEventTree->SetBranchAddress("boloType", &boloType, &b_boloType);

   fEventTree->SetBranchAddress("Enabled_Heat_A",&Enabled_Heat_A,&b_Enabled_Heat_A);
   fEventTree->SetBranchAddress("Enabled_Heat_B",&Enabled_Heat_B,&b_Enabled_Heat_B);
   fEventTree->SetBranchAddress("Enabled_Ion_A",&Enabled_Ion_A,&b_Enabled_Ion_A);
   fEventTree->SetBranchAddress("Enabled_Ion_B",&Enabled_Ion_B,&b_Enabled_Ion_B);
   fEventTree->SetBranchAddress("Enabled_Ion_C",&Enabled_Ion_C,&b_Enabled_Ion_C);
   fEventTree->SetBranchAddress("Enabled_Ion_D",&Enabled_Ion_D,&b_Enabled_Ion_D);
   fEventTree->SetBranchAddress("Enabled_Slow_A",&Enabled_Slow_A,&b_Enabled_Slow_A);
   fEventTree->SetBranchAddress("Enabled_Slow_B",&Enabled_Slow_B,&b_Enabled_Slow_B);
   fEventTree->SetBranchAddress("Enabled_Slow_C",&Enabled_Slow_C,&b_Enabled_Slow_C);
   fEventTree->SetBranchAddress("Enabled_Slow_D",&Enabled_Slow_D,&b_Enabled_Slow_D);



   //get used methods for processing
   if(b_Energy_OF) {
     processingMethodes.push_back("OF");
   }
   if(b_Energy_OF_NoXPSD) {
     processingMethodes.push_back("NoXPSD");
   }
   if(b_Energy_OF_NoXPSD_t0) {
     processingMethodes.push_back("NoXPSD_t0");
   }
   if(b_Energy_OF_NoXPSD_Filt) {
     processingMethodes.push_back("NoXPSD_Filt");
   }
   if(b_Energy_OF_NoXPSD_t0_Filt) {
     processingMethodes.push_back("NoXPSD_t0_Filt");
   }
   if(b_Energy_Ion_NoXPSD&&b_Energy_Heat_NoXPSD) {
     processingMethodes.push_back("IndNoXPSD");
   }
   if(b_Energy_Ion_NoXPSD_Filt&&b_Energy_Heat_NoXPSD_Filt) {
     processingMethodes.push_back("IndNoXPSD_Filt");
   }
 
   
}


void edwNEPALTreeManager::InitRunTree(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   runNumber = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fRunTree = tree;
   fRunTree->SetMakeClass(1);

   fRunTree->SetBranchAddress("HeatParameter_A", HeatParameter_A, &b_HeatParameter_A);
   fRunTree->SetBranchAddress("HeatParameter_B", HeatParameter_B, &b_HeatParameter_B);
   fRunTree->SetBranchAddress("PSD_Heat_A", PSD_Heat_A, &b_PSD_Heat_A);
   fRunTree->SetBranchAddress("PSD_Heat_B", PSD_Heat_B, &b_PSD_Heat_B);
   fRunTree->SetBranchAddress("OF_Heat_A", OF_Heat_A, &b_OF_Heat_A);
   fRunTree->SetBranchAddress("OF_Heat_B", OF_Heat_B, &b_OF_Heat_B);
   fRunTree->SetBranchAddress("Template_Heat_A", Template_Heat_A, &b_Template_Heat_A);
   fRunTree->SetBranchAddress("Template_Heat_B", Template_Heat_B, &b_Template_Heat_B);
   fRunTree->SetBranchAddress("PSD_Heat_Freq", PSD_Heat_Freq, &b_PSD_Heat_Freq);
   fRunTree->SetBranchAddress("PSD_Slow_A", PSD_Slow_A, &b_PSD_Slow_A);
   fRunTree->SetBranchAddress("PSD_Slow_B", PSD_Slow_B, &b_PSD_Slow_B);
   fRunTree->SetBranchAddress("PSD_Slow_C", PSD_Slow_C, &b_PSD_Slow_C);
   fRunTree->SetBranchAddress("PSD_Slow_D", PSD_Slow_D, &b_PSD_Slow_D);
   fRunTree->SetBranchAddress("OF_Slow_A", OF_Slow_A, &b_OF_Slow_A);
   fRunTree->SetBranchAddress("OF_Slow_B", OF_Slow_B, &b_OF_Slow_B);
   fRunTree->SetBranchAddress("OF_Slow_C", OF_Slow_C, &b_OF_Slow_C);
   fRunTree->SetBranchAddress("OF_Slow_D", OF_Slow_D, &b_OF_Slow_D);
   fRunTree->SetBranchAddress("Template_Slow", Template_Slow, &b_Template_Slow);
   fRunTree->SetBranchAddress("PSD_Slow_Freq", PSD_Slow_Freq, &b_PSD_Slow_Freq);
   fRunTree->SetBranchAddress("PSD_Fast_A", PSD_Fast_A, &b_PSD_Fast_A);
   fRunTree->SetBranchAddress("PSD_Fast_B", PSD_Fast_B, &b_PSD_Fast_B);
   fRunTree->SetBranchAddress("PSD_Fast_C", PSD_Fast_C, &b_PSD_Fast_C);
   fRunTree->SetBranchAddress("PSD_Fast_D", PSD_Fast_D, &b_PSD_Fast_D);
   fRunTree->SetBranchAddress("OF_Fast_A", OF_Fast_A, &b_OF_Fast_A);
   fRunTree->SetBranchAddress("OF_Fast_B", OF_Fast_B, &b_OF_Fast_B);
   fRunTree->SetBranchAddress("OF_Fast_C", OF_Fast_C, &b_OF_Fast_C);
   fRunTree->SetBranchAddress("OF_Fast_D", OF_Fast_D, &b_OF_Fast_D);
   fRunTree->SetBranchAddress("Template_Fast", Template_Fast, &b_Template_Fast);
   fRunTree->SetBranchAddress("PSD_Fast_Freq", PSD_Fast_Freq, &b_PSD_Fast_Freq);
   fRunTree->SetBranchAddress("OF_resolutions", OF_resolutions, &b_OF_resolutions);
   fRunTree->SetBranchAddress("OF_Filt_resolutions", OF_Filt_resolutions, &b_OF_Filt_resolutions);
   fRunTree->SetBranchAddress("t0_heat_shift", &t0_heat_shift, &b_t0_heat_shift);
   fRunTree->SetBranchAddress("N_Selected_Randoms", &N_Selected_Randoms, &b_N_Selected_Randoms);
   fRunTree->SetBranchAddress("NameRun", &runNumber, &b_runNumber);
   fRunTree->SetBranchAddress("N_hour", &N_hour_header, &b_N_hour_header);
   
   fRunTree->GetEntry(0);

}

Int_t edwNEPALTreeManager::GetEntries() {
  return fEventTree->GetEntries();
}
void edwNEPALTreeManager::GetEntry(int ientry) {
  fEventTree->GetEntry(ientry);
}

Double_t edwNEPALTreeManager::getHeatAadu() {
  return Energy_OF_NoXPSD_Filt[0];
}
Double_t edwNEPALTreeManager::getHeatBadu() {
  return Energy_OF_NoXPSD_Filt[1];
}
Int_t edwNEPALTreeManager::getBoloID() {
  return boloID;
}

Int_t edwNEPALTreeManager::getPartitionNb() {
  return sambaNPart;
}

Double_t edwNEPALTreeManager::getFastIonAadu(){
  return Energy_OF_NoXPSD_Filt[6];
}
Double_t edwNEPALTreeManager::getFastIonBadu(){
  return Energy_OF_NoXPSD_Filt[7];
}
Double_t edwNEPALTreeManager::getFastIonCadu(){
  return Energy_OF_NoXPSD_Filt[8];
}
Double_t edwNEPALTreeManager::getFastIonDadu(){
  return Energy_OF_NoXPSD_Filt[9];
}

Double_t edwNEPALTreeManager::getSlowIonAadu(){
  return Energy_OF_NoXPSD_Filt[2];
}
Double_t edwNEPALTreeManager::getSlowIonBadu(){
  return Energy_OF_NoXPSD_Filt[3];
}
Double_t edwNEPALTreeManager::getSlowIonCadu(){
  return Energy_OF_NoXPSD_Filt[4];
}
Double_t edwNEPALTreeManager::getSlowIonDadu(){
  return Energy_OF_NoXPSD_Filt[5];
}

Double_t edwNEPALTreeManager::getTimeSinceCryorunStart() {
  return sinceStartD;
}

Double_t edwNEPALTreeManager::getTimeSinceLastEvent() {
  return sinceLastS;
}

Double_t edwNEPALTreeManager::getSambaBoloTemperature() {
  return Tbolo;
}

Int_t    edwNEPALTreeManager::getAnaRunNumber() {
  return runAnax;
}

Int_t edwNEPALTreeManager::getEventNb(){
  return Event_Number;
}


Double_t edwNEPALTreeManager::getIonADU(string ch,string shaper, string option){
  
  int index = 0;
  if(shaper=="slow") {
    index = 2;
  } else if(shaper=="fast") {
    index = 6;
  } else {
     cout << "WARNING  edwNEPALTreeManager::getIonADU unknown " << shaper << " shaper" << endl;
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
    cout << "WARNING edwNEPALTreeManager::getIonADU unknown " << ch << " channel" << endl; 
  }

  if(option == "OF") {
    return Energy_OF[index];
  } else if(option == "NoXPSD") {
    return Energy_OF_NoXPSD[index];
  } else if(option == "NoXPSD_t0") {
    return Energy_OF_NoXPSD_t0[index];
  } else if(option == "NoXPSD_Filt") {
    return Energy_OF_NoXPSD_Filt[index];
  } else if(option == "NoXPSD_t0_Filt") {
    return Energy_OF_NoXPSD_t0_Filt[index];
  } else if(option == "IndNoXPSD") {
    index -= 2;
    return Energy_Ion_NoXPSD[index];
  } else if(option == "IndNoXPSD_Filt") {
    index -= 2;
    return Energy_Ion_NoXPSD_Filt[index];
  } else {
    cout << "WARNING edwNEPALTreeManager::getIonADU unknown option " << option << endl; 
    return 0.;
  }

}

Double_t edwNEPALTreeManager::getHeatADU(string ch, string option){
  
  int index = 0;
  if(ch=="A") {
    index = 0;
  } else if(ch=="B") {
    index = 1;
  } else {
    cout << "WARNING edwNEPALTreeManager::getHeatADU unknown " << ch << " channel" << endl; 
  }

  if(option == "OF") {
    return Energy_OF[index];
  } else if(option == "NoXPSD") {
    return Energy_OF_NoXPSD[index];
  } else if(option == "NoXPSD_t0") {
    return Energy_OF_NoXPSD_t0[index];
  } else if(option == "NoXPSD_Filt") {
    return Energy_OF_NoXPSD_Filt[index];
  } else if(option == "NoXPSD_t0_Filt") {
    return Energy_OF_NoXPSD_t0_Filt[index];
  } else if(option == "IndNoXPSD") {
    return Energy_Heat_NoXPSD[index];
  } else if(option == "IndNoXPSD_Filt") {
    return Energy_Heat_NoXPSD_Filt[index];
  } else {
    cout << "WARNING edwNEPALTreeManager::getHeatADU unknown option " << option << endl; 
    return 0.;
  }

}

Double_t edwNEPALTreeManager::getIonChi2(string ch,string shaper, string option){
  
  int index = 0;
  if(shaper=="slow") {
    index = 2;
  } else if(shaper=="fast") {
    index = 6;
  } else {
     cout << "WARNING  edwNEPALTreeManager::getIonChi2 unknown " << shaper << " shaper" << endl;
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
    cout << "WARNING edwNEPALTreeManager::getIonChi2 unknown " << ch << " channel" << endl; 
  }

  if(option == "OF") {
    return chi2_OF[index];
  } else if(option == "NoXPSD") {
    return chi2_OF_NoXPSD[index];
  } else if(option == "NoXPSD_t0") {
    return chi2_OF_NoXPSD_t0[index];
  } else if(option == "NoXPSD_Filt") {
    return chi2_OF_NoXPSD_Filt[index];
  } else if(option == "NoXPSD_t0_Filt") {
    return chi2_OF_NoXPSD_t0_Filt[index];
  } else if(option == "IndNoXPSD") {
    return chi2_Ion_NoXPSD[index-2];
  } else if(option == "IndNoXPSD_Filt") {
    return chi2_Ion_NoXPSD_Filt[index-2];
  } else {
    cout << "WARNING edwNEPALTreeManager::getIonChi2 unknown option " << option << endl; 
    return 0.;
  }

}

Double_t edwNEPALTreeManager::getHeatChi2(string ch, string option){
  
  int index = 0;
  if(ch=="A") {
    index = 0;
  } else if(ch=="B") {
    index = 1;
  } else {
    cout << "WARNING edwNEPALTreeManager::getHeatChi2 unknown " << ch << " channel" << endl; 
  }

  if(option == "OF") {
    return chi2_OF[index];
  } else if(option == "NoXPSD") {
    return chi2_OF_NoXPSD[index];
  } else if(option == "NoXPSD_t0") {
    return chi2_OF_NoXPSD_t0[index];
  } else if(option == "NoXPSD_Filt") {
    return chi2_OF_NoXPSD_Filt[index];
  } else if(option == "NoXPSD_t0_Filt") {
    return chi2_OF_NoXPSD_t0_Filt[index];
  } else if(option == "IndNoXPSD") {
    return chi2_Heat_NoXPSD[index];
  } else if(option == "IndNoXPSD_Filt") {
    return chi2_Heat_NoXPSD_Filt[index];
  } else {
    cout << "WARNING edwNEPALTreeManager::getHeatChi2 unknown option " << option << endl; 
    return 0.;
  }

}


Double_t edwNEPALTreeManager::getIonResolution(string ch,string shaper, string option){

  int index = 0;
  if(shaper=="slow") {
    index = 2;
  } else if(shaper=="fast") {
    index = 6;
  } else {
     cout << "WARNING  edwNEPALTreeManager::getIonResolution unknown " << shaper << " shaper" << endl;
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
    cout << "WARNING edwNEPALTreeManager::getIonResolution unknown " << ch << " channel" << endl; 
  }

  if(option == "OF") {
    return 0.;
  } else if(option == "NoXPSD") {
    return OF_resolutions[index];
  } else if(option == "NoXPSD_t0") {
    return OF_resolutions[index];
  } else if(option == "NoXPSD_Filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "NoXPSD_t0_Filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "IndNoXPSD") {
    return OF_resolutions[index];
  } else if(option == "IndNoXPSD_Filt") {
    return OF_Filt_resolutions[index];
  } else {
    cout << "WARNING edwNEPALTreeManager::getIonResolution unknown option " << option << endl; 
    return 0.;
  }



}

Double_t edwNEPALTreeManager::getHeatResolution(string ch, string option){

  int index = 0;
  if(ch=="A") {
    index = 0;
  } else if(ch=="B") {
    index = 1;
  } else {
    cout << "WARNING edwNEPALTreeManager::getHeatResolution unknown " << ch << " channel" << endl; 
  }

  if(option == "OF") {
    return 0.;
  } else if(option == "NoXPSD") {
    return OF_resolutions[index];
  } else if(option == "NoXPSD_t0") {
    return OF_resolutions[index];
  } else if(option == "NoXPSD_Filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "NoXPSD_t0_Filt") {
    return OF_Filt_resolutions[index];
  } else if(option == "IndNoXPSD") {
    return OF_resolutions[index];
  } else if(option == "IndNoXPSD_Filt") {
    return OF_Filt_resolutions[index];
  } else {
    cout << "WARNING edwNEPALTreeManager::getHeatResolution unknown option " << option << endl; 
    return 0.;
  }

}

Bool_t   edwNEPALTreeManager::getIsDecor(string option) {
  size_t pos = fileName.find("decor");
//   if(pos==string::npos) {
//     pos = fileName.find("Decorr");
//   }
  string decorString = fileName.substr(pos+5,1);
  if(decorString == "0") {
    return false;
  } else if(decorString == "1") {
    return true;
  } else {
    cout << "edwNEPALTreeManager::getIsDecor ERROR " << fileName << " " << pos << " " << decorString << endl;
    return false;
  }
}
string  edwNEPALTreeManager::getBoloName(){
  string boloName = boloType ? *boloType : "undef";
  ostringstream oss;
  oss << boloID;
  boloName += oss.str();
  return boloName;
}


Double_t edwNEPALTreeManager::getHeatThresholdA() {
  return thtrigA;
}


Double_t edwNEPALTreeManager::getHeatThresholdB() {
  return thtrigB;
}


Double_t edwNEPALTreeManager::getNormalizedStep() {

  int Reset_value = (int) resetFetS;
  return MegaStp%Reset_value + MicroStp*1e-5;

}
