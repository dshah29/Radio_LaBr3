
#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"


//class RunAction;

class EventAction : public G4UserEventAction
{
public:
  EventAction();
  virtual ~EventAction();

  void  BeginOfEventAction(const G4Event*);
  void    EndOfEventAction(const G4Event*);
    
  void AddAbs(G4double de) {dEnergy+= de;};
 
                     
  
    
private:
   
 //  RunAction*  runAct;
   G4double  dEnergy;
  
};



#endif

    
