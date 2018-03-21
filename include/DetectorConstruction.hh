
#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

class G4LogicalVolume;
class G4VPhysicalVolume;

#include "G4VUserDetectorConstruction.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction();
    ~DetectorConstruction();
     //void DefineMaterials();
    G4VPhysicalVolume* Construct();
      const G4VPhysicalVolume* Gettracker_phys()   {return tracker_phys;};
	const G4VPhysicalVolume* GetAl_phys()   {return Al_phys;};
  private:
    
    // Logical volumes
    //
    G4LogicalVolume* experimentalHall_log;
    G4LogicalVolume* tracker_log;
    G4LogicalVolume* Al_log;
	G4LogicalVolume* AlO_log;

    // Physical volumes
   
    G4VPhysicalVolume* experimentalHall_phys;
   
    G4VPhysicalVolume* tracker_phys;
	  G4VPhysicalVolume* Al_phys;
	G4VPhysicalVolume* AlO_phys;
};

#endif

