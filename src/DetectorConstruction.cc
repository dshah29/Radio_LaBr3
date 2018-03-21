

#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4PVParameterised.hh"



DetectorConstruction::DetectorConstruction()
 :  experimentalHall_log(0), tracker_log(0),Al_log(0) ,AlO_log(0),
    experimentalHall_phys(0),  tracker_phys(0),Al_phys(0),AlO_phys(0)
{;}



DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{



  G4double a;  // atomic mass
  G4double z;  // atomic number
  G4double density,natoms,ncomponents,fractionmass,nelements;
  
  
   //------------------------------------------------------ materials
  G4Element* La = new G4Element("Lanthanum", "La", z=57.,a=138.9055*g/mole);
  G4Element* Br = new G4Element("Bromium", "Br", z=35., a=79.904*g/mole);
  G4Element* Ce = new G4Element("Cerium", "Ce", z=58., a=140.116*g/mole);
  //G4Element* Al = new G4Element("Aluminum", "Al", z=13., a=26.98154*g/mole);
  
  
  G4Material* LaBr3 = new G4Material("LaBr3", density = 5.29*g/cm3, ncomponents=2);
  LaBr3->AddElement(La, fractionmass=25.*perCent);
  LaBr3->AddElement(Br, fractionmass=75.*perCent);

  
  G4Material* LaBr3_Ce = new G4Material("LaBr3_Ce", density = 5.29*g/cm3, ncomponents=2);
  LaBr3_Ce->AddMaterial(LaBr3, fractionmass=99.5*perCent);
  LaBr3_Ce->AddElement(Ce, fractionmass=0.5*perCent);

  G4Material* Al = 
  new G4Material("Aluminum", z= 13., a=26.98154*g/mole, density=2.702*g/cm3);

  G4Material* vacuum =
     new G4Material("Vacuum", 1,1.008*g/mole,  1.e-25*g/cm3,  kStateGas,     2.73*kelvin,   1.e-25*g/cm3);

  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);

  G4Material* Air = new G4Material("Air", density=1.29*mg/cm3, nelements=2);
  Air->AddElement(N, 70.*perCent);
  Air->AddElement(O, 30.*perCent);


  G4double expHall_x = 0.5*m;
  G4double expHall_y = 0.5*m;
  G4double expHall_z = 1.0*m;
  G4Box* experimentalHall_box = new G4Box("expHall_box",expHall_x,expHall_y,expHall_z);
  experimentalHall_log = new G4LogicalVolume(experimentalHall_box, Air ,"expHall_log",0,0,0);
  experimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),experimentalHall_log,"expHall",0,false,0);
  
  //experimentalHall_log->SetVisAttributes(G4VisAttributes::Invisible);

  /* const G4int nEntries = 5;
   G4double LaBr_Energy[nEntries] =  { 3.001*eV, 3.000*eV, 3.000*eV, 2.999*eV, 2.998*eV};

  // LaBr:Ce	 
  G4double LaBr_Fast[nEntries]  =  {1.0,  1.0,   1.0,   1.0,  1.0};     
  G4double LaBr_RIND[nEntries]     =  { 1.9, 1.9, 1.9, 1.9, 1.9};
  G4double LaBr_ABSL[nEntries]     =  {35.*cm, 35.*cm, 35.*cm, 35.*cm, 35.*cm};

  G4MaterialPropertiesTable* LaBr_MPT = new G4MaterialPropertiesTable();
  LaBr_MPT->AddProperty("RINDEX",       LaBr_Energy, LaBr_RIND,    nEntries);
  LaBr_MPT->AddProperty("ABSLENGTH",    LaBr_Energy, LaBr_ABSL,    nEntries);
  LaBr_MPT->AddProperty("FASTCOMPONENT",LaBr_Energy, LaBr_Fast, nEntries);
  LaBr_MPT->AddConstProperty("SCINTILLATIONYIELD", 63000./MeV);
  LaBr_MPT->AddConstProperty("RESOLUTIONSCALE", 2.06);
  LaBr_MPT->AddConstProperty("FASTTIMECONSTANT", 16.*ns);
  
  LaBr3_Ce->SetMaterialPropertiesTable(LaBr_MPT); */
  
  /* const G4int nEntries = 32;

  G4double PhotonEnergy[nEntries] =
            { 2.034*eV, 2.068*eV, 2.103*eV, 2.139*eV,
              2.177*eV, 2.216*eV, 2.256*eV, 2.298*eV,
              2.341*eV, 2.386*eV, 2.433*eV, 2.481*eV,
              2.532*eV, 2.585*eV, 2.640*eV, 2.697*eV,
              2.757*eV, 2.820*eV, 2.885*eV, 2.954*eV,
              3.026*eV, 3.102*eV, 3.181*eV, 3.265*eV,
              3.353*eV, 3.446*eV, 3.545*eV, 3.649*eV,
              3.760*eV, 3.877*eV, 4.002*eV, 4.136*eV };
//
// Water
//	      
  G4double RefractiveIndex1[nEntries] =
            { 1.3435, 1.344,  1.3445, 1.345,  1.3455,
              1.346,  1.3465, 1.347,  1.3475, 1.348,
              1.3485, 1.3492, 1.35,   1.3505, 1.351,
              1.3518, 1.3522, 1.3530, 1.3535, 1.354,
              1.3545, 1.355,  1.3555, 1.356,  1.3568,
              1.3572, 1.358,  1.3585, 1.359,  1.3595,
              1.36,   1.3608};

  G4double Absorption1[nEntries] =
           {3.448*m,  4.082*m,  6.329*m,  9.174*m, 12.346*m, 13.889*m,
           15.152*m, 17.241*m, 18.868*m, 20.000*m, 26.316*m, 35.714*m,
           45.455*m, 47.619*m, 52.632*m, 52.632*m, 55.556*m, 52.632*m,
           52.632*m, 47.619*m, 45.455*m, 41.667*m, 37.037*m, 33.333*m,
           30.000*m, 28.500*m, 27.000*m, 24.500*m, 22.000*m, 19.500*m,
           17.500*m, 14.500*m };

  G4double ScintilFast[nEntries] =
            { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00 };
  G4double ScintilSlow[nEntries] =
            { 0.01, 1.00, 2.00, 3.00, 4.00, 5.00, 6.00,
              7.00, 8.00, 9.00, 8.00, 7.00, 6.00, 4.00,
              3.00, 2.00, 1.00, 0.01, 1.00, 2.00, 3.00,
              4.00, 5.00, 6.00, 7.00, 8.00, 9.00, 8.00,
              7.00, 6.00, 5.00, 4.00 };

  G4MaterialPropertiesTable* myMPT1 = new G4MaterialPropertiesTable();
  myMPT1->AddProperty("RINDEX",       PhotonEnergy, RefractiveIndex1,nEntries);
  myMPT1->AddProperty("ABSLENGTH",    PhotonEnergy, Absorption1,     nEntries);
  myMPT1->AddProperty("FASTCOMPONENT",PhotonEnergy, ScintilFast,     nEntries);
  myMPT1->AddProperty("SLOWCOMPONENT",PhotonEnergy, ScintilSlow,     nEntries);
  
  myMPT1->AddConstProperty("SCINTILLATIONYIELD",500./MeV);
  myMPT1->AddConstProperty("RESOLUTIONSCALE",1.0);
  myMPT1->AddConstProperty("FASTTIMECONSTANT", 1.*ns);
  myMPT1->AddConstProperty("SLOWTIMECONSTANT",10.*ns);
  myMPT1->AddConstProperty("YIELDRATIO",0.8);

  LaBr3->SetMaterialPropertiesTable(myMPT1);*/

  G4double innerRadiusOfTheTube = 0.*mm;
  G4double outerRadiusOfTheTube = 38.*mm;
  G4double hightOfTheTube = 38.*mm;
  G4double startAngleOfTheTube = 0.*deg;
  G4double spanningAngleOfTheTube = 360.*deg;
  G4Tubs* tracker_tube = new G4Tubs("tracker_tube",innerRadiusOfTheTube,outerRadiusOfTheTube,hightOfTheTube,startAngleOfTheTube,spanningAngleOfTheTube);

   tracker_log = new G4LogicalVolume(tracker_tube,LaBr3_Ce,"tracker_log",0,0,0);
  G4double trackerPos_x = 0.*m;
  G4double trackerPos_y = 0.*m;
  G4double trackerPos_z = 0.*m;
  tracker_phys = new G4PVPlacement(0,
             G4ThreeVector(trackerPos_x,trackerPos_y,trackerPos_z),
             tracker_log,"tracker",experimentalHall_log,false,0);


