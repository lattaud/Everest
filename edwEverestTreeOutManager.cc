#include "edwEverestTreeOutManager.h"


edwEverestTreeOutManager::edwEverestTreeOutManager() {
  fFileName = "noFile";
  fRootFile = NULL;
  fTreeIonCalibData = NULL;
  fTreeHeatCalibData = NULL;
  fTreeParamCalibData = NULL;
  fTreeStrucCalibData = NULL;
  fTreeBoloHeader = NULL;
  fTreeAmplitudesOF = NULL;
  fTreeAmplitudesNoXPSD = NULL;
  fTreeAmplitudesNoXPSD_t0 = NULL;
  fTreeAmplitudesNoXPSD_Filt = NULL;
  fTreeAmplitudesNoXPSD_t0_Filt = NULL;
  fTreeAmplitudesIndNoXPSD = NULL;
  fTreeAmplitudesIndNoXPSD_Filt = NULL;
  fTreeAmplitudes_Trig = NULL;	     
  fTreeAmplitudes_Trig_Filt = NULL;	     
  fTreeAmplitudes_Trig_Filt_Decor = NULL;	     
  fTreeAmplitudes_Trig_Fast_Filt = NULL;	     
  fTreeAmplitudes_Noise = NULL;	     
  fTreeAmplitudes_Noise_Filt = NULL;	     
  fTreeAmplitudes_Noise_Filt_Decor = NULL;	     
  fTreeAmplitudes_Noise_Fast_Filt = NULL;	     
  fTreeEnergiesOF = NULL;
  fTreeEnergiesNoXPSD = NULL;
  fTreeEnergiesNoXPSD_t0 = NULL;
  fTreeEnergiesNoXPSD_Filt = NULL;
  fTreeEnergiesNoXPSD_t0_Filt = NULL;
  fTreeEnergiesIndNoXPSD = NULL;
  fTreeEnergiesIndNoXPSD_Filt = NULL;
  fTreeEnergies_Trig = NULL;	     
  fTreeEnergies_Trig_Filt = NULL;	     
  fTreeEnergies_Trig_Filt_Decor = NULL;	     
  fTreeEnergies_Trig_Fast_Filt = NULL;	     
  fTreeEnergies_Noise = NULL;	     
  fTreeEnergies_Noise_Filt = NULL;	     
  fTreeEnergies_Noise_Filt_Decor = NULL;
  fTreeEnergies_Noise_Fast_Filt = NULL;	     
  fTreeResolutionsOF = NULL;	       	  
  fTreeResolutionsNoXPSD = NULL;	  
  fTreeResolutionsNoXPSD_t0 = NULL;       
  fTreeResolutionsNoXPSD_Filt = NULL;     
  fTreeResolutionsNoXPSD_t0_Filt = NULL;  
  fTreeResolutionsIndNoXPSD = NULL;       
  fTreeResolutionsIndNoXPSD_Filt = NULL;  
  fTreeResolutions_Noise = NULL;	  
  fTreeResolutions_Noise_Filt = NULL;	  
  fTreeResolutions_Noise_Filt_Decor = NULL;
  fTreeResolutions_Noise_Fast_Filt = NULL;	  
  fBolometer = NULL;
}

void edwEverestTreeOutManager::resetBolometer() {

  fBolometer->Reset();
}

