#include "edwRData.h"
#include "edwCalibrationManager.h"
#include <iostream>

using namespace std;


//////////////////////////////////////////////////////
/////// operator<<

ostream& operator<<(ostream& flux, const edwIonCalibData& aICD) {
  flux << aICD.fAnaRunNumber << " " 
       << aICD.fCrossTalkAB <<" "<< aICD.fCrossTalkBA <<" "<< aICD.fCrossTalkCD <<" "<< aICD.fCrossTalkDC <<" "
       << aICD.fCrossTalkAC <<" "<< aICD.fCrossTalkCA <<" "<< aICD.fCrossTalkBD <<" "<< aICD.fCrossTalkDB <<" "
       << aICD.fCrossTalkAD <<" "<< aICD.fCrossTalkDA <<" "<< aICD.fCrossTalkCB <<" "<< aICD.fCrossTalkBC <<endl;
  return flux;

}


ostream& operator<<(ostream& flux, const edwHeatCalibData& aHCD){
  flux << aHCD.fAnaRunNumber <<" " << aHCD.fVoltage << " " << aHCD.fGainA << " " << aHCD.fGainB << " " << aHCD.fHeatTimeDependence << endl;
  return flux;
}


ostream& operator<<(ostream& flux, const edwParamCalibData& aPCD){
  flux << aPCD.fAnaRunNumber << " " <<  aPCD.fFiducialVoltage  << " " << aPCD.fVetoVoltage  << " " << aPCD.fIoniXtalkCutA << " " << aPCD.fIoniXtalkCutB << " " << aPCD.fIoniXtalkCutC << " " << aPCD.fIoniXtalkCutD  << " " << aPCD.fHeatCorrA << " " << aPCD.fHeatCorrB << endl;
  flux << "        ";
  for(int i=0;i<5;i++) flux << aPCD.fNonLinearityA[i] << " ";
  flux << aPCD.fThresholdCorrA << " " << aPCD.fThresholdCorrB << endl;
  flux << "        ";
  for(int i=0;i<5;i++) flux << aPCD.fNonLinearityB[i] << " ";
  flux <<  aPCD.fHeatAweight << " " << aPCD.fIonBweight << endl;
  return flux;
}


ostream& operator<<(ostream& flux, const edwStrucCalibData& aSCD){
  flux << aSCD.fAnaRunNumber << " " << aSCD. fHeatAbitNumber<< " " << aSCD.fHeatBbitNumber << " " << aSCD.fPolarisationMode << endl;
  return flux;
}

ostream& operator<<(ostream& flux, const edwHeatChi2Cut& aHX2C) {
  flux << aHX2C.fStartAnaRunNumber << " " << aHX2C.fEndAnaRunNumber << " " << aHX2C.fDi1 << " " << aHX2C.fDi2 << " " << aHX2C.fBA << " " << aHX2C.fBB
       << " " << aHX2C.fPA << " " << aHX2C.fPB << " " << aHX2C.fXA << " " << aHX2C.fXB <<  aHX2C.fX1 << " " << aHX2C.fX2 << endl;
  return flux;
}


ostream& operator<<(ostream& flux, const edwIonChi2Cut& aIX2C) {
  flux << aIX2C.fStartAnaRunNumber << " " << aIX2C.fEndAnaRunNumber   << " " << aIX2C.fBA   << " " << aIX2C.fBB   << " " << aIX2C.fBC   << " " << aIX2C.fBD  
       << " " << aIX2C.fPA   << " " << aIX2C.fPB   << " " << aIX2C.fPC   << " " << aIX2C.fPD << endl;  
  return flux;
}


ostream& operator<<(ostream& flux, const edwElectrodCut& aEC) {
  flux << aEC.fStartAnaRunNumber << " " << aEC.fEndAnaRunNumber << " " << aEC.fZA << " " << aEC.fZB << " " << aEC.fZC << " " << aEC.fZD 
       << " " << aEC.fPA << " " << aEC.fPB << " " << aEC.fPC << " " << aEC.fPD << " " << aEC.fQslot << endl; 
    return flux;
}


////////////////////////////////////////////////////////
///// edwHeatCalibData


double edwHeatCalibData::getGain(TString ch)   { 
  if(ch=="A") {
    return fGainA;   
  } else if(ch=="B") {
    return fGainB;   
  } else {
    cout << "WARNING edwHeatCalibData::getGain unknown " << ch << " channel" << endl; 
    return 0;
  }
}

////////////////////////////////////////////////////////
///// edwIonCalibData

