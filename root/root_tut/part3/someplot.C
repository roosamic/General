void someplot()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu May 11 14:37:20 2017) by ROOT version6.08/06
   TCanvas *c1 = new TCanvas("c1", "c1",65,52,700,500);
   c1->Range(3679.25,-357.2501,9095.75,7144.25);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[19] = {
   4582,
   4582,
   4908,
   5597,
   5802,
   6170,
   6620,
   6871,
   7107,
   7107,
   7255,
   7255,
   7678,
   7892,
   7892,
   7892,
   7892,
   8193,
   8193};
   Double_t Graph0_fy1001[19] = {
   943,
   2307,
   1268,
   3326,
   2162,
   3899,
   2980,
   3231,
   3463,
   4850,
   3610,
   4986,
   5407,
   1377,
   1489,
   4252,
   5624,
   1804,
   4545};
   Double_t Graph0_fex1001[19] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[19] = {
   50,
   491,
   103,
   172,
   220,
   455,
   700,
   85,
   23,
   340,
   177,
   233,
   443,
   156,
   223,
   347,
   270,
   100,
   370};
   TGraphErrors *gre = new TGraphErrors(19,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("this is a title");
   gre->SetFillColor(1);
   gre->SetLineColor(8);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(4);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","this is a title",100,4220.9,8554.1);
   Graph_Graph1001->SetMinimum(392.9);
   Graph_Graph1001->SetMaximum(6394.1);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.3904298,0.94,0.6095702,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("this is a title");
   pt->Draw();
   
   pt = new TPaveText(4602.693,5007.747,5960.698,5830.696,"br");
   pt->Draw();
      tex = new TLatex(4804.454,5308.44,"I added text ");
   tex->SetLineWidth(2);
   tex->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
   c1->ToggleToolBar();
}
