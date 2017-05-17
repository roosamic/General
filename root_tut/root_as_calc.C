{
/*students will be refered to by index for convience*/
double grade_array[6] = {82,85,86,90,93,95};
 for (int i = 0; i < 6; i++)
   cout <<"grade "<< i <<": "<< grade_array[i]<<endl;



  
double mean = TMath::Mean(6, &grade_array[0]);
 cout<<"average grade: "<< mean <<endl;



double dev;
for (int i =0; i<6; i++){
	dev = grade_array[i]-mean;
	cout<< "deviation "<< i << ": "<< dev <<endl;
     }


double gmean = TMath::GeomMean(6, &grade_array[0]);
cout<< "geometric mean " <<gmean<<endl

   
}
