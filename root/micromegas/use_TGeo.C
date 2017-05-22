/*
I gave up on trying to find a simple way to get garfield to accept our set up
Ill be using the TGeo class.

roosa@nscl.msu.edu
*/

#include <iostream>
#include <TCanvas.h>
#include <TROOT.h>
#include <TApplication.h>
#include <TGeoManager.h>
#include <TGeoMaterial.h>
#include <TGeoMedium.h>
#include <TGeoVolume.h>

#include "MediumMagboltz.hh"
#include "GeometryRoot.hh"
#include "Plotting.hh"

using namespace Garfield;

int main(int argc, char * argv[]){
  //set the measurements of the detector
  //len=>cm
  double len_drift = 40; 
  double len_aval = 100.e-4; 
  double diameter = 15.;
  //voltages (V)
  double v_drift = 5000.;
  double v_aval = 300.;

  //let the executible produce graphics as if it were in the root app.
  TApplication app("app", &argc, argv);
  plottingEngine.SetDefaultStyle();

  /*
  //trying to get copper into garfield 
  TGeoElementTable *table = gGeoManager->GetElementTable();
  TGeoElement *Cu = table->GetElement(Int_t Z = 29);
  */

  //load in the gas data
  MediumMagboltz* gas =new MediumMagboltz();
  gas->LoadGasFile("ar_93_co2_7.gas");


  //build the damn thing, currently copypasta'd from the gar_handbook 
  // Create the ROOT geometry.
  TGeoManager* geoman = new TGeoManager("world", "geometry");
  
  // Create the ROOT material and medium.
  // For simplicity we use the predefined material "Vacuum".
  TGeoMaterial* matVacuum = new TGeoMaterial("Vacuum", 0, 0, 0);
  TGeoMedium* medVacuum = new TGeoMedium("Vacuum", 1, matVacuum);
  
  // Dimensions of the tube
  double rMin = 0., rMax = 0.5, halfLength = 10.;
  
  // In this simple case, the tube is also the top volume.
  TGeoVolume* top = geoman->MakeTube("TOP", medVacuum, rMin, rMax, halfLength);
  geoman->SetTopVolume(top);
  geoman->CloseGeometry();
  
  // Create the Garfield geometry.
  GeometryRoot* geo = new GeometryRoot();
  
  // Pass the pointer to the TGeoManager.
  geo->SetGeometry(geoman);
  
  // Associate the ROOT medium with the Garfield medium.
  geo->SetMedium("Vacuum", gas);

  

  
  app.Run(kTRUE);

}
