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
#include "MediumSilicon.hh"
#include "Sensor.hh"

using namespace Garfield;

int main(int argc, char * argv[]){
  //set the measurements of the detector
  //len&&diameter=>cm
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

  //make a sensor
  Sensor* sensor = new Sensor();


  //make a component for the drift field and the gain region
  ComponentAnalyticField* wire_cmp = new ComponentAnalyticField();
  ComponentConstant* aval_cmp = new ComponentConstant();
  ComponentConstant* drift_cmp = new ComponentConstant();


  //from bottom up, set the geometry of each region, set the efield and add to their components
  
  //wire is easy 
  //chose len_aval for the "wire"'s len bc it was already there and this should be arbitrary
  wire_cmp->AddWire(0., 0., diameter, v_aval, "wire",len_aval);

  //tubes need to live in a geometry
  GeometrySimple* aval_geo = new GeometrySimple();
  GeometrySimple* drift_geo = new GeometrySimple();

  //calculate the values needed for tubes [cm] 
  double r_tube = diameter/2;
  double hlen_drift = len_drift/2;
  double hlen_aval = len_aval/2;
  double center_drift = len_aval + hlen_aval + hlen_drift;

  //make the volumes
  SolidTube* aval_region = new SolidTube(0., 0., len_aval, 0., r_tube, halflen_aval);
  SolidTube* drift_region = new SolidTube(0., 0.,center_drift , 0., r_tube, halflen_aval);

  //make tubes of gas
  aval_geo->AddSolid(aval_region, gas);
  drift_geo->AddSolid(drift_region, gas);

  //calculate the efields and give the components the geometries
  double aval_field = v_aval/len_aval;
  double drift_field = v_drift/len_drift;

  
     

  


  //add the components to the sensor
  sensor->AddComponent(drift_cmp);
  sensor->AddComponent(aval_cmp);
  sensor->AddElectrode(wire_cmp,"wire")






  app.Run(kTRUE);

}
