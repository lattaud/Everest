#include "edwResolutionComputer.h"

#include "TH1F.h"
#include "TF1.h"
#include "TCanvas.h"
#include <fstream>
using namespace std;


edwResolutionComputer::edwResolutionComputer() {}

edwResolutionComputer::~edwResolutionComputer() {}



bool edwResolutionComputer::readHeatChi2CutFile(string fileName) {

  ifstream f(fileName.c_str());
  if(!f.is_open()) {
    cout << "edwResolutionComputer::readHeatChi2CutFile file " << fileName << " not found" << endl;
    return false;
  }

  int bolo, startRun, endRun;
  double cutAB, cutAP, cutBB, cutBP, cutAX, cutBX, cutD0, cutD1, cutDX0, cutDX1;
  while(f>>bolo>>startRun>>endRun>>cutAB>>cutAP>>cutBB>>cutBP>>cutAX>>cutBX>>cutD0>>cutD1>>cutDX0>>cutDX1) {
    edwHeatChi2Cut* aHX2C = new edwHeatChi2Cut(startRun, endRun,  cutD0, cutD1,cutAB,cutBB,cutAP,cutBP,cutAX,cutBX,cutDX0,cutDX1);
    fHeatChi2CutMap[bolo].push_back(aHX2C);
  }
  f.close();

  int index = 0;
  for (edwHeatChi2CutMapIterator it=fHeatChi2CutMap.begin(); it!=fHeatChi2CutMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      (*it).second[i]->setIndex(index++);
    }
  }

  return true;

}


bool edwResolutionComputer::readIonChi2CutFile(string fileName) {


  ifstream f(fileName.c_str());
  if(!f.is_open()) {
    cout << "edwResolutionComputer::readIonChi2CutFile file " << fileName << " not found" << endl;
    return false;
  }

  int bolo, startRun, endRun;
  double cutAB, cutAP, cutBB, cutBP, cutCB, cutCP, cutDB, cutDP;
  while(f>>bolo>>startRun>>endRun>>cutAB>>cutAP>>cutBB>>cutBP>>cutCB>>cutCP>>cutDB>>cutDP) {
    edwIonChi2Cut* aIX2C = new edwIonChi2Cut(startRun, endRun,cutAB, cutAP, cutBB, cutBP, cutCB, cutCP, cutDB, cutDP);
    fIonChi2CutMap[bolo].push_back(aIX2C);
  }
  f.close();

  int index = 0;
  for (edwIonChi2CutMapIterator it=fIonChi2CutMap.begin(); it!=fIonChi2CutMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      (*it).second[i]->setIndex(index++);
    }
  }

  return true;

}




bool edwResolutionComputer::readElectrodCutFile(string fileName) {

  ifstream f(fileName.c_str());
  if(!f.is_open()) {
    cout << "edwResolutionComputer::readElectrodCutFile file " << fileName << " not found" << endl;
    return false;
  }

  int bolo, startRun, endRun;
  double cutAB, cutAP, cutCB, cutCP, cutDB, cutDP, cutQB, cutQP, cutQS;
  while(f>>bolo>>startRun>>endRun>>cutAB>>cutAP>>cutCB>>cutCP>>cutDB>>cutDP>>cutQB>>cutQP>>cutQS) {
    edwElectrodCut* aEC = new edwElectrodCut(startRun, endRun,cutAB, cutAP, cutCB, cutCP, cutDB, cutDP, cutQB, cutQP, cutQS);
    fElectrodCutMap[bolo].push_back(aEC);
  }
  f.close();

  int index = 0;
  for (edwElectrodCutMapIterator it=fElectrodCutMap.begin(); it!=fElectrodCutMap.end(); ++it) {
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      (*it).second[i]->setIndex(index++);
    }
  }

  return true;

}