//Al casing outside the Detector

  
  G4double innerRadiusOfTheTubeAl = 38.*mm;
  G4double outerRadiusOfTheTubeAl = 39.*mm;
  G4double hightOfTheTubeAl = 38.*mm;
  G4double startAngleOfTheTubeAl = 0.*deg;
  G4double spanningAngleOfTheTubeAl = 360.*deg;
  G4Tubs* Al_tube = new G4Tubs("Al_tube",innerRadiusOfTheTubeAl,outerRadiusOfTheTubeAl,hightOfTheTubeAl,startAngleOfTheTubeAl,spanningAngleOfTheTubeAl);
  
 
   Al_log = new G4LogicalVolume(Al_tube,Al,"Al_log",0,0,0);
  G4double trackerPosAl_x = 0.*m;
  G4double trackerPosAl_y = 0.*m;
  G4double trackerPosAl_z = 0.*m;
  Al_phys = new G4PVPlacement(0,
             G4ThreeVector(trackerPosAl_x,trackerPosAl_y,trackerPosAl_z),
             Al_log,"Alcase",experimentalHall_log,false,0);

  //back side of detector (Al casing)

  G4double innerRadiusOfTheTubeAlO = 0.*mm;
  G4double outerRadiusOfTheTubeAlO = 39.*mm;
  G4double hightOfTheTubeAlO = 0.5*mm;
  G4double startAngleOfTheTubeAlO = 0.*deg;
  G4double spanningAngleOfTheTubeAlO = 360.*deg;
  G4Tubs* AlO_tube = new G4Tubs("AlO_tube",innerRadiusOfTheTubeAlO,outerRadiusOfTheTubeAlO,hightOfTheTubeAlO,startAngleOfTheTubeAlO,spanningAngleOfTheTubeAlO);
  
 
  AlO_log = new G4LogicalVolume(AlO_tube,Al,"AlO_log",0,0,0);
  G4double trackerPosAlO_x = 0.*mm;
  G4double trackerPosAlO_y = 0.*mm;
  G4double trackerPosAlO_z = -38.*mm;
  AlO_phys = new G4PVPlacement(0,
             G4ThreeVector(trackerPosAlO_x,trackerPosAlO_y,trackerPosAlO_z),
             AlO_log,"AlOcase",experimentalHall_log,false,0);
  
  //FINAL PARAMETER

  G4VisAttributes * tracker_logTubeVisAtt = new G4VisAttributes(G4Colour(1.0,1.0,0.0));
  G4VisAttributes * Al_logTubeVisAtt = new G4VisAttributes(G4Colour(1.0,0.0,1.0));
  G4VisAttributes * AlO_logTubeVisAtt = new G4VisAttributes(G4Colour(1.0,0.0,1.0));	
  
  tracker_logTubeVisAtt->SetForceSolid(true);
  tracker_log->SetVisAttributes(tracker_logTubeVisAtt);
  
  Al_logTubeVisAtt->SetForceSolid(true);
  Al_log->SetVisAttributes(Al_logTubeVisAtt);

  AlO_logTubeVisAtt->SetForceSolid(true);
  AlO_log->SetVisAttributes(AlO_logTubeVisAtt);
  return experimentalHall_phys;
}







