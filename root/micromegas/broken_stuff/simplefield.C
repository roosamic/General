#include <iostream>
#include <TCanvas.h>
#include <TROOT.h>
#include <TApplication.h>
#include <cmath>


#include "MediumMagboltz.hh"
#include "ViewField.hh"


#include "Plotting.hh"
//Efield from component constant is (as the name suggests) constant
//better models will require a different class
#include "ComponentConstant.hh"
#include "ComponentUser.hh"

using namespace Garfield;


void efield(double x, double y, double z, double& ex, double& ey, double& ez){
  ex = ey = ez = 0.;

    //set the measurements of the detector
  //len=>cm
  double len_drift = 40; 
  double len_aval = 100.e-4;
  
  double diameter = 15.;
  //voltages (V)
  double v_drift = 5000.;
  double v_aval = 300.;
  double total_len = len_drift;
  double inside = pow(diameter/2,2);



  
  double mag_rad = x*x+y*y+z*z;
  if (mag_rad<inside){
    if(z<total_len){
      ez = 125;
      if(z<len_aval){
	ez = 300;
      }
    }
  }
}




int main(int argc, char * argv[]){



  TApplication app("app", &argc, argv);
  plottingEngine.SetDefaultStyle();




  ComponentUser* cmp = new ComponentUser();
  cmp->SetElectricField(efield);
  
  //look at the componet
  // Create a viewer.
  ViewField* view_cmp = new ViewField();
  // Set the pointer to the component.
  view_cmp->SetComponent(cmp);
  // Make a two-dimensional plot of the cell layout.
  view_cmp->PlotContour();


  app.Run(kTRUE);

}