edwEverestTreeOutManager::edwEverestTreeOutManager(TString name) {

  fFileName = name;
  fBolometer = new edwBolometer();

  fRootFile = new TFile(name,"RECREATE");

  // calib data trees

  fTreeIonCalibData = new TTree("ionCalibData","ion calib data");
  fTreeIonCalibData->Branch("anaRunNb",&fAnaRunNumber,"anaRun/I");
  fTreeIonCalibData->Branch("boloID",&fBoloID,"boloID/I");
  fTreeIonCalibData->Branch("GainA",&fIonGainA,"gA/D");
  fTreeIonCalibData->Branch("GainB",&fIonGainB,"gB/D");
  fTreeIonCalibData->Branch("GainC",&fIonGainC,"gC/D");
  fTreeIonCalibData->Branch("GainD",&fIonGainD,"gD/D");
  fTreeIonCalibData->Branch("CrossTalkAB",&fCrossTalkAB,"ctAB/D");
  fTreeIonCalibData->Branch("CrossTalkAC",&fCrossTalkAC,"ctAC/D");
  fTreeIonCalibData->Branch("CrossTalkAD",&fCrossTalkAD,"ctAD/D");
  fTreeIonCalibData->Branch("CrossTalkBA",&fCrossTalkBA,"ctBA/D");
  fTreeIonCalibData->Branch("CrossTalkBC",&fCrossTalkBC,"ctBC/D");
  fTreeIonCalibData->Branch("CrossTalkBD",&fCrossTalkBD,"ctBD/D");
  fTreeIonCalibData->Branch("CrossTalkCA",&fCrossTalkCA,"ctCA/D");
  fTreeIonCalibData->Branch("CrossTalkCB",&fCrossTalkCB,"ctCB/D");
  fTreeIonCalibData->Branch("CrossTalkCD",&fCrossTalkCD,"ctCD/D");
  fTreeIonCalibData->Branch("CrossTalkDA",&fCrossTalkDA,"ctDA/D");
  fTreeIonCalibData->Branch("CrossTalkDB",&fCrossTalkDB,"ctDB/D");
  fTreeIonCalibData->Branch("CrossTalkDC",&fCrossTalkDC,"ctDC/D");

  fTreeHeatCalibData = new TTree("heatCalibData","heat calib data");
  fTreeHeatCalibData->Branch("anaRunNb",&fAnaRunNumber,"anaRun/I");
  fTreeHeatCalibData->Branch("boloID",&fBoloID,"boloID/I");
  fTreeHeatCalibData->Branch("Voltage",&fVoltage,"V/D");
  fTreeHeatCalibData->Branch("GainA",&fHeatGainA,"gA/D");
  fTreeHeatCalibData->Branch("GainB",&fHeatGainB,"gB/D");
  fTreeHeatCalibData->Branch("HeatTimeDependence",&fHeatTimeDependence,"timeDep/D");

  fTreeParamCalibData = new TTree("paramCalibData","param calib data");
  fTreeParamCalibData->Branch("anaRunNb",&fAnaRunNumber,"anaRun/I");
  fTreeParamCalibData->Branch("boloID",&fBoloID,"boloID/I");
  fTreeParamCalibData->Branch("FiducialVoltage",&fFiducialVoltage,"fidV/D");
  fTreeParamCalibData->Branch("VetoVoltage",&fVetoVoltage,"vetoV/D");
  fTreeParamCalibData->Branch("IoniXtalkCutA",&fIoniXtalkCutA,"ctCutA/D");
  fTreeParamCalibData->Branch("IoniXtalkCutB",&fIoniXtalkCutB,"ctCutB/D");
  fTreeParamCalibData->Branch("IoniXtalkCutC",&fIoniXtalkCutC,"ctCutC/D");
  fTreeParamCalibData->Branch("IoniXtalkCutD",&fIoniXtalkCutD,"ctCutD/D");
  fTreeParamCalibData->Branch("HeatCorrA",&fHeatCorrA,"hCorrA/D");
  fTreeParamCalibData->Branch("HeatCorrB",&fHeatCorrB,"hCorrB/D");
  fTreeParamCalibData->Branch("NonLinearityA",&fNonLinearityA,"nonLinA[5]/D");
  fTreeParamCalibData->Branch("NonLinearityB",&fNonLinearityB,"nonLinB[5]/D");
  fTreeParamCalibData->Branch("ThresholdCorr",&fThresholdCorrA,"thCorrA/D");
  fTreeParamCalibData->Branch("ThresholdCorr",&fThresholdCorrB,"thCorrB/D");
  fTreeParamCalibData->Branch("fHeatAweight",&fHeatAweight,"hAweight/D");
  fTreeParamCalibData->Branch("fIonBweight",&fIonBweight,"ioBweight/D");

  fTreeStrucCalibData = new TTree("strucCalibData","struc calib data");
  fTreeStrucCalibData->Branch("anaRunNb",&fAnaRunNumber,"anaRun/I");
  fTreeStrucCalibData->Branch("boloID",&fBoloID,"boloID/I");
  fTreeStrucCalibData->Branch("BoloIndexInSamba",&fBoloIndexInSamba,"sambaBoloIndex/I");
  fTreeStrucCalibData->Branch("HeatAbitNumber",&fHeatAbitNumber,"hAbit/I");
  fTreeStrucCalibData->Branch("HeatBbitNumber",&fHeatBbitNumber,"hBBit/I");
  fTreeStrucCalibData->Branch("PolarisationMode",&fPolarisationMode,"polMode/I");

  // bolo header tree

  fTreeBoloHeader = new TTree("boloHeader","bolo header");
  fTreeBoloHeader->Branch("anaRunNb",&fAnaRunNumber,"anaRun/I");
  fTreeBoloHeader->Branch("boloName",&boloName);
  fTreeBoloHeader->Branch("boloNb",&boloNb,"boloNb/I");
  fTreeBoloHeader->Branch("partitionNb",&partitionNb,"partitionNb/I");
  fTreeBoloHeader->Branch("timeFirstDay",&timeFirstDay,"timeFirstDay/D");
  fTreeBoloHeader->Branch("eventNb",&eventNb,"evtNb/I");
  fTreeBoloHeader->Branch("heatThresholdA",&heatThresholdA,"hThA/D");
  fTreeBoloHeader->Branch("heatThresholdB",&heatThresholdB,"hThB/D");
  fTreeBoloHeader->Branch("normalizedStep",&normalizedStep,"normStep/D");
  fTreeBoloHeader->Branch("indexIonCalibData",&indexIonCalibData,"idIonCalibData/I");  
  fTreeBoloHeader->Branch("indexHeatCalibData",&indexHeatCalibData,"idHeatCalibData/I");
  fTreeBoloHeader->Branch("indexParamCalibData",&indexParamCalibData,"idParmaCalibData/I");
  fTreeBoloHeader->Branch("indexStrucCalibData",&indexStrucCalibData,"idStrucCalibData/I");

  // resolution tree

  fTreeResolutionsOF = new TTree("resolutionOF","resolutionOF");
  fTreeResolutionsOF->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutionsOF->Branch("resoHeatB",&resoHeatB,"rHB/D");
  fTreeResolutionsOF->Branch("resoHeatTot",&resoHeatTot,"rH/D");   
  fTreeResolutionsOF->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutionsOF->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutionsOF->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutionsOF->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutionsOF->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutionsOF->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutionsOF->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutionsOF->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutionsNoXPSD = new TTree("resolutionNoXPSD","resolutionNoXPSD");
  fTreeResolutionsNoXPSD->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutionsNoXPSD->Branch("resoHeatB",&resoHeatB,"rHB/D");  
  fTreeResolutionsNoXPSD->Branch("resoHeatTot",&resoHeatTot,"rH/D");    
  fTreeResolutionsNoXPSD->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutionsNoXPSD->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutionsNoXPSD->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutionsNoXPSD->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutionsNoXPSD->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutionsNoXPSD->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutionsNoXPSD->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutionsNoXPSD->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutionsNoXPSD_t0 = new TTree("resolutionNoXPSD_t0","resolutionNoXPSD_t0");
  fTreeResolutionsNoXPSD_t0->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutionsNoXPSD_t0->Branch("resoHeatB",&resoHeatB,"rHB/D");
  fTreeResolutionsNoXPSD_t0->Branch("resoHeatTot",&resoHeatTot,"rH/D");   
  fTreeResolutionsNoXPSD_t0->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutionsNoXPSD_t0->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutionsNoXPSD_t0->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutionsNoXPSD_t0->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutionsNoXPSD_t0->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutionsNoXPSD_t0->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutionsNoXPSD_t0->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutionsNoXPSD_t0->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutionsNoXPSD_Filt = new TTree("resolutionNoXPSD_Filt","resolutionNoXPSD_Filt");
  fTreeResolutionsNoXPSD_Filt->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutionsNoXPSD_Filt->Branch("resoHeatB",&resoHeatB,"rHB/D"); 
  fTreeResolutionsNoXPSD_Filt->Branch("resoHeatTot",&resoHeatTot,"rH/D");  
  fTreeResolutionsNoXPSD_Filt->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutionsNoXPSD_Filt->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutionsNoXPSD_Filt->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutionsNoXPSD_Filt->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutionsNoXPSD_Filt->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutionsNoXPSD_Filt->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutionsNoXPSD_Filt->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutionsNoXPSD_Filt->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutionsNoXPSD_t0_Filt = new TTree("resolutionNoXPSD_t0_Filt","resolutionNoXPSD_t0_Filt");
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoHeatB",&resoHeatB,"rHB/D"); 
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoHeatTot",&resoHeatTot,"rH/D");    
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutionsNoXPSD_t0_Filt->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutionsIndNoXPSD = new TTree("resolutionIndNoXPSD","resolutionIndNoXPSD");
  fTreeResolutionsIndNoXPSD->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutionsIndNoXPSD->Branch("resoHeatB",&resoHeatB,"rHB/D"); 
  fTreeResolutionsIndNoXPSD->Branch("resoHeatTot",&resoHeatTot,"rH/D");    
  fTreeResolutionsIndNoXPSD->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutionsIndNoXPSD->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutionsIndNoXPSD->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutionsIndNoXPSD->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutionsIndNoXPSD->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutionsIndNoXPSD->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutionsIndNoXPSD->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutionsIndNoXPSD->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutionsIndNoXPSD_Filt = new TTree("resolutionIndNoXPSD_Filt","resolutionIndNoXPSD_Filt");
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoHeatB",&resoHeatB,"rHB/D"); 
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoHeatTot",&resoHeatTot,"rH/D");    
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutionsIndNoXPSD_Filt->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutions_Noise = new TTree("resolution_Noise","resolution_Noise");
  fTreeResolutions_Noise->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutions_Noise->Branch("resoHeatB",&resoHeatB,"rHB/D"); 
  fTreeResolutions_Noise->Branch("resoHeatTot",&resoHeatTot,"rH/D");    
  fTreeResolutions_Noise->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutions_Noise->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutions_Noise->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutions_Noise->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutions_Noise->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutions_Noise->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutions_Noise->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutions_Noise->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutions_Noise_Filt = new TTree("resolution_Noise_Filt","resolution_Noise_Filt");
  fTreeResolutions_Noise_Filt->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutions_Noise_Filt->Branch("resoHeatB",&resoHeatB,"rHB/D"); 
  fTreeResolutions_Noise_Filt->Branch("resoHeatTot",&resoHeatTot,"rH/D");    
  fTreeResolutions_Noise_Filt->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutions_Noise_Filt->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutions_Noise_Filt->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutions_Noise_Filt->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutions_Noise_Filt->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutions_Noise_Filt->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutions_Noise_Filt->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutions_Noise_Filt->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutions_Noise_Filt_Decor = new TTree("resolution_Noise_Filt_Decor","resolution_Noise_Filt_Decor");
  fTreeResolutions_Noise_Filt_Decor->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutions_Noise_Filt_Decor->Branch("resoHeatB",&resoHeatB,"rHB/D");  
  fTreeResolutions_Noise_Filt_Decor->Branch("resoHeatTot",&resoHeatTot,"rH/D");   
  fTreeResolutions_Noise_Filt_Decor->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutions_Noise_Filt_Decor->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutions_Noise_Filt_Decor->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutions_Noise_Filt_Decor->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutions_Noise_Filt_Decor->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutions_Noise_Filt_Decor->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutions_Noise_Filt_Decor->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutions_Noise_Filt_Decor->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  fTreeResolutions_Noise_Fast_Filt = new TTree("resolution_Noise_Fast_Filt","resolution_Noise_Fast_Filt");
  fTreeResolutions_Noise_Fast_Filt->Branch("resoHeatA",&resoHeatA,"rHA/D");   
  fTreeResolutions_Noise_Fast_Filt->Branch("resoHeatB",&resoHeatB,"rHB/D"); 
  fTreeResolutions_Noise_Fast_Filt->Branch("resoHeatTot",&resoHeatTot,"rH/D");    
  fTreeResolutions_Noise_Fast_Filt->Branch("resoIonA",&resoIonA,"rIA/D");    
  fTreeResolutions_Noise_Fast_Filt->Branch("resoIonB",&resoIonB,"rIA/D");    
  fTreeResolutions_Noise_Fast_Filt->Branch("resoIonC",&resoIonC,"rIA/D");    
  fTreeResolutions_Noise_Fast_Filt->Branch("resoIonD",&resoIonD,"rIA/D");    
  fTreeResolutions_Noise_Fast_Filt->Branch("resoFastIonA",&resoFastIonA,"rFIA/D");
  fTreeResolutions_Noise_Fast_Filt->Branch("resoFastIonB",&resoFastIonB,"rFIA/D");
  fTreeResolutions_Noise_Fast_Filt->Branch("resoFastIonC",&resoFastIonC,"rFIA/D");
  fTreeResolutions_Noise_Fast_Filt->Branch("resoFastIonD",&resoFastIonD,"rFIA/D");

  // Amplitudes Trees
    
  fTreeAmplitudesOF = new TTree("AmplitudesOF","amplitudes OF");
  fTreeAmplitudesOF->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudesOF->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudesOF->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudesOF->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudesOF->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudesOF->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudesOF->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudesOF->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudesOF->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudesOF->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudesOF->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudesOF->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudesOF->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudesOF->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudesOF->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudesOF->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudesOF->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudesOF->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudesOF->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudesOF->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudesOF->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudesOF->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudesOF->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudesOF->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudesOF->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudesOF->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudesOF->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudesOF->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudesOF->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudesOF->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudesOF->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudesNoXPSD = new TTree("AmplitudesNoXPSD","amplitudes NoXPSD");
  fTreeAmplitudesNoXPSD->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudesNoXPSD->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudesNoXPSD->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudesNoXPSD->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudesNoXPSD->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudesNoXPSD->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudesNoXPSD->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudesNoXPSD->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudesNoXPSD->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudesNoXPSD->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudesNoXPSD->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudesNoXPSD->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudesNoXPSD->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudesNoXPSD->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudesNoXPSD->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudesNoXPSD->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudesNoXPSD->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudesNoXPSD->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudesNoXPSD->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudesNoXPSD->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudesNoXPSD->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudesNoXPSD->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudesNoXPSD->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudesNoXPSD->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudesNoXPSD->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudesNoXPSD->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudesNoXPSD->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudesNoXPSD->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudesNoXPSD->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudesNoXPSD->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudesNoXPSD->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudesNoXPSD_t0 = new TTree("AmplitudesNoXPSD_t0","amplitudes NoXPSD_t0");
  fTreeAmplitudesNoXPSD_t0->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudesNoXPSD_t0->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudesNoXPSD_t0->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudesNoXPSD_t0->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudesNoXPSD_t0->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudesNoXPSD_t0->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudesNoXPSD_t0->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudesNoXPSD_t0->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudesNoXPSD_t0->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudesNoXPSD_t0->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudesNoXPSD_t0->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudesNoXPSD_t0->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudesNoXPSD_t0->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudesNoXPSD_Filt = new TTree("AmplitudesNoXPSD_Filt","amplitudes NoXPSD_Filt");
  fTreeAmplitudesNoXPSD_Filt->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudesNoXPSD_Filt->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudesNoXPSD_Filt->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudesNoXPSD_Filt->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudesNoXPSD_Filt->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudesNoXPSD_Filt->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudesNoXPSD_Filt->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudesNoXPSD_Filt->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudesNoXPSD_Filt->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudesNoXPSD_Filt->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudesNoXPSD_Filt->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudesNoXPSD_t0_Filt = new TTree("AmplitudesNoXPSD_t0_Filt","amplitudes NoXPSD_t0_Filt");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudesNoXPSD_t0_Filt->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudesIndNoXPSD = new TTree("AmplitudesIndNoXPSD","amplitudes IndNoXPSD");
  fTreeAmplitudesIndNoXPSD->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudesIndNoXPSD->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudesIndNoXPSD->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudesIndNoXPSD->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudesIndNoXPSD->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudesIndNoXPSD->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudesIndNoXPSD->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudesIndNoXPSD->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudesIndNoXPSD->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudesIndNoXPSD->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudesIndNoXPSD->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudesIndNoXPSD->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudesIndNoXPSD->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudesIndNoXPSD->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudesIndNoXPSD->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudesIndNoXPSD->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudesIndNoXPSD->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudesIndNoXPSD->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudesIndNoXPSD->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudesIndNoXPSD->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudesIndNoXPSD->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudesIndNoXPSD->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudesIndNoXPSD->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudesIndNoXPSD->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudesIndNoXPSD->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudesIndNoXPSD->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudesIndNoXPSD->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudesIndNoXPSD->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudesIndNoXPSD->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudesIndNoXPSD->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudesIndNoXPSD->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudesIndNoXPSD_Filt = new TTree("AmplitudesIndNoXPSD_Filt","amplitudes IndNoXPSD_Filt");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudesIndNoXPSD_Filt->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudesIndNoXPSD_Filt->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudesIndNoXPSD_Filt->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudesIndNoXPSD_Filt->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Trig = new TTree("Amplitudes_Trig","amplitudes IndNoXPSD_Filt");
  fTreeAmplitudes_Trig->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Trig->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Trig->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Trig->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Trig->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Trig->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Trig->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Trig->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Trig->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Trig->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Trig->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Trig->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Trig->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Trig->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Trig->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Trig->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Trig->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Trig->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Trig->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Trig->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Trig->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Trig->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Trig->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Trig->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Trig->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Trig->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Trig->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Trig->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Trig->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Trig->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Trig->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Trig_Filt = new TTree("Amplitudes_Trig_Filt","amplitudes IndNoXPSD_Filt");
  fTreeAmplitudes_Trig_Filt->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Trig_Filt->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Trig_Filt->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Trig_Filt->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Trig_Filt->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Trig_Filt->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Trig_Filt->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Trig_Filt->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Trig_Filt->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Trig_Filt->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Trig_Filt->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Trig_Filt->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Trig_Filt->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Trig_Filt->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Trig_Filt->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Trig_Filt->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Trig_Filt->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Trig_Filt->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Trig_Filt->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Trig_Filt->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Trig_Filt->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Trig_Filt->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Trig_Filt->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Trig_Filt->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Trig_Filt->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Trig_Filt->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Trig_Filt->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Trig_Filt->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Trig_Filt->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Trig_Filt->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Trig_Filt->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Trig_Filt_Decor = new TTree("Amplitudes_Trig_Filt_Decor","amplitudes IndNoXPSD_Filt");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Trig_Filt_Decor->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Trig_Filt_Decor->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Trig_Filt_Decor->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Trig_Filt_Decor->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Trig_Fast_Filt = new TTree("Amplitudes_Trig_Fast_Filt","amplitudes IndNoXPSD_Fast_Filt");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Trig_Fast_Filt->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Trig_Fast_Filt->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Trig_Fast_Filt->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Trig_Fast_Filt->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Noise = new TTree("Amplitudes_Noise","amplitudes IndNoXPSD_Filt");
  fTreeAmplitudes_Noise->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Noise->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Noise->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Noise->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Noise->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Noise->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Noise->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Noise->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Noise->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Noise->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Noise->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Noise->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Noise->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Noise->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Noise->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Noise->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Noise->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Noise->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Noise->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Noise->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Noise->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Noise->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Noise->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Noise->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Noise->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Noise->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Noise->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Noise->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Noise->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Noise->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Noise->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Noise_Filt = new TTree("Amplitudes_Noise_Filt","amplitudes IndNoXPSD_Filt");
  fTreeAmplitudes_Noise_Filt->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Noise_Filt->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Noise_Filt->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Noise_Filt->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Noise_Filt->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Noise_Filt->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Noise_Filt->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Noise_Filt->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Noise_Filt->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Noise_Filt->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Noise_Filt->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Noise_Filt->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Noise_Filt->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Noise_Filt->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Noise_Filt->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Noise_Filt->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Noise_Filt->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Noise_Filt->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Noise_Filt->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Noise_Filt->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Noise_Filt->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Noise_Filt->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Noise_Filt->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Noise_Filt->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Noise_Filt->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Noise_Filt->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Noise_Filt->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Noise_Filt->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Noise_Filt->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Noise_Filt->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Noise_Filt->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Noise_Filt_Decor = new TTree("Amplitudes_Noise_Filt_Decor","amplitudes IndNoXPSD_Filt");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Noise_Filt_Decor->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Noise_Filt_Decor->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Noise_Filt_Decor->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Noise_Filt_Decor->Branch("isDecorr",&isDecorr,"isDecor/B");

  fTreeAmplitudes_Noise_Fast_Filt = new TTree("Amplitudes_Noise_Fast_Filt","amplitudes IndNoXPSD_Fast_Filt");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("heatA",&heatA,"hA/D");	     
  fTreeAmplitudes_Noise_Fast_Filt->Branch("heatB",&heatB,"hB/D");	     
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionA",&ionA,"iA/D");	     
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionB",&ionB,"iB/D");	     
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionC",&ionC,"iC/D");	     
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionD",&ionD,"iD/D");	     
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonA",&fastIonA,"fiA/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonB",&fastIonB,"fiB/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonC",&fastIonC,"fiC/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonD",&fastIonD,"fiD/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("heatChi2A",&heatChi2A,"hAchi2/D");  
  fTreeAmplitudes_Noise_Fast_Filt->Branch("heatChi2B",&heatChi2B,"hBchi2/D");  
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionChi2A",&ionChi2A,"iAchi2/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionChi2B",&ionChi2B,"iBchi2/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionChi2C",&ionChi2C,"iCchi2/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionChi2D",&ionChi2D,"iDchi2/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonChi2A",&fastIonChi2A,"fiAchi2/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonChi2B",&fastIonChi2B,"fiBchi2/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonChi2C",&fastIonChi2C,"fiCchi2/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonChi2D",&fastIonChi2D,"fiDchi2/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("heatResoA",&heatResoA,"hAreso/D");  
  fTreeAmplitudes_Noise_Fast_Filt->Branch("heatResoB",&heatResoB,"hBreso/D");  
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionResoA",&ionResoA,"iAreso/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionResoB",&ionResoB,"iBreso/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionResoC",&ionResoC,"iCreso/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("ionResoD",&ionResoD,"iDreso/D");   
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonAReso",&fastIonAReso,"fiAreso/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonBReso",&fastIonBReso,"fiBreso/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonCReso",&fastIonCReso,"fiCreso/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("fastIonDReso",&fastIonDReso,"fiDreso/D");
  fTreeAmplitudes_Noise_Fast_Filt->Branch("isDecorr",&isDecorr,"isDecor/B");

  // Energies tree

  fTreeEnergiesOF = new TTree("EnergiesOF","energies OF");
  fTreeEnergiesOF->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergiesOF->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergiesOF->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergiesOF->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergiesOF->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergiesOF->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergiesOF->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergiesOF->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergiesOF->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergiesOF->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergiesOF->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergiesOF->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergiesOF->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergiesOF->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergiesOF->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergiesOF->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergiesOF->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergiesOF->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergiesOF->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergiesOF->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergiesOF->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergiesOF->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergiesOF->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergiesOF->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergiesOF->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergiesOF->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergiesOF->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergiesOF->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergiesOF->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergiesOF->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergiesOF->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergiesOF->Branch("Er",&Er,"Er/D");
  fTreeEnergiesOF->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergiesOF->Branch("Q",&Q,"Q/D");

  fTreeEnergiesNoXPSD = new TTree("EnergiesNoXPSD","energies NoXPSD");
  fTreeEnergiesNoXPSD->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergiesNoXPSD->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergiesNoXPSD->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergiesNoXPSD->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergiesNoXPSD->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergiesNoXPSD->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergiesNoXPSD->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergiesNoXPSD->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergiesNoXPSD->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergiesNoXPSD->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergiesNoXPSD->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergiesNoXPSD->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergiesNoXPSD->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergiesNoXPSD->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergiesNoXPSD->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergiesNoXPSD->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergiesNoXPSD->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergiesNoXPSD->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergiesNoXPSD->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergiesNoXPSD->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergiesNoXPSD->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergiesNoXPSD->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergiesNoXPSD->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergiesNoXPSD->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergiesNoXPSD->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergiesNoXPSD->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergiesNoXPSD->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergiesNoXPSD->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergiesNoXPSD->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergiesNoXPSD->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergiesNoXPSD->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergiesNoXPSD->Branch("Er",&Er,"Er/D");
  fTreeEnergiesNoXPSD->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergiesNoXPSD->Branch("Q",&Q,"Q/D");

  fTreeEnergiesNoXPSD_t0 = new TTree("EnergiesNoXPSD_t0","energies NoXPSD_t0");
  fTreeEnergiesNoXPSD_t0->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergiesNoXPSD_t0->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergiesNoXPSD_t0->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergiesNoXPSD_t0->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergiesNoXPSD_t0->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergiesNoXPSD_t0->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergiesNoXPSD_t0->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergiesNoXPSD_t0->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergiesNoXPSD_t0->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergiesNoXPSD_t0->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergiesNoXPSD_t0->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergiesNoXPSD_t0->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergiesNoXPSD_t0->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergiesNoXPSD_t0->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergiesNoXPSD_t0->Branch("Er",&Er,"Er/D");
  fTreeEnergiesNoXPSD_t0->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergiesNoXPSD_t0->Branch("Q",&Q,"Q/D");

  fTreeEnergiesNoXPSD_Filt = new TTree("EnergiesNoXPSD_Filt","energies NoXPSD_Filt");
  fTreeEnergiesNoXPSD_Filt->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergiesNoXPSD_Filt->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergiesNoXPSD_Filt->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergiesNoXPSD_Filt->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergiesNoXPSD_Filt->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergiesNoXPSD_Filt->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergiesNoXPSD_Filt->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergiesNoXPSD_Filt->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergiesNoXPSD_Filt->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergiesNoXPSD_Filt->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergiesNoXPSD_Filt->Branch("Er",&Er,"Er/D");
  fTreeEnergiesNoXPSD_Filt->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergiesNoXPSD_Filt->Branch("Q",&Q,"Q/D");

  fTreeEnergiesNoXPSD_t0_Filt = new TTree("EnergiesNoXPSD_t0_Filt","energies NoXPSD_t0_Filt");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("Er",&Er,"Er/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergiesNoXPSD_t0_Filt->Branch("Q",&Q,"Q/D");

  fTreeEnergiesIndNoXPSD = new TTree("EnergiesIndNoXPSD","energies IndNoXPSD");
  fTreeEnergiesIndNoXPSD->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergiesIndNoXPSD->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergiesIndNoXPSD->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergiesIndNoXPSD->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergiesIndNoXPSD->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergiesIndNoXPSD->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergiesIndNoXPSD->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergiesIndNoXPSD->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergiesIndNoXPSD->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergiesIndNoXPSD->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergiesIndNoXPSD->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergiesIndNoXPSD->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergiesIndNoXPSD->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergiesIndNoXPSD->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergiesIndNoXPSD->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergiesIndNoXPSD->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergiesIndNoXPSD->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergiesIndNoXPSD->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergiesIndNoXPSD->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergiesIndNoXPSD->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergiesIndNoXPSD->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergiesIndNoXPSD->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergiesIndNoXPSD->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergiesIndNoXPSD->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergiesIndNoXPSD->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergiesIndNoXPSD->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergiesIndNoXPSD->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergiesIndNoXPSD->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergiesIndNoXPSD->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergiesIndNoXPSD->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergiesIndNoXPSD->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergiesIndNoXPSD->Branch("Er",&Er,"Er/D");
  fTreeEnergiesIndNoXPSD->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergiesIndNoXPSD->Branch("Q",&Q,"Q/D");

  fTreeEnergiesIndNoXPSD_Filt = new TTree("EnergiesIndNoXPSD_Filt","energiesInd NoXPSD_Filt");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("Er",&Er,"Er/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergiesIndNoXPSD_Filt->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Trig = new TTree("Energies_Trig","energiesInd NoXPSD_Filt");
  fTreeEnergies_Trig->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Trig->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Trig->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Trig->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Trig->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Trig->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Trig->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Trig->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Trig->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Trig->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Trig->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Trig->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Trig->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Trig->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Trig->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Trig->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Trig->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Trig->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Trig->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Trig->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Trig->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Trig->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Trig->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Trig->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Trig->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Trig->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Trig->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Trig->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Trig->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Trig->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Trig->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Trig->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Trig->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Trig->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Trig_Filt = new TTree("Energies_Trig_Filt","energiesInd NoXPSD_Filt");
  fTreeEnergies_Trig_Filt->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Trig_Filt->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Trig_Filt->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Trig_Filt->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Trig_Filt->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Trig_Filt->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Trig_Filt->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Trig_Filt->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Trig_Filt->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Trig_Filt->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Trig_Filt->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Trig_Filt->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Trig_Filt->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Trig_Filt->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Trig_Filt->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Trig_Filt->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Trig_Filt->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Trig_Filt->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Trig_Filt->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Trig_Filt->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Trig_Filt->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Trig_Filt->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Trig_Filt->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Trig_Filt->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Trig_Filt->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Trig_Filt->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Trig_Filt->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Trig_Filt->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Trig_Filt->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Trig_Filt->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Trig_Filt->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Trig_Filt->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Trig_Filt->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Trig_Filt->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Trig_Filt_Decor = new TTree("Energies_Trig_Filt_Decor","energiesInd NoXPSD_Filt");
  fTreeEnergies_Trig_Filt_Decor->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Trig_Filt_Decor->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Trig_Fast_Filt = new TTree("Energies_Trig_Fast_Filt","energiesInd NoXPSD_Fast_Filt");
  fTreeEnergies_Trig_Fast_Filt->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Trig_Fast_Filt->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Noise = new TTree("Energies_Noise","energiesInd NoXPSD_Filt");
  fTreeEnergies_Noise->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Noise->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Noise->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Noise->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Noise->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Noise->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Noise->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Noise->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Noise->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Noise->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Noise->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Noise->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Noise->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Noise->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Noise->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Noise->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Noise->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Noise->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Noise->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Noise->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Noise->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Noise->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Noise->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Noise->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Noise->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Noise->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Noise->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Noise->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Noise->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Noise->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Noise->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Noise->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Noise->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Noise->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Noise_Filt = new TTree("Energies_Noise_Filt","energiesInd NoXPSD_Filt");
  fTreeEnergies_Noise_Filt->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Noise_Filt->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Noise_Filt->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Noise_Filt->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Noise_Filt->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Noise_Filt->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Noise_Filt->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Noise_Filt->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Noise_Filt->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Noise_Filt->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Noise_Filt->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Noise_Filt->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Noise_Filt->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Noise_Filt->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Noise_Filt->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Noise_Filt->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Noise_Filt->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Noise_Filt->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Noise_Filt->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Noise_Filt->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Noise_Filt->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Noise_Filt->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Noise_Filt->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Noise_Filt->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Noise_Filt->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Noise_Filt->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Noise_Filt->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Noise_Filt->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Noise_Filt->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Noise_Filt->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Noise_Filt->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Noise_Filt->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Noise_Filt->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Noise_Filt->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Noise_Filt_Decor = new TTree("Energies_Noise_Filt_Decor","energiesInd NoXPSD_Filt");
  fTreeEnergies_Noise_Filt_Decor->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Noise_Filt_Decor->Branch("Q",&Q,"Q/D");

  fTreeEnergies_Noise_Fast_Filt = new TTree("Energies_Noise_Fast_Filt","energiesInd NoXPSD_Fast_Filt");
  fTreeEnergies_Noise_Fast_Filt->Branch("EhAuncorr",&EhAuncorr,"EhAuncorr/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EhBuncorr",&EhBuncorr,"EhBuncorr/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EhA",&EhA,"EhA/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EhB",&EhB,"EhB/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiA",&EiA,"EiA/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiB",&EiB,"EiB/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiC",&EiC,"EiC/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiD",&EiD,"EiD/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("fastEiA",&fastEiA,"fEiA/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("fastEiB",&fastEiB,"fEiB/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("fastEiC",&fastEiC,"fEiC/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("fastEiD",&fastEiD,"fEiD/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWhA",&FWhA,"FWhA/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWhB",&FWhB,"FWhB/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWiA",&FWiA,"FWiA/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWiB",&FWiB,"FWiB/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWiC",&FWiC,"FWiC/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWiD",&FWiD,"FWiD/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWfastIA",&FWfastIA,"FWfastIA/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWfastIB",&FWfastIB,"FWfastIB/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWfastIC",&FWfastIC,"FWfastIC/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("FWfastID",&FWfastID,"FWfastID/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("Ei",&Ei,"Ei/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiFID",&EiFID,"EiFID/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiFIDunweigthed",&EiFIDunweighted,"EiFIDunweighted/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiVETO",&EiVETO,"EiVETO/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiVETO1",&EiVETO1,"EiVETO1/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EiVETO2",&EiVETO2,"EiVETO2/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("EhUncorr",&EhUncorr,"EhUncorr/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("Eh",&Eh,"Eh/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("ErFID",&ErFID,"ErFID/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("Er",&Er,"Er/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("QFID",&QFID,"QFID/D");
  fTreeEnergies_Noise_Fast_Filt->Branch("Q",&Q,"Q/D");

}


void edwEverestTreeOutManager::FillCalib(edwIonCalibDataMap ionCalibDataMap) {

  for (edwIonCalibDataMapIterator it=ionCalibDataMap.begin(); it!=ionCalibDataMap.end(); ++it) {
    fBoloID =  (*it).first;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      fAnaRunNumber = (*it).second[i]->getAnaRunNumber();
      fIonGainA = (*it).second[i]->getGainA();
      fIonGainB = (*it).second[i]->getGainB();
      fIonGainC = (*it).second[i]->getGainC();
      fIonGainD = (*it).second[i]->getGainD();
      fCrossTalkAB = (*it).second[i]->getCrossTalkAB();
      fCrossTalkAC = (*it).second[i]->getCrossTalkAC();
      fCrossTalkAD = (*it).second[i]->getCrossTalkAD();
      fCrossTalkBA = (*it).second[i]->getCrossTalkBA();
      fCrossTalkBC = (*it).second[i]->getCrossTalkBC();
      fCrossTalkBD = (*it).second[i]->getCrossTalkBD();
      fCrossTalkCA = (*it).second[i]->getCrossTalkCA();
      fCrossTalkCB = (*it).second[i]->getCrossTalkCB();
      fCrossTalkCD = (*it).second[i]->getCrossTalkCD();
      fCrossTalkDA = (*it).second[i]->getCrossTalkDA();
      fCrossTalkDB = (*it).second[i]->getCrossTalkDB();
      fCrossTalkDC = (*it).second[i]->getCrossTalkDC();
      fTreeIonCalibData->Fill();
    }
  }


  fRootFile->cd();
  fTreeIonCalibData->Write();

}
void edwEverestTreeOutManager::FillCalib(edwHeatCalibDataMap heatCalibDataMap) {

  for (edwHeatCalibDataMapIterator it=heatCalibDataMap.begin(); it!=heatCalibDataMap.end(); ++it) {
    fBoloID =  (*it).first;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      fAnaRunNumber = (*it).second[i]->getAnaRunNumber();
      fVoltage = (*it).second[i]->getVoltage();
      fHeatGainA = (*it).second[i]->getGainA();
      fHeatGainB = (*it).second[i]->getGainB();
      fHeatTimeDependence = (*it).second[i]->getHeatTimeDependence();
      fTreeHeatCalibData->Fill();
    }
  }

  fRootFile->cd();
  fTreeHeatCalibData->Write();

}

void edwEverestTreeOutManager::FillCalib(edwParamCalibDataMap paramCalibDataMap) {

  for (edwParamCalibDataMapIterator it=paramCalibDataMap.begin(); it!=paramCalibDataMap.end(); ++it) {
    fBoloID =  (*it).first;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      fAnaRunNumber = (*it).second[i]->getAnaRunNumber();
      fFiducialVoltage = (*it).second[i]->getFiducialVoltage();
      fVetoVoltage = (*it).second[i]->getVetoVoltage();
      fIoniXtalkCutA = (*it).second[i]->getIoniXtalkCutA();
      fIoniXtalkCutB = (*it).second[i]->getIoniXtalkCutB();
      fIoniXtalkCutC = (*it).second[i]->getIoniXtalkCutC();
      fIoniXtalkCutD = (*it).second[i]->getIoniXtalkCutD();
      fHeatCorrA = (*it).second[i]->getHeatCorrA();
      fHeatCorrB = (*it).second[i]->getHeatCorrB();
      for(int j=0;j<5;j++) {
	fNonLinearityA[j] = (*it).second[i]->getNonLinearityA(j);
	fNonLinearityB[j] = (*it).second[i]->getNonLinearityB(j);
      }
      fThresholdCorrA = (*it).second[i]->getThresholdCorrA(); 
      fThresholdCorrB = (*it).second[i]->getThresholdCorrB();
      fHeatAweight = (*it).second[i]->getHeatAweight();
      fIonBweight = (*it).second[i]->getIonBweight();
      fTreeParamCalibData->Fill();
    }
  }

  fRootFile->cd();
  fTreeParamCalibData->Write();

}

void edwEverestTreeOutManager::FillCalib(edwStrucCalibDataMap strucCalibDataMap) {

  for (edwStrucCalibDataMapIterator it=strucCalibDataMap.begin(); it!=strucCalibDataMap.end(); ++it) {
    fBoloID =  (*it).first;
    for(unsigned int i=0; i< (*it).second.size(); i++) {
      fAnaRunNumber = (*it).second[i]->getAnaRunNumber();
      fBoloIndexInSamba = (*it).second[i]->getBoloIndexInSamba();
      fHeatAbitNumber = (*it).second[i]->getHeatAbitNumber();
      fHeatBbitNumber = (*it).second[i]->getHeatBbitNumber();
      fPolarisationMode = (*it).second[i]->getPolarisationMode();
      fTreeStrucCalibData->Fill();
    }
  }

  fRootFile->cd();
  fTreeStrucCalibData->Write();

}

void edwEverestTreeOutManager::FillEvent() {

  edwEnergies* anEnergies = NULL;
  edwAmplitudes* anAmplitudes = NULL;


  fAnaRunNumber = fBolometer->getAnaRunNumber();
  boloName = fBolometer->getBoloName();	      
  boloNb = fBolometer->getBoloNb();
  partitionNb = fBolometer->getPartitionNb();
  timeFirstDay = fBolometer->getTimeFirstDay();      
  eventNb = fBolometer->getEventNb();
  heatThresholdA = fBolometer->getHeatThresholdA();    
  heatThresholdB = fBolometer->getHeatThresholdB();    
  normalizedStep = fBolometer->getNormalizedStep();    
  indexIonCalibData = fBolometer->getIonCalibDataIndex(); 
  indexHeatCalibData = fBolometer->getHeatCalibDataIndex();
  indexParamCalibData = fBolometer->getParamCalibDataIndex();
  indexStrucCalibData = fBolometer->getStrucCalibDataIndex();

  fTreeBoloHeader->Fill();

  for(int j = 0; j< fProcessingMethods.size() ; j++) {

    // AMPLITUDES

    anAmplitudes = fBolometer->getAmplitudes(fProcessingMethods[j]);
    if(anAmplitudes) {
      heatA = anAmplitudes->getHeatA();	 
      heatB = anAmplitudes->getHeatB();	
      ionA = anAmplitudes->getIonA();	
      ionB = anAmplitudes->getIonB();	
      ionC = anAmplitudes->getIonC();	
      ionD = anAmplitudes->getIonD();	
      fastIonA = anAmplitudes->getFastIonA();	   
      fastIonB = anAmplitudes->getFastIonB();	   
      fastIonC = anAmplitudes->getFastIonC();	   
      fastIonD = anAmplitudes->getFastIonD();	   
      heatChi2A = anAmplitudes->getHeatChi2A();	   
      heatChi2B = anAmplitudes->getHeatChi2B();	   
      ionChi2A = anAmplitudes->getIonChi2A();	   
      ionChi2B = anAmplitudes->getIonChi2B();	   
      ionChi2C = anAmplitudes->getIonChi2C();	   
      ionChi2D = anAmplitudes->getIonChi2D();	   
      fastIonChi2A = anAmplitudes->getFastIonChi2A();
      fastIonChi2B = anAmplitudes->getFastIonChi2B();
      fastIonChi2C = anAmplitudes->getFastIonChi2C();
      fastIonChi2D = anAmplitudes->getFastIonChi2D();
      heatResoA = anAmplitudes->getHeatResoA();	   
      heatResoB = anAmplitudes->getHeatResoB();	   
      ionResoA = anAmplitudes->getIonResoA();	   
      ionResoB = anAmplitudes->getIonResoB();	   
      ionResoC = anAmplitudes->getIonResoC();	   
      ionResoD = anAmplitudes->getIonResoD();	   
      fastIonAReso = anAmplitudes->getFastIonResoA();
      fastIonBReso = anAmplitudes->getFastIonResoB();
      fastIonCReso = anAmplitudes->getFastIonResoC();
      fastIonDReso = anAmplitudes->getFastIonResoD();
      isDecorr = anAmplitudes->isDecorrelated();

      // Fill the correct tree
      if(fProcessingMethods[j] == "OF") {
	fTreeAmplitudesOF->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD") {
	fTreeAmplitudesNoXPSD->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD_t0") {
	fTreeAmplitudesNoXPSD_t0->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD_filt") {
	fTreeAmplitudesNoXPSD_Filt->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD_t0_filt") {
	fTreeAmplitudesNoXPSD_t0_Filt->Fill();
      } else if(fProcessingMethods[j] == "IndNoXPSD") {
	fTreeAmplitudesIndNoXPSD->Fill();
      } else if(fProcessingMethods[j] == "IndNoXPSD_filt") {
	fTreeAmplitudesIndNoXPSD_Filt->Fill();
      } else if(fProcessingMethods[j] == "trig_Normal_raw") {
	fTreeAmplitudes_Trig->Fill();
      } else if(fProcessingMethods[j] == "trig_Normal_filt") {
	fTreeAmplitudes_Trig_Filt->Fill();
      } else if(fProcessingMethods[j] == "trig_Normal_filt_decor") {
	fTreeAmplitudes_Trig_Filt_Decor->Fill();
      } else if(fProcessingMethods[j] == "trig_Fast_filt") {
	fTreeAmplitudes_Trig_Fast_Filt->Fill();
      } else if(fProcessingMethods[j] == "noise_Normal_raw") {
	fTreeAmplitudes_Noise->Fill();
      } else if(fProcessingMethods[j] == "noise_Normal_filt") {
	fTreeAmplitudes_Noise_Filt->Fill();
      } else if(fProcessingMethods[j] == "noise_Normal_filt_decor") {
	fTreeAmplitudes_Noise_Filt_Decor->Fill();
      } else if(fProcessingMethods[j] == "noise_Fast_filt") {
	fTreeAmplitudes_Noise_Fast_Filt->Fill();
      } else {
	//	cout << " edwEverestTreeOutManager::Fill no tree " << fProcessingMethods[j] << ". Ignored" << endl;
      }

    }

    // ENERGIES

    anEnergies = fBolometer->getEnergies(fProcessingMethods[j]);
     
    if(anEnergies) {
      EhAuncorr = anEnergies->getEhAuncorr();
      EhBuncorr = anEnergies->getEhBuncorr();
      EhA = anEnergies->getEhA();	        
      EhB = anEnergies->getEhB();	        
      EiA = anEnergies->getEiA();	        
      EiB = anEnergies->getEiB();	        
      EiC = anEnergies->getEiC();	        
      EiD = anEnergies->getEiD();	        
      fastEiA = anEnergies->getFastEiA();  
      fastEiB = anEnergies->getFastEiB();  
      fastEiC = anEnergies->getFastEiC();  
      fastEiD = anEnergies->getFastEiD();  
      FWhA = anEnergies->getFWhA();     
      FWhB = anEnergies->getFWhB();     
      FWiA = anEnergies->getFWiA();     
      FWiB = anEnergies->getFWiB();     
      FWiC = anEnergies->getFWiC();     
      FWiD = anEnergies->getFWiD();     
      FWfastIA = anEnergies->getFWfastIA(); 
      FWfastIB = anEnergies->getFWfastIB(); 
      FWfastIC = anEnergies->getFWfastIC(); 
      FWfastID = anEnergies->getFWfastID(); 
      Ei = anEnergies->getEi();	        
      EiFID = anEnergies->getEiFID();    
      EiFIDunweighted = anEnergies->getEiFIDunweighted();
      EiVETO = anEnergies->getEiVETO();   
      EiVETO1 = anEnergies->getEiVETO1();  
      EiVETO2 = anEnergies->getEiVETO2();  
      EhUncorr = anEnergies->getEhUncorr(); 
      Eh = anEnergies->getEh();	        
      ErFID = anEnergies->getErFID();    
      Er = anEnergies->getEr();	        
      QFID = anEnergies->getQFID();     
      Q = anEnergies->getQ();        

      // Fill the correct tree
      if(fProcessingMethods[j] == "OF") {
	fTreeEnergiesOF->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD") {
	fTreeEnergiesNoXPSD->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD_t0") {
	fTreeEnergiesNoXPSD_t0->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD_filt") {
	fTreeEnergiesNoXPSD_Filt->Fill();
      } else if(fProcessingMethods[j] == "NoXPSD_t0_filt") {
	fTreeEnergiesNoXPSD_t0_Filt->Fill();
      } else if(fProcessingMethods[j] == "IndNoXPSD") {
	fTreeEnergiesIndNoXPSD->Fill();
      } else if(fProcessingMethods[j] == "IndNoXPSD_filt") {
	fTreeEnergiesIndNoXPSD_Filt->Fill();
      } else if(fProcessingMethods[j] == "trig_Normal_raw") {
	fTreeEnergies_Trig->Fill();
      } else if(fProcessingMethods[j] == "trig_Normal_filt") {
	fTreeEnergies_Trig_Filt->Fill();
      } else if(fProcessingMethods[j] == "trig_Normal_filt_decor") {
	fTreeEnergies_Trig_Filt_Decor->Fill();
      } else if(fProcessingMethods[j] == "trig_Fast_filt") {
	fTreeEnergies_Trig_Fast_Filt->Fill();
      } else if(fProcessingMethods[j] == "noise_Normal_raw") {
	fTreeEnergies_Noise->Fill();
      } else if(fProcessingMethods[j] == "noise_Normal_filt") {
	fTreeEnergies_Noise_Filt->Fill();
      } else if(fProcessingMethods[j] == "noise_Normal_filt_decor") {
	fTreeEnergies_Noise_Filt_Decor->Fill();
      } else if(fProcessingMethods[j] == "noise_Fast_filt") {
	fTreeEnergies_Noise_Fast_Filt->Fill();
      } else {
	//	cout << " edwEverestTreeOutManager::Fill no tree " << fProcessingMethods[j] << ". Ignored" << endl;
      }
    }

  }
  


}

Int_t edwEverestTreeOutManager::GetEntries(string procMeth) {

  if(procMeth == "OF") {
    return fTreeEnergiesOF->GetEntries();
  } else if(procMeth == "NoXPSD") {
    return fTreeEnergiesNoXPSD->GetEntries();
  } else if(procMeth == "NoXPSD_t0") {
    return fTreeEnergiesNoXPSD_t0->GetEntries();
  } else if(procMeth == "NoXPSD_filt") {
    return fTreeEnergiesNoXPSD_Filt->GetEntries();
  } else if(procMeth == "NoXPSD_t0_filt") {
    return fTreeEnergiesNoXPSD_t0_Filt->GetEntries();
  } else if(procMeth == "IndNoXPSD") {
    return fTreeEnergiesIndNoXPSD->GetEntries();
  } else if(procMeth == "IndNoXPSD_filt") {
    return fTreeEnergiesIndNoXPSD_Filt->GetEntries();
  } else if(procMeth == "trig_Normal_raw") {
    return fTreeEnergies_Trig->GetEntries();
  } else if(procMeth == "trig_Normal_filt") {
    return fTreeEnergies_Trig_Filt->GetEntries();
  } else if(procMeth == "trig_Normal_filt_decor") {
    return fTreeEnergies_Trig_Filt_Decor->GetEntries();
  } else if(procMeth == "trig_Fast_filt") {
    return fTreeEnergies_Trig_Fast_Filt->GetEntries();
  } else if(procMeth == "noise_Normal_raw") {
    return fTreeEnergies_Noise->GetEntries();
  } else if(procMeth == "noise_Normal_filt") {
    return fTreeEnergies_Noise_Filt->GetEntries();
  } else if(procMeth == "noise_Normal_filt_decor") {
    return fTreeEnergies_Noise_Filt_Decor->GetEntries();
  } else if(procMeth == "noise_Fast_filt") {
    return fTreeEnergies_Noise_Fast_Filt->GetEntries();
  } else {
    cout << "edwEverestTreeOutManager::GetEntries(" << procMeth << ") unknown" << endl;
    return 0;
  }


}



void edwEverestTreeOutManager::GetEntry(Int_t i,string option) {

  fTreeBoloHeader->GetEntry(i);

  if(option == "OF") {
    fTreeEnergiesOF->GetEntry(i);
    fTreeAmplitudesOF->GetEntry(i);
  } else if(option == "NoXPSD") {
    fTreeEnergiesNoXPSD->GetEntry(i);
    fTreeAmplitudesNoXPSD->GetEntry(i);
  } else if(option == "NoXPSD_t0") {
    fTreeEnergiesNoXPSD_t0->GetEntry(i);
    fTreeAmplitudesNoXPSD_t0->GetEntry(i);
  } else if(option == "NoXPSD_filt") {
    fTreeEnergiesNoXPSD_Filt->GetEntry(i);
    fTreeAmplitudesNoXPSD_Filt->GetEntry(i);
  } else if(option == "NoXPSD_t0_filt") {
    fTreeEnergiesNoXPSD_t0_Filt->GetEntry(i);
    fTreeAmplitudesNoXPSD_t0_Filt->GetEntry(i);
  } else if(option == "IndNoXPSD") {
    fTreeEnergiesIndNoXPSD->GetEntry(i);
    fTreeAmplitudesIndNoXPSD->GetEntry(i);
  } else if(option == "IndNoXPSD_filt") {
    fTreeEnergiesIndNoXPSD_Filt->GetEntry(i);
    fTreeAmplitudesIndNoXPSD_Filt->GetEntry(i);
  } else if(option == "trig_Normal_raw") {
    fTreeEnergies_Trig->GetEntry(i);
    fTreeAmplitudes_Trig->GetEntry(i);
  } else if(option == "trig_Normal_filt") {
    fTreeEnergies_Trig_Filt->GetEntry(i);
    fTreeAmplitudes_Trig_Filt->GetEntry(i);
  } else if(option == "trig_Normal_filt_decor") {
    fTreeEnergies_Trig_Filt_Decor->GetEntry(i);
    fTreeAmplitudes_Trig_Filt_Decor->GetEntry(i);
  } else if(option == "trig_Fast_filt") {
    fTreeEnergies_Trig_Fast_Filt->GetEntry(i);
    fTreeAmplitudes_Trig_Fast_Filt->GetEntry(i);
  } else if(option == "noise_Normal_raw") {
    fTreeEnergies_Noise->GetEntry(i);
    fTreeAmplitudes_Noise->GetEntry(i);
  } else if(option == "noise_Normal_filt") {
    fTreeEnergies_Noise_Filt->GetEntry(i);
    fTreeAmplitudes_Noise_Filt->GetEntry(i);
  } else if(option == "noise_Normal_filt_decor") {
    fTreeEnergies_Noise_Filt_Decor->GetEntry(i);
    fTreeAmplitudes_Noise_Filt_Decor->GetEntry(i);
  } else if(option == "noise_Fast_filt") {
    fTreeEnergies_Noise_Fast_Filt->GetEntry(i);
    fTreeAmplitudes_Noise_Fast_Filt->GetEntry(i);
  } else {
    cout << "edwEverestTreeOutManager::GetEntry unknow " << option << endl;
  }

  fTreeIonCalibData->GetEntry(indexIonCalibData);
  fTreeHeatCalibData->GetEntry(indexHeatCalibData);
  fTreeParamCalibData->GetEntry(indexParamCalibData);
  fTreeStrucCalibData->GetEntry(indexStrucCalibData);

  
}


Double_t edwEverestTreeOutManager::GetE(string ch) {


  if(ch=="hA") {
    return EhA;
  } else if(ch=="hB") {
    return EhB;
  } else if(ch=="hTot") {
    return Eh;
  } else if(ch=="iA") {
    return EiA;
  } else if(ch=="iB") {
    return EiB;
  } else if(ch=="iC") {
    return EiC;
  } else if(ch=="iD") {
    return EiD;
  } else if(ch=="iFid") {
    return EiFID;
  } else if(ch=="iTot") {
    return Ei;
  } else if(ch=="fiA") {
    return fastEiA;
  } else if(ch=="fiB") {
    return fastEiB;
  } else if(ch=="fiC") {
    return fastEiC;
  } else if(ch=="fiD") {
    return fastEiD;
  } else {
    cout << "ERROR edwEverestTreeOutManager::GetE(ch) unknown channel " << ch << endl;
    return 0;
  }

}

Double_t edwEverestTreeOutManager::GetNormalizedChi2(string ch) {

  int N_samples_Heat = 1024;
  int N_samples_Slow = 1024;
  int N_samples_Fast = 4096;

  if(ch=="hA") {
    return heatChi2A/N_samples_Heat;
  } else if(ch=="hB") {
    return heatChi2B/N_samples_Heat;
  } else if(ch=="iA") {
    return ionChi2A/N_samples_Slow;
  } else if(ch=="iB") {
    return ionChi2B/N_samples_Slow;
  } else if(ch=="iC") {
    return ionChi2C/N_samples_Slow;
  } else if(ch=="iD") {
    return ionChi2D/N_samples_Slow;
  } else if(ch=="fiA") {
    return fastIonChi2A/N_samples_Fast;
  } else if(ch=="fiB") {
    return fastIonChi2B/N_samples_Fast;
  } else if(ch=="fiC") {
    return fastIonChi2C/N_samples_Fast;
  } else if(ch=="fiD") {
    return fastIonChi2D/N_samples_Fast;
  } else {
    cout << "ERROR edwEverestTreeOutManager::GetE(ch) unknown channel " << ch << endl;
    return 0;
  }

}

void edwEverestTreeOutManager::SetReso(string ch,double reso) {

  if(ch=="hA") {
    resoHeatA = reso;
  } else if(ch=="hB") {
    resoHeatB = reso;
  }else if(ch=="hTot"){
    resoHeatTot = reso; 
  } else if(ch=="iA") {
    resoIonA = reso;
  } else if(ch=="iB") {
    resoIonB = reso;
  } else if(ch=="iC") {
    resoIonC = reso;
  } else if(ch=="iD") {
    resoIonD = reso;
  } else if(ch=="fiA") {
    resoFastIonA = reso;
  } else if(ch=="fiB") {
    resoFastIonB = reso;
  } else if(ch=="fiC") {
    resoFastIonC = reso;
  } else if(ch=="fiD") {
    resoFastIonD = reso;
  } else {
    cout << "ERROR edwEverestTreeOutManager::SetReso() unknown channel " << ch << endl;
    return;
  }
}


void edwEverestTreeOutManager::FillReso(string procMeth) {

  fRootFile->cd();
  if(procMeth=="OF") {
    fTreeResolutionsOF->Fill();
    fTreeResolutionsOF->Write();
  } else if(procMeth=="NoXPSD") {
    fTreeResolutionsNoXPSD->Fill();
    fTreeResolutionsNoXPSD->Write();
  } else if(procMeth=="NoXPSD_t0") {
    fTreeResolutionsNoXPSD_t0->Fill();
    fTreeResolutionsNoXPSD_t0->Write();
  } else if(procMeth=="NoXPSD_filt") {
    fTreeResolutionsNoXPSD_Filt->Fill();
    fTreeResolutionsNoXPSD_Filt->Write();
  } else if(procMeth=="NoXPSD_t0_filt") {
    fTreeResolutionsNoXPSD_t0_Filt->Fill();
    fTreeResolutionsNoXPSD_t0_Filt->Write();
  } else if(procMeth=="noise_Normal_raw") {
    fTreeResolutions_Noise->Fill();
    fTreeResolutions_Noise->Write();
  } else if(procMeth=="noise_Normal_filt") {
    fTreeResolutions_Noise_Filt->Fill();
    fTreeResolutions_Noise_Filt->Write();
  } else if(procMeth=="noise_Normal_filt_decor") {
    fTreeResolutions_Noise_Filt_Decor->Fill();
    fTreeResolutions_Noise_Filt_Decor->Write();
  } else if(procMeth=="noise_Fast_filt") {
    fTreeResolutions_Noise_Fast_Filt->Fill();
    fTreeResolutions_Noise_Fast_Filt->Write();
  } else {
    cout << "dont fill reso for " << procMeth << endl;
  }
}
  
