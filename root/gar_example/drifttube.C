#include <iostream>
#include <TCanvas.h>
#include <TROOT.h>
#include <TApplication.h>
#include <TH1F.h>

#include "MediumMagboltz.hh"
#include "FundamentalConstants.hh"
#include "ComponentAnalyticField.hh"
#include "GeometrySimple.hh"
#include "SolidTube.hh"
#include "Sensor.hh"
#include "AvalancheMC.hh"
#include "ViewSignal.hh"
#include "Plotting.hh"

using namespace Garfield;

/*
This is following the drift tube example from the Garfield user guide.
It loads the outfile from the gastable.C script, builds the drift tube
and simulates the avalanches

last changed May 5, 2017
roosa@nscl.msu.edu
*/

int main(int argc, char * argv[]){

  TApplication app("app", &argc, argv);
  plottingEngine.SetDefaultStyle();

  //load in the gas data
  MediumMagboltz* gas =new MediumMagboltz();
  gas->LoadGasFile("ar_93_co2_7.gas");

  //declare the analytic field, and the geometry
  ComponentAnalyticField* cmp = new ComponentAnalyticField();
  GeometrySimple* geo = new GeometrySimple();


  
  //set the dimensions of the tube/wire, all in [cm] 
  double r_wire = 25.e-4;
  double r_tube = 1.46;
  double halflen_tube = 10;


  //make the tube
  //first 3 zeros are (x,y, inner radius ) 
  SolidTube* tube = new SolidTube(0. , 0. , 0. , r_wire, r_tube, halflen_tube);

  //put gas in the tube
  geo->AddSolid(tube,gas);

  //pass the geometry into the component field
  cmp->SetGeometry(geo);

  /*doesnt currently work, I'm trying to find the needed headers
  //look at the geometry
  // Create a viewer.
  ViewCell* view = new ViewCell();
  // Set the pointer to the component.
  view->SetComponent(cmp);
  // Make a two-dimensional plot of the cell layout.
  view->Plot2d();
  */

  //now make the electric field
  //set voltages

  double v_wire = 3270;
  double v_tube = 0;

  //place the wire at the origin, with diameter 2*r_wire, volatege v_wire and, labled "s"
  cmp->AddWire(0. , 0. ,2*r_wire, v_wire, "s");

  //place tube with radius r_tube, voltage v_tube, n=0 edges (cylinder) and, labled "t"
  cmp->AddTube(r_tube, v_tube, 0, "t");

  //get the signal in the wire
  cmp->AddReadout("s");


  //make to a sensor and add component field
  Sensor* sensor = new Sensor();
  sensor->AddComponent(cmp);
  sensor->AddElectrode(cmp,"s");


  //set the time period (ns), step and binning for the sensor 
  double time_min = 0;
  double time_max = 2;
  double time_step = 0.02;
  int ntime_bins = int((time_max-time_min)/time_step);

  sensor->SetTimeWindow(time_min, time_step, ntime_bins);
  
  //now we want to simulate electron avalanches
  //declare the avalanch and give it the sensor we defined
  AvalancheMC* aval = new AvalancheMC();
  aval->SetSensor(sensor);
  
  //turn on signal calculations and set time step
  aval->EnableSignalCalculation();
  aval->SetTimeSteps(.05);

  //place an avalance electron slightly off the wire and simulate
  double x0 = 0.;
  double y0 = r_wire + 100.e-4;
  double z0 = 0.;
  double t0 = 0.;
  
  aval->AvalancheElectron(x0, y0, z0, t0);


  //plot current induced in the wire

  ViewSignal* signal_view = new ViewSignal();

  
  signal_view->SetSensor(sensor);
  signal_view->PlotSignal("s");

  app.Run(kTRUE);
  
}
