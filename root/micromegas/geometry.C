#include <iostream>
#include <TCanvas.h>
#include <TROOT.h>
#include <TApplication.h>


#include "MediumMagboltz.hh"
#include "ComponentAnalyticField.hh"
#include "GeometrySimple.hh"
#include "SolidTube.hh"
#include "ViewCell.hh"
#include "ViewGeometry.hh"
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


  TApplication app("app", &argc, argv);
  plottingEngine.SetDefaultStyle();


  //load in the gas data
  MediumMagboltz* gas =new MediumMagboltz();
  gas->LoadGasFile("ar_93_co2_7.gas");

  //declare the analytic field, and the geometry
  ComponentAnalyticField* cmp = new ComponentAnalyticField();
  GeometrySimple* geo = new GeometrySimple();

    //set the dimensions of the tube/wire, all in [cm] 
  double r_tube = diameter/2;
  double halflen_tube = (len_drift+len_aval)/2;
  double halflen_cap = 1;
  double cap_dist = halflen_tube+halflen_cap;
  double halflen_mm = 100.e-6;
  double mm_dist = -(halflen_tube-len_aval-halflen_mm);


  //make the tube, end caps and a layer for the micromegas
  //first 4 zeros are (x,y,z, inner radius ) 
  SolidTube* tube = new SolidTube(0., 0., 0., 0., r_tube, halflen_tube);
  SolidTube* drift_cap = new SolidTube(0., 0., cap_dist, 0., r_tube, halflen_cap);
  SolidTube* aval_cap = new SolidTube(0., 0.,-cap_dist, 0., r_tube, halflen_cap);
  SolidTube* micromegas = new SolidTube(0., 0., cap_dist, 0., r_tube, halflen_cap);

  //make tube of gas and add caps
  geo->AddSolid(tube,gas);
  //i gave the caps gas material bc i don't know how to use stainless steel yet
  geo->AddSolid(drift_cap,gas);
  geo->AddSolid(aval_cap,gas);

  /*

  //pass the geometry into the component field
  cmp->SetGeometry(geo);


  //now make the electric field
  //set voltages

  double v_wire = 3270;
  double v_tube = 0;

  //place tube with radius r_tube, voltage v_tube, n=0 edges (cylinder) and, labled "t"
  cmp->AddTube(r_tube, v_tube, 0, "t");
  */
  



  //look at geometry
  ViewGeometry* view_geo = new ViewGeometry();
  // Set the pointer to the geometry.
  view_geo->SetGeometry(geo);
  view_geo->Plot();

  /*
  //look at the componet
  // Create a viewer.
  ViewCell* view_cmp = new ViewCell();
  // Set the pointer to the component.
  view_cmp->SetComponent(cmp);
  // Make a two-dimensional plot of the cell layout.
  view_cmp->Plot3d();
  */


  app.Run(kTRUE);

}