double edwIonCalibData::getGain(TString ch)   { 
  if(ch=="A") {
    return fGainA;   
  } else if(ch=="B") {
    return fGainB;   
  } else if(ch=="C") {
    return fGainC;   
  } else if(ch=="D") {
    return fGainD;   
  } else {
    cout << "WARNING edwIonCalibData::getGain unknown " << ch << " channel" << endl; 
    return 0;
  }
}

double edwIonCalibData::getCrossTalkXandA(TString X)   { 
  if(X=="A") {
    return -1.;   
  } else if(X=="B") {
    return fCrossTalkBA;   
  } else if(X=="C") {
    return fCrossTalkCA;   
  } else if(X=="D") {
    return fCrossTalkDA;   
  } else {
    cout << "WARNING edwIonCalibData::getCrossTalkXandA unknown " << X << " channel" << endl; 
    return 0;
  }
}


double edwIonCalibData::getCrossTalkXandB(TString X)   { 
  if(X=="A") {
    return fCrossTalkAB;   
  } else if(X=="B") {
    return -1.;   
  } else if(X=="C") {
    return fCrossTalkCB;   
  } else if(X=="D") {
    return fCrossTalkDB;   
  } else {
    cout << "WARNING edwIonCalibData::getCrossTalkXandB unknown " << X << " channel" << endl; 
    return 0;
  }
}

double edwIonCalibData::getCrossTalkXandC(TString X)   { 
  if(X=="A") {
    return fCrossTalkAC;   
  } else if(X=="B") {
    return fCrossTalkBC;   
  } else if(X=="C") {
    return -1.;   
  } else if(X=="D") {
    return fCrossTalkDC;   
  } else {
    cout << "WARNING edwIonCalibData::getCrossTalkXandC unknown " << X << " channel" << endl; 
    return 0;
  }
}

double edwIonCalibData::getCrossTalkXandD(TString X)   { 
  if(X=="A") {
    return fCrossTalkAD;   
  } else if(X=="B") {
    return fCrossTalkBD;   
  } else if(X=="C") {
    return fCrossTalkCD;   
  } else if(X=="D") {
    return -1.;   
  } else {
    cout << "WARNING edwIonCalibData::getCrossTalkXandD unknown " << X << " channel" << endl; 
    return 0;
  }
}

////////////////////////////////////////////////////////
//// edwParamCalibData


double edwParamCalibData::getIoniXtalkCut(TString ch) {
  if(ch=="A") {
    return fIoniXtalkCutA;   
  } else if(ch=="B") {
    return fIoniXtalkCutB;   
  } else if(ch=="C") {
    return fIoniXtalkCutC;   
  } else if(ch=="D") {
    return fIoniXtalkCutD;   
  } else {
    cout << "WARNING edwParamCalibData::getGain unknown " << ch << " channel" << endl; 
    return 0;
  }
}

double edwParamCalibData::getHeatCorr(TString ch) {
  if(ch=="A") {
    return fHeatCorrA;   
  } else if(ch=="B") {
    return fHeatCorrB;   
  } else {
    cout << "WARNING edwParamCalibData::getHeatCorr unknown " << ch << " channel" << endl; 
    return 0;
  }  


}

double edwParamCalibData::getNonLinearity(TString ch, int i){
  if(ch=="A") {
    return fNonLinearityA[i];   
  } else if(ch=="B") {
    return fNonLinearityB[i];   
  } else {
    cout << "WARNING edwHeatCalibData::getNonLinearity unknown " << ch << " channel" << endl; 
    return 0;
  }
}

/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////

edwEnergies::edwEnergies()    {

  energiesOption = "noOption";

  EhAuncorr = 0.;
  EhBuncorr = 0.;
  EhA = 0.;
  EhB = 0.;
  EiA = 0.;
  EiB = 0.;
  EiC = 0.;
  EiD = 0.;
  fastEiA = 0.;
  fastEiB = 0.;
  fastEiC = 0.;
  fastEiD = 0.;

}

edwEnergies::edwEnergies(TString name)   {

  energiesOption = name;

  EhAuncorr = 0.;
  EhBuncorr = 0.;
  EhA = 0.;
  EhB = 0.;
  EiA = 0.;
  EiB = 0.;
  EiC = 0.;
  EiD = 0.;
  fastEiA = 0.;
  fastEiB = 0.;
  fastEiC = 0.;
  fastEiD = 0.;

}

edwEnergies::edwEnergies(TString name, Double_t lha, Double_t lhb, Double_t ha, Double_t hb, Double_t ia, Double_t ib, Double_t ic, Double_t id, Double_t fia, Double_t fib, Double_t fic, Double_t fid) {

  energiesOption = name;


  EhAuncorr = lha;
  EhBuncorr = lhb;
  EhA = ha;
  EhB = hb;
  EiA = ia;
  EiB = ib;
  EiC = ic;
  EiD = id;
  fastEiA = fia;
  fastEiB = fib;
  fastEiC = fic;
  fastEiD = fid;

}

