
#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"


class EventAction;
class DetectorConstruction;

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(DetectorConstruction*, EventAction*);
  virtual ~SteppingAction();

  void UserSteppingAction(const G4Step*);
    
private:
  DetectorConstruction* detector;
  EventAction*  eventaction;  
};


#endif