edwHeatChi2Cut* edwResolutionComputer::getHeatChi2Cut(int boloID, int runNumber) {

  for(unsigned int i = 0;i<fHeatChi2CutMap[boloID].size();i++) {
    if(fHeatChi2CutMap[boloID][i]->compareRunNumber(runNumber)) {
      return fHeatChi2CutMap[boloID][i];
    }
  }

  return fHeatChi2CutMap[boloID].back();
}

edwIonChi2Cut* edwResolutionComputer::getIonChi2Cut(int boloID, int runNumber) {

  for(unsigned int i = 0;i<fIonChi2CutMap[boloID].size();i++) {
    if(fIonChi2CutMap[boloID][i]->compareRunNumber(runNumber)) {
      return fIonChi2CutMap[boloID][i];
    }
  }

  return fIonChi2CutMap[boloID].back();
}


edwElectrodCut* edwResolutionComputer::getElectrodCut(int boloID, int runNumber) {

  for(unsigned int i = 0;i<fElectrodCutMap[boloID].size();i++) {
    if(fElectrodCutMap[boloID][i]->compareRunNumber(runNumber)) {
      return fElectrodCutMap[boloID][i];
    }
  }

  return fElectrodCutMap[boloID].back();
}

void edwResolutionComputer::computeResolutions(int boloID) {


  cout << "Compute Resolutions "<< endl;

  vector<string> processingMethodes = fEverestTreeManager->GetProcessingMethods();
  //TH1F * Test_hist = new TH1F("test","test",1000,-2,2);
  int Runnb_accross_loop = 0 ;
  for(int iPM = 0; iPM< processingMethodes.size() ; iPM++) {

    if(processingMethodes[iPM].find("Trig") != string::npos ) continue;
    if(processingMethodes[iPM].find("trig") != string::npos ) continue;

    vector<string> ch;
    ch.push_back("hA");
    ch.push_back("hB");
    ch.push_back("hTot");
    ch.push_back("iA");
    ch.push_back("iB");
    ch.push_back("iC");
    ch.push_back("iD");
    //    ch.push_back("iFid");
    //    ch.push_back("iTot");
    Int_t Nbin_gaussian = 0;
    
    
    
    //fCalibrationManager->getHeatCalibData(runNb,boloID);
    
    map<string,TH1F*> hreso;
    for(int i=0;i<ch.size();i++) {
        string name = "h"+ch[i];
        string title = "resolution "+ch[i];
        hreso[ch[i]] = new TH1F(name.c_str(),title.c_str(),1000,-5,5);
    }
    
    //
    //  Fill
    //

    int nbOfEvent = fEverestTreeManager->GetEntries(processingMethodes[iPM]);
    
    for(int iEv=0; iEv<nbOfEvent;iEv++) {

      //      if(iEv%100==0) cout << "Compute Reso " << processingMethodes[iPM] << " Event " << iEv << "\r" << flush;

      fEverestTreeManager->GetEntry(iEv,processingMethodes[iPM]);
      fCalibrationManager->getNEPALTreeManager()->GetEntry(iEv);
      int runNb = fCalibrationManager->getNEPALTreeManager()->getAnaRunNumber();/*fEverestTreeManager->GetRunNumber();*/
      Runnb_accross_loop = runNb ;

      bool OKChi2 = true;
      int i=0;
      //      cout << "Event " << iEv << endl;
      double volt_ =  fCalibrationManager->getHeatCalibData(runNb,boloID)->getVoltage();
      double E_ = fEverestTreeManager->GetE(ch[i])*(1+fabs(volt_)/3.);
      while(OKChi2 && i<ch.size()) {
      double E;
	if(ch[i]=="hA"||ch[i]=="hB") {
	  double volt =  fCalibrationManager->getHeatCalibData(runNb,boloID)->getVoltage();
	  E = fEverestTreeManager->GetE(ch[i])*(1+fabs(volt)/3.);
	  OKChi2 = getHeatChi2Cut(boloID,runNb)->isChi2OK(fEverestTreeManager->GetNormalizedChi2(ch[i]),
							  E,ch[i]);
	}else if(ch[i]=="hTot"){
	
	   double volt =  fCalibrationManager->getHeatCalibData(runNb,boloID)->getVoltage();
	   E = fEverestTreeManager->GetE(ch[i])*(1+fabs(volt)/3.);
	   Double_t E_A = fEverestTreeManager->GetE("hA")*(1+fabs(volt)/3.);
	   Double_t E_B = fEverestTreeManager->GetE("hB")*(1+fabs(volt)/3.);
	   OKChi2 = getHeatChi2Cut(boloID,runNb)->isChi2OK(fEverestTreeManager->GetNormalizedChi2("hA"),E_A,"hA") && getHeatChi2Cut(boloID,runNb)->isChi2OK(fEverestTreeManager->GetNormalizedChi2("hB"),E_B,"hB");
	
	} else if(ch[i]=="iA"||ch[i]=="iB"||ch[i]=="iC"||ch[i]=="iD") {
	  OKChi2 = getIonChi2Cut(boloID,runNb)->isChi2OK(fEverestTreeManager->GetNormalizedChi2(ch[i]),
							 fEverestTreeManager->GetE(ch[i]),ch[i]);
	}
	
	if(OKChi2) {
     //if(ch[i]=="hA")cout<<"event "<<iEv<<" EhA "<<E<<endl;
     //if(ch[i]=="hB")cout<<"event "<<iEv<<" EhB "<<E<<endl;
	  //if(processingMethodes[iPM] == "noise_Normal_filt_decor") std::cout<< "Event "<<iEv <<" Ephonon "<<E_<<std::endl;
	   hreso[ch[i]]->Fill(E);
	
   }
	
	i++;
   };

     /*   if(ch[0] == "hA" &&  processingMethodes[iPM] == "noise_Normal_filt_decor") std::cout<<E_<<" voltage "<<volt_<<" run "<<runNb<<std::endl;
        Test_hist->Fill(E_);*/
        
      

    }
    
      

    //
    // fit
    //

    for(int i=0;i<ch.size();i++) {
    

      Double_t nEntries = hreso[ch[i]]->GetEntries(); 
      Double_t rms = 0.;
      Double_t par[3];
      
      Double_t hmax, wval;
      if ( nEntries > 1. ) {
	hmax = hreso[ch[i]]->GetMaximum();
	wval = hreso[ch[i]]->GetRMS();
      } else {
	hmax = 1.;
	wval = 1.;
      }

     
      if(wval==0) {
	rms = 0.;
      } else {
  
	TF1 *g1 = new TF1("g1","[0]*exp(-(x-[1])*(x-[1])/[2]/[2]/2.)+[3]*[3]", 0, 2 );
  
	g1->SetParameter(0,hmax);
	g1->SetParameter(1,0.0);
	g1->SetParameter(2,wval);
	g1->SetParameter(3,.0);
	hreso[ch[i]]->Fit("g1","LQ");
	g1->GetParameters(&par[0]);
	rms = par[2];
	fEverestTreeManager->SetReso(ch[i],rms);
	if(i > 2  ) continue ;
      
      bool debugg = false ;
      if(debugg){
          TCanvas* display = new TCanvas("display","display", 800,800);
          hreso[ch[i]]->Draw();      
          display->SaveAs(("debugg"+ch[i]+"_"+processingMethodes[iPM]+"_"+to_string(Runnb_accross_loop)+".pdf").c_str());
	  cout << " rms = " << processingMethodes[iPM] << " " << ch[i] << " resolution " << rms << " Nevents "  << hreso[ch[i]]->GetEntries() << endl;
	  }
      }
  
     
      
      
        
    }
    
    fEverestTreeManager->FillReso(processingMethodes[iPM]);


    // clean
    for(int i=0;i<ch.size();i++) {
      hreso[ch[i]]->Delete();
    }

  } // loop on processingMethodes

}
