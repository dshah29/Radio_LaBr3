
#include "EventAction.hh"

#include "RunAction.hh"


#include "G4Event.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>

G4int count=0;
G4int count2=0;
G4int i=0;
G4int var;
G4int count3[1000]={0};
G4int en=0;

EventAction::EventAction()

{ }



EventAction::~EventAction()

{ }



void EventAction::BeginOfEventAction(const G4Event* evt)
{  
  dEnergy=0.;
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* evt)
{
  G4int event_id = evt->GetEventID();
  
 
  G4TrajectoryContainer* trajectoryContainer = evt->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();
  
  // periodic printing
  //
  if (event_id < 100 || event_id%100 == 0) {
    G4cout << ">>> Event " << evt->GetEventID() << G4endl;
    G4cout << "    " << n_trajectories 
	   << " trajectories stored in this event." << G4endl;
  }
          
	    FILE *myFile;
            myFile=fopen("/home/grs/G4/g4work/RadioLaBr3/output.txt","a");
            var= dEnergy*100;       //enegy/10*1000 KeV
              
            count3[var]=count3[var]+1;
     
              // fprintf(myFile,"%f \t",dEnergy);
               //fprintf(myFile,"%d \t",i);
              // fprintf(myFile,"%d \t",var[i]);
              // fprintf(myFile,"%d \n",count3[var[i]]);
            i++;
            if(event_id==2999)
                        { 
                            fprintf(myFile,"%s \t","Energy(keV)");
                            fprintf(myFile,"%s \n","Counts");
                             for(G4int j=0;j<1000;j++)
                            {
                            en=j*10;
                            fprintf(myFile,"%d \t",en);
                            fprintf(myFile,"%d \n",count3[j]);
                             
                            }
                        }
           fclose (myFile);
 
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
