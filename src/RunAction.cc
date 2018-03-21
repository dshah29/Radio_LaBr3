


#include "RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"


RunAction::RunAction()
{}


RunAction::~RunAction()
{}


void RunAction::BeginOfRunAction(const G4Run* aRun)
{ 
            G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
      //      FILE *myFile;
    //        myFile=fopen("/home/grs/G4/g4work/LaBr3Det/output.txt","a"); 
}

/*void RunAction::printfile(G4int var[],G4int count3[])
{
	for(int i=0;i==500;i++)
		{
			if(count3[var[i]]!= 0)
                            {
                                 fprintf(myFile,"%d \t",var[i]);
                                 fprintf(myFile,"%d \n",count3[var[i]]);
                             }
                 }
}*/

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  //fclose (myFile);
}