void edwEnergies::dump() {
  cout << "edwEnergies::dump " << energiesOption << "uncorrected heat A: " << EhAuncorr << " B: " << EhBuncorr << "heat A: " << EhA << " B : " << EhB << endl;
  cout << "Ei " << EiA << " " << EiB << " " << EiC << " " <<EiD << endl;
  cout << "fastEi " << fastEiA << " " << fastEiB << " " << fastEiC << " " <<fastEiD << endl;
}


void edwEnergies::computePhysicalVariables(edwIonCalibData* ionCalibData, edwHeatCalibData* heatCalibData, edwParamCalibData* paramCalibData,int polMode) {

  if(polMode==1) {
    Ei = (EiA+EiB+EiC+EiD)/2.;
    EiFIDunweighted = (EiB+EiD)/2.;
    double w = paramCalibData->getIonBweight();
    EiFID = w*EiB + (1-w)*EiD; 
    EiVETO =  (EiA+EiC)/2.;
    EiVETO1 = EiA;
    EiVETO2 = EiC;
  } else if(polMode==2) {
    Ei = (EiA+EiB+EiC+EiD)/2.;
    EiFIDunweighted = Ei;
    EiFID = Ei;
    EiVETO = 0.;
    EiVETO1 = 0.;
    EiVETO2 = 0.;
  } else if(polMode==8) {
    Ei = (EiB+EiD)/2.;
    EiFIDunweighted = Ei;
    EiFID = Ei;
    EiVETO = 0.;
    EiVETO1 = 0.;
    EiVETO2 = 0.;
  } else if(polMode==11) {
      Ei = (EiA+EiB)/2.;
      EiFIDunweighted = Ei;
      EiFID = Ei;
      EiVETO = 0.;
      EiVETO1 = 0.;
      EiVETO2 = 0.;
      
      /*
       EiFid  =  EiB ;
       EiTot =   EiA ;
       EiTop =   EiA ;
       EiBot =   EiB ;
       EiV1 = 0.;
       EiV2 = 0.;
       EiDif = 0.;
       */
      
  }  else if(polMode==12) {
      Ei = (EiA+EiB+EiC+EiD)/2.;
      EiFIDunweighted = (EiA+EiB+EiC+EiD)/2.0;
      EiFID = (EiA+EiB+EiC+EiD)/2.0;
      EiVETO = 0.;
      EiVETO1 = 0.;
      EiVETO2 = 0.;
      
      /*
      EiFid  = ( EiA + EiB + EiC + EiD ) /2.;
      EiTot = ( EiA + EiB + EiC + EiD ) /2.;
      EiTop =   EiA ;
      EiBot =   EiB + EiC + EiD ;
      EiV1 = 0.;
      EiV2 = 0.;
      EiDif = 0.;
      */
      
  } else if(polMode==13) {
    Ei = (EiA+EiB+EiC+EiD)/2.;
    EiFIDunweighted = (EiA+EiB)/2.0;
    EiFID = (EiA+EiB)/2.0;
    EiVETO = (EiC+EiD)/2.0;
    EiVETO1 = EiC;
    EiVETO2 = EiD;
      
    /*
      EiFid =   EiB ;
      EiTot =   EiB + EiD ;
      EiTop =   EiA + EiC ;
      EiBot =   EiB + EiD ;
      EiV1 = EiC;
      EiV2 = EiD;
      EiDif = (EiA-EiB)/2.;
    */
    
  } else if(polMode==14) {
    Ei = (EiA+EiB+EiC+EiD)/2.;
    EiFIDunweighted = (EiB+EiD)/2.0;
    EiFID = (EiB+EiD)/2.0;
    EiVETO = (EiC+EiD)/2.0;
    EiVETO1 = EiA;
    EiVETO2 = EiC;
    
    /*
     EiFid =   ( EiB + EiD ) /2.;
     EiTot =   ( EiA + EiB + EiC + EiD ) / 2. ;
     EiTop =   EiA + EiB ;
     EiBot =   EiC + EiD ;
     EiV1 = EiA;
     EiV2 = EiC;
     EiDif = (EiD-EiB)/2.;
    */
  } else {
    cout << "edwEnergies::computePhysicalVariables ERROR : unknown polarisation mode " << polMode << ". Physics variable not computed" << endl;
    return;
  }
  double w = paramCalibData->getHeatAweight();
  EhUncorr = w*EhAuncorr + (1.-w)*EhBuncorr;
  Eh = w*EhA + (1.-w)*EhB;
  Double_t rk = fabs(heatCalibData->getVoltage()/3.);
  ErFID = (1+rk)*Eh - rk*EiFID;
  Er = (1+rk)*Eh - EiFIDunweighted*rk - EiVETO*paramCalibData->getVetoVoltage()/3.;
  if(ErFID==0) {
    QFID = 0.;
  } else {
    QFID = EiFID/ErFID;
  }
  if(Er==0) {
    Q = 0;
  } else {
    Q = Ei/Er;
  }


}

