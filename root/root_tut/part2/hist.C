{
/*initialize the histogram and the grades array*/
TH1* h1 = new TH1I("h1", "grade distribution", 10, 60.0, 100);

double grades[15] ={86,77,85,80,85,80,75,80,80,78,88,74,80,71,74};

/*fill the hist and print to check if it worked*/


cout<<"Grades: "<<endl;
for (int i=0; i<15; i++){
h1-> Fill(grades[i]);
cout<< grades[i]<< " added" <<endl;
}
 
cout<<"Mean: "<< TMath::Mean(15, &grades[0])<<endl;
cout<<"std dev: "<< h1->GetRMS()<<endl;


/*drawing*/
h1->SetTitle("Grade Distribution");
h1->GetXaxis()->SetTitle("Grade");


/*grades are often assumed to be gaussian so lets try that*/
h1->Fit("gaus");
h1->Draw();

/*result was satisfactory, the mean was very close to the actual and the stddev was slightly larger*/

}
