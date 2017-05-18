#include <iostream>
#include <TCanvas.h>
#include <TROOT.h>

#include "MediumMagboltz.hh"
#include "FundamentalConstants.hh"

using namespace Garfield;

/*
This is following the drift tube example from the Garfield user guide.
It generates a gas table for the given gas combination and electric field.
Expect this to take several hours on a personal computer. 

last changed May 5, 2017
roosa@nscl.msu.edu
*/

int main(){

  //Set up gas table, I used the exact values in the manual here

  //initialize the gas and its concentrations
  MediumMagboltz* gas = new MediumMagboltz();
  double con_Ar = 93.;
  double con_CO2=  7.;
  
  gas->SetComposition("ar",con_Ar, "co2", con_CO2);

  //Choose temp (K) and Pressure (torr)
  double pressure = 3*760;
  double temp = 293.15;
  
  gas->SetPressure(pressure);
  gas->SetTemperature(temp);
  
  //set up the electric field (V/cm)
  int field_points = 20;
  double min_field = 100;
  double max_field = 100.e3;
  bool log_spacing = true;
  
  gas->SetFieldGrid(min_field, max_field, field_points, log_spacing);

  //let Magboltz run
  //choose number of collisions in multiples of 10^7
  const int collisions = 10;
  const bool verbose = true;

  gas->GenerateGasTable(collisions,verbose);


  //save to file
  gas->WriteGasFile("ar_93_co2_7.gas");
  
}