/////////////////////////////////////////////////////////


edwAmplitudes::edwAmplitudes()    {

  amplitudesOption = "noOption";

  heatA = 0.;
  heatB = 0.;
  ionA = 0.;
  ionB = 0.;
  ionC = 0.;
  ionD = 0.;
  fastIonA = 0.;
  fastIonB = 0.;
  fastIonC = 0.;
  fastIonD = 0.;

}

edwAmplitudes::edwAmplitudes(TString name)   {

  amplitudesOption = name;

  heatA = 0.;
  heatB = 0.;
  ionA = 0.;
  ionB = 0.;
  ionC = 0.;
  ionD = 0.;
  fastIonA = 0.;
  fastIonB = 0.;
  fastIonC = 0.;
  fastIonD = 0.;

}

edwAmplitudes::edwAmplitudes(TString name, Double_t ha, Double_t hb, Double_t ia, Double_t ib, Double_t ic, Double_t id, Double_t fia, Double_t fib, Double_t fic, Double_t fid) {

  amplitudesOption = name;

  heatA = ha;
  heatB = hb;
  ionA = ia;
  ionB = ib;
  ionC = ic;
  ionD = id;
  fastIonA = fia;
  fastIonB = fib;
  fastIonC = fic;
  fastIonD = fid;

}

edwAmplitudes::edwAmplitudes(TString name, Double_t* array) {

  amplitudesOption = name;

  heatA = array[0];
  heatB = array[1];
  ionA = array[2];
  ionB = array[3];
  ionC = array[4];
  ionD = array[5];
  fastIonA = array[6];
  fastIonB = array[7];
  fastIonC = array[8];
  fastIonD = array[9];

}

void edwAmplitudes::dump() {
  cout << "edwAmplitudes::dump " << amplitudesOption << " heat(Chi2) A: " << heatA << "(" <<heatChi2A << ") B: " << heatB << "(" <<heatChi2B << ")" << endl;
  cout << "ion(Chi2) " << ionA << "(" << ionChi2A << ") " << ionB << "(" << ionChi2B << ") " << ionC << "(" << ionChi2C << ") " <<ionD << "(" << ionChi2D << ")" << endl;
  cout << "fastIon(Chi2) " << fastIonA << "(" << fastIonChi2A << ") " << fastIonB << "(" << fastIonChi2B << ") " << fastIonC << "(" << fastIonChi2C << ") " <<fastIonD << "(" << fastIonChi2D << ")" << endl;
}

////////////////////////////////////////////////////////


edwBolometer::~edwBolometer() {
}

void edwBolometer::Reset() {

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

}



