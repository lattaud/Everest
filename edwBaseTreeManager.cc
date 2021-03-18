#define edwBaseTreeManager_cxx
#include "edwBaseTreeManager.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


// Int_t  edwBaseTreeManager::GetAnaRunNumber(int RUN) {

//   //  fRunTree->GetEntry(0);
//   //  fEventTree->GetEntry(0);
//   //  size_t pos = (*runNumber).find("_");*
//   string sambaRunNumber;
//   if( (*runNumber)=="") {
//     sambaRunNumber = m_sambaRun;
//   } else {
//     sambaRunNumber = (*runNumber).substr(0,(*runNumber).find("_"));
//   }

// //   string macNb = sambaRunNumber.substr(4,1);  //-> [0]
// //   string runNb = sambaRunNumber.substr(6,2);  //-> [5,6]
// //   string days = sambaRunNumber.substr(2,2);   //-> [3,4]

//   int startingMonth = 0;
//   char startingYear = 'a';
//   if(RUN==305){
//     startingMonth = 10;
//     //    JulesMonthStart="j"; //(Octobre <=> j )
//     startingYear = 'n' ;  //(2013)
//   }else if(RUN==308){
//     startingMonth = 5;
//     //    JulesMonthStart="e"; //(Mai <=> e ) (car g=juillet et pour jules juillet vaut 2 pour le run 308
//     startingYear = 'o' ;  //(2014)
//   }else if(RUN==309){
//     startingMonth = 6;
//     //    JulesMonthStart="f"; //(Juin <=> f )
//     startingYear = 'p' ;  //(2015)
//   }else if(RUN==310){
//     startingMonth = 3;
//     //    JulesMonthStart="c"; //(Mars <=> c )
//     startingYear = 'n' ;  //(2016)
//   }else if(RUN==311){
//     startingMonth = 12;
//     //JulesMonthStart="l"; //(Decembre <=> c )
//     startingYear = 'q' ;  //(2016)
//   }else if(RUN==313){
//     startingMonth = 10;
//     //JulesMonthStart="j"; //(Octobre <=> j )
//     startingYear = 'r' ;  //(2017)
//   }else if(RUN==316){
//       startingMonth = 6;
//       //JulesMonthStart="f"; //(Juin <=> f )
//       startingYear = 's' ;  //(2018)
//   }else if(RUN==317){
//       startingMonth = 12;
//       startingYear = 's' ;  //(2018-2019)
//   }else if(RUN==57){
//       startingMonth = 0;
//       startingYear = 't' ;  //(2019-2020)
//   }else cout<<"implementer les mois dans calibrationtools.C pour le Run"<<RUN<<endl;

//   int a=* "a";

//   int macNb =*sambaRunNumber.substr(4,1).c_str();//-atoi("a")+1;  //-> [0]
//   macNb = macNb-a+1;

//   int runNb = atoi(sambaRunNumber.substr(6,2).c_str());  //-> [5,6]
//   int days = atoi(sambaRunNumber.substr(2,2).c_str());   //-> [3,4]
//   //  char year = sambaRunNumber.substr(0,1).c_str()[0];
//   int month =* sambaRunNumber.substr(1,1).c_str();//)-atoi("a")+1;
//   month = month-a+1;

//   if(sambaRunNumber.substr(0,1).c_str()[0] == startingYear) {
//     month -= startingMonth;
//   } else {
//     month += 12-startingMonth;
//   }
//   int runNumber = 0;
//   if(macNb == 12 ) {
//     // lyon run
//     int year = startingYear - a;
//     runNumber = year*1000000 + month*10000 + days*100 + runNb;
//   } else {
//     runNumber = macNb*1000000 + month*10000 + days*100 + runNb;
//   }


//   return runNumber;

// }

edwBaseTreeManager::edwBaseTreeManager()
{
}


edwBaseTreeManager::~edwBaseTreeManager()
{
  processingMethodes.clear();
}

