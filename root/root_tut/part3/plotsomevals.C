{
  TGraphErrors graph("./somevals.txt","%lg %lg %lg");
  graph.SetTitle("this is a title");
  graph.SetMarkerStyle(kCircle);
  graph.SetMarkerColor(3);
  graph.SetLineColor(8);
  graph.Draw("ap");
}