void  edwBolometer::dump() {
  cout << "bolo " << boloName << "(" << boloNb << ")" << endl;
  cout << "ionCalibDataIndex " << indexIonCalibData << endl;  
  cout << "heatCalibDataIndex " << indexHeatCalibData << endl;
  cout << "paramCalibDataIndex " << indexParamCalibData << endl;
  cout << "strucCalibDataIndex " << indexStrucCalibData << endl;

  if(AmpOF) {
    cout << "AmpOF ";
    AmpOF->dump();
  }
  if(AmpNoXPSD) {
    cout << "AmpNoXPSD ";
    AmpNoXPSD->dump();
  }
  if(AmpNoXPSD_t0) {
    cout << "AmpNoXPSD_t0 ";
    AmpNoXPSD_t0->dump();
  }
  if(AmpNoXPSD_Filt) {
    cout << "AmpNoXPSD_Filt ";
    AmpNoXPSD_Filt->dump();
  }
  if(AmpNoXPSD_t0_Filt) {
    cout << "AmpNoXPSD_Filt ";
    AmpNoXPSD_t0_Filt->dump();
  }
  if(AmpIndNoXPSD) {
    cout << "AmpIndNoXPSD ";
    AmpIndNoXPSD->dump();
  }
  if(AmpIndNoXPSD_Filt) {
    cout << "AmpIndNoXPSD_Filt ";
    AmpIndNoXPSD_Filt->dump();
  }
  if(Amp_Trig) {
    cout << "Amp_Trig ";
    Amp_Trig->dump();
  }
  if(Amp_Trig_Filt) {
    cout << "Amp_Trig_Filt ";
    Amp_Trig_Filt->dump();
  }
  if(Amp_Trig_Filt_Decor) {
    cout << "Amp_Trig_Filt_Decor ";
    Amp_Trig_Filt_Decor->dump();
  }
  if(Amp_Trig_Fast_Filt) {
    cout << "Amp_Trig_Fast_Filt ";
    Amp_Trig_Fast_Filt->dump();
  }
  if(Amp_Noise) {
    cout << "Amp_Noise ";
    Amp_Noise->dump();
  }
  if(Amp_Noise_Filt) {
    cout << "Amp_Noise_Filt ";
    Amp_Noise_Filt->dump();
  }
  if(Amp_Noise_Filt_Decor) {
    cout << "Amp_Noise_Filt_Decor ";
    Amp_Noise_Filt_Decor->dump();
  }
  if(Amp_Noise_Fast_Filt) {
    cout << "Amp_Noise_Fast_Filt ";
    Amp_Noise_Fast_Filt->dump();
  }


  if(EnerOF) {
    cout << "EnerOF ";
    EnerOF->dump();
  }
  if(EnerNoXPSD) {
    cout << "EnerNoXPSD ";
    EnerNoXPSD->dump();
  }
  if(EnerNoXPSD_t0) {
    cout << "EnerNoXPSD_t0 ";
    EnerNoXPSD_t0->dump();
  }
  if(EnerNoXPSD_Filt) {
    cout << "EnerNoXPSD_Filt ";
    EnerNoXPSD_Filt->dump();
  }
  if(EnerNoXPSD_t0_Filt) {
    cout << "EnerNoXPSD_Filt ";
    EnerNoXPSD_t0_Filt->dump();
  }
  if(EnerIndNoXPSD) {
    cout << "EnerIndNoXPSD ";
    EnerIndNoXPSD->dump();
  }
  if(EnerIndNoXPSD_Filt) {
    cout << "EnerIndNoXPSD_Filt ";
    EnerIndNoXPSD_Filt->dump();
  }
  if(Ener_Trig) {
    cout << "Ener_Trig ";
    Ener_Trig->dump();
  }
  if(Ener_Trig_Filt) {
    cout << "Ener_Trig_Filt ";
    Ener_Trig_Filt->dump();
  }
  if(Ener_Trig_Filt_Decor) {
    cout << "Ener_Trig_Filt_Decor ";
    Ener_Trig_Filt_Decor->dump();
  }
  if(Ener_Trig_Fast_Filt) {
    cout << "Ener_Trig_Fast_Filt ";
    Ener_Trig_Fast_Filt->dump();
  }
  if(Ener_Noise) {
    cout << "Ener_Noise ";
    Ener_Noise->dump();
  }
  if(Ener_Noise_Filt) {
    cout << "Ener_Noise_Filt ";
    Ener_Noise_Filt->dump();
  }
  if(Ener_Noise_Filt_Decor) {
    cout << "Ener_Noise_Filt_Decor ";
    Ener_Noise_Filt_Decor->dump();
  }
  if(Ener_Noise_Fast_Filt) {
    cout << "Ener_Noise_Fast_Filt ";
    Ener_Noise_Fast_Filt->dump();
  }


}

bool edwHeatChi2Cut::isChi2OK(double chi2, double E, string ch) {

  if(ch=="hA") {
    return chi2 < fBA+100*pow(E/fPA,fXA);
  } else if(ch=="hB") {
   return chi2 < fBB+100*pow(E/fPB,fXB);
  } else {
    cout << "pardon! H" << endl;
    return false;
  }


}

bool edwIonChi2Cut::isChi2OK(double chi2, double E, string ch) {

  if(ch.find("iA")!=string::npos) {
    return chi2 < fBA+100*pow(E/fPA,2) && chi2 >= 0.25;
  } else if(ch.find("iB")!=string::npos) {
    return chi2 < fBB+100*pow(E/fPB,2) && chi2 >= 0.25;
  } else if(ch.find("iC")!=string::npos) {
    return chi2 < fBC+100*pow(E/fPC,2) && chi2 >= 0.25;
  } else if(ch.find("iD")!=string::npos) {
    return chi2 < fBD+100*pow(E/fPD,2) && chi2 >= 0.25;
  } else {
    cout << "pardon! I" << endl;
    return false;
  }


}
