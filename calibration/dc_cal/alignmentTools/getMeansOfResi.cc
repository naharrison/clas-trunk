///////////////////////////////////////////////////////
//
// getTheMeansOfResi.cc
//
// This file runs over the root files generated by the 
// user_align program (hbook files are actually created
// and then converted to root) and produces plots 
// of the mean for each layer in each sector for
// different angular ranges of the tracks. 
//
// It then fits each histogram to a gaussian and a 
// polynomial background. The plots are saved if requested,
// and the means and widths of the gaussians are written
// out in a text file for later analysis.
//
// Matt Bellis
// 12/15/05
//
///////////////////////////////////////////////////////
using namespace std;
#include<cstdlib>
#include<unistd.h>
#include<iostream>
#include<fstream>
#include<string>
#include"TTree.h"
#include"TFile.h"
#include"TMath.h"
#include"TH1.h"
#include"TF1.h"
#include"TCanvas.h"
#include"TGraph.h"
#include "TClass.h"
#include "TStyle.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TLegend.h"
#include "TLine.h"

//////////////////////////////////////////////
void PrintOptions(const char *name);
// Functions used in the fitting of the histograms
Double_t background(Double_t *x, Double_t *par) ;
Double_t gaussian(Double_t *x, Double_t *par) ;
Double_t fitFunction(Double_t *x, Double_t *par) ;
void fitGaussianAndBackground(TH1F *histo, Double_t low, Double_t high, Double_t mean, Double_t width, int verbose);

TF1 *fitFcn;
TF1 *backFcn;
TF1 *signalFcn;
//////////////////////////////////////////////

int main(int argc, char **argv)
{
  gStyle->SetStatW(0.30);
  gStyle->SetStatH(0.20);
  gStyle->SetStatFont(40);

  gStyle->SetTitleW(0.60);
  gStyle->SetTitleH(0.10);
  gStyle->SetTitleFont(40);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadBottomMargin(0.15);

  gStyle->SetOptStat(0);
  gStyle->SetFitFormat("5.4g");

  char name[256];
  char title[256];
  char command[256];

  int ntrack;
  int sector[16];
  float calcdoca[16][36];
  float fitdoca[16][36];
  short int wire[16][36];
  int layer[16][36];
  float theta[16];
  int angle;

  TTree *tree = NULL; 

  int c;
  extern char *optarg;
  extern int optind;
  int verbose = 0;
  char *progName = argv[0];

  char *pass = "0000";

  if(argc == 1)
  {
    PrintOptions(progName);
    return 0;
  }
  else{
    while((c = getopt(argc,argv,"hp:v")) != -1){
      switch(c){
        case 'h':
          PrintOptions(progName);
          break;
        case 'v':
          verbose++;
          break;
        case 'p':
          pass = optarg;
          cerr << "Processing for " << pass << endl;
          break;
        default:
          PrintOptions(progName);
          return 0;
          break;
      }
    }
  }

  // Declare the canvases
  int numcan = 18+3;
  TCanvas *can[numcan];
  TPad *top[numcan];
  TPad *bottom[numcan];
  TPaveText *mainlabel[2][numcan];
  for(int i=0;i<numcan;i++)
  {

    sprintf(name,"can%d",i);
    sprintf(title, "Data %d", i);
    can[i] = new TCanvas(name,title,10+10*i, 10+10*i, 900, 900);
    can[i]->SetFillColor(0);

    top[i] = new TPad("top", "The Top", 0.01, 0.92, 0.99, 0.99);
    top[i]->SetFillColor(0);
    top[i]->Draw();

    bottom[i] = new TPad("bottom", "The bottom", 0.01, 0.01, 0.99, 0.90);
    bottom[i]->SetFillColor(0);
    bottom[i]->Draw();
    bottom[i]->Divide(6, 6);

    top[i]->cd();
    if(i<6 || i==18)                  sprintf(command,"8^{#circ}< #theta <20^{#circ} - %s",pass);
    else if((i>=6 && i<12) || i==19)  sprintf(command,"40^{#circ}< #theta <65^{#circ} - %s",pass);
    else if((i>=12 && i<18) || i==20) sprintf(command,"75^{#circ}< #theta <115^{#circ} - %s",pass);
    if(verbose) cerr << command <<endl;
    top[i]->cd();
    mainlabel[0][i] = new TPaveText(0.35,0.05,0.99,0.99,"brNDC");
    mainlabel[0][i]->SetFillColor(1);
    mainlabel[0][i]->SetTextColor(0); 
    mainlabel[0][i]->AddText(command);
    mainlabel[0][i]->AddText(" ");
    top[i]->cd();
    mainlabel[0][i]->Draw();

    if(i<18) sprintf(command,"Layers - Sector: %d",i%6+1);
    else     sprintf(command,"Superlayers - all sectors");
    if(verbose) cerr << command <<endl;
    top[i]->cd();
    mainlabel[1][i] = new TPaveText(0.01,0.05,0.33,0.99,"brNDC");
    mainlabel[1][i]->AddText(command);
    mainlabel[1][i]->AddText(" ");
    top[i]->cd();
    mainlabel[1][i]->Draw();

  }

  // Declare the histograms and fitting functions.
  TH1F* hresisuperlayer[4][6][6]; // superlayers
  TH1F* hresi[4][6][36];          // layers
  TF1* fb[4][6][36];
  TF1* fs[4][6][36];
  TF1* ff[4][6][36];
  TF1* fb2[4][6][36];
  TF1* fs2[4][6][36];
  TF1* ff2[4][6][36];

  for(int i=0;i<4;i++)
  {
    for(int j=0;j<6;j++)
    {
      for(int k=0;k<36;k++)
      {
        sprintf(name,"hresi%d-%d-%d",i,j,k);
        hresi[i][j][k] = new TH1F(name,"",100,-0.4,0.4);
        hresi[i][j][k]->SetTitle("");
        hresi[i][j][k]->SetNdivisions(8);
        hresi[i][j][k]->GetXaxis()->CenterTitle();
        hresi[i][j][k]->GetXaxis()->SetTitleOffset(1.10);
        hresi[i][j][k]->GetXaxis()->SetTitleFont(42);
        hresi[i][j][k]->GetXaxis()->SetTitle("residual");
        hresi[i][j][k]->GetYaxis()->SetTitleOffset(1.1);
        hresi[i][j][k]->GetYaxis()->SetTitleFont(42);
        hresi[i][j][k]->GetYaxis()->CenterTitle();
        hresi[i][j][k]->GetYaxis()->SetTitle("events");
        hresi[i][j][k]->SetFillColor(33);

        sprintf(name,"hresisuperlayer%d-%d-%d",i,j,k);
        hresisuperlayer[i][j][k] = new TH1F(name,"",100,-0.5,0.5);
        hresisuperlayer[i][j][k]->SetTitle("");
        hresisuperlayer[i][j][k]->SetNdivisions(8);
        hresisuperlayer[i][j][k]->GetXaxis()->CenterTitle();
        hresisuperlayer[i][j][k]->GetXaxis()->SetTitleOffset(1.10);
        hresisuperlayer[i][j][k]->GetXaxis()->SetTitleFont(42);
        hresisuperlayer[i][j][k]->GetXaxis()->SetTitle("residual");
        hresisuperlayer[i][j][k]->GetYaxis()->SetTitleOffset(1.1);
        hresisuperlayer[i][j][k]->GetYaxis()->SetTitleFont(42);
        hresisuperlayer[i][j][k]->GetYaxis()->CenterTitle();
        hresisuperlayer[i][j][k]->GetYaxis()->SetTitle("events");
        hresisuperlayer[i][j][k]->SetFillColor(33);

      }
    }
  }

  // Loop over the list of root files
  for(int iarg = optind; iarg < argc; ++iarg)
  {
    cerr << "Processing file: " << argv[iarg] << endl;

    TFile f(argv[iarg]);
    tree = (TTree*)f.Get("ALIGN/h50");

    tree->SetBranchAddress("ntrack",&ntrack);
    tree->SetBranchAddress("sector",&sector);
    tree->SetBranchAddress("calcdoca",&calcdoca);
    tree->SetBranchAddress("fitdoca",&fitdoca);
    tree->SetBranchAddress("wire",&wire);
    tree->SetBranchAddress("layer",&layer);
    tree->SetBranchAddress("theta",&theta);

    int nentries = int (tree->GetEntriesFast ());
    cerr << "nentries: " << nentries << endl;
    for (int i=0; i < nentries; i++)
    {
      if (i % 100 == 0) cerr << i << "\r";
      tree->GetEntry (i);
      for(int j=0;j<ntrack;j++) 
      {
        if(theta[j]>8*(6.26/360.0) && theta[j]<115*(6.26/360.0))
        {
          if(theta[j]>8*(6.26/360.0) && theta[j]<20*(6.26/360.0)) angle = 0;
          else if(theta[j]>40*(6.26/360.0) && theta[j]<65*(6.26/360.0)) angle = 1;
          else if(theta[j]>75*(6.26/360.0) && theta[j]<115*(6.26/360.0)) angle = 2;
          else angle = 3;
          for(int k=0;k<36;k++)
          {
            if(fitdoca[j][k]-calcdoca[j][k]!=0 && wire[j][k]>0)
            {
              hresi[angle][sector[j]-1][k]->Fill(fitdoca[j][k]-calcdoca[j][k]);
              hresisuperlayer[angle][sector[j]-1][k/6]->Fill(fitdoca[j][k]-calcdoca[j][k]);
            }
          }
        }
      }
    }
  }

  TPaveText *laba[4][6][36];   
  TPaveText *labsl[4][6][36]; 
  TPaveText *laba2[4][6][36];   
  TPaveText *labsl2[4][6][36]; 

  sprintf(name,"meansAndwidths.%s.txt",pass);
  ofstream OUT(name);
  for(int i=0;i<3;i++)
  {
    if(i==0) sprintf(command,"8< #theta <20 - %s",pass);
    else if(i==1) sprintf(command,"40< #theta <65 - %s",pass);
    else if(i==2) sprintf(command,"75< #theta <115 - %s",pass);
    cerr << command << endl;
    for(int j=0;j<6;j++)
    {
      cerr << "\tSector: " << j+1 << endl;
      for(int k=0;k<36;k++)
      {
        bottom[6*i + j ]->cd(k+1);
        hresi[i][j][k]->Draw();
        fitGaussianAndBackground(hresi[i][j][k],-0.4,0.4,0.0,0.2, verbose);
        ff[i][j][k] = new TF1(*fitFcn);
        fs[i][j][k] = new TF1(*backFcn);
        fb[i][j][k] = new TF1(*signalFcn);
        ff[i][j][k]->Draw("same");
        fs[i][j][k]->Draw("same");
        fb[i][j][k]->Draw("same");
        OUT << i << " " << j+1  << " " << k+1 << " " << 10000*fitFcn->GetParameter(4) << " " << 10000*fitFcn->GetParameter(5) << endl;

        sprintf(command," Layer: %d ",k+1);
        laba[i][j][k] = new TPaveText(0.65,0.85,1.00,1.00,"brNDC");
        laba[i][j][k]->AddText(command);
        laba[i][j][k]->Draw();

        sprintf(command," SL: %d ",k/6+1);
        labsl[i][j][k] = new TPaveText(0.05,0.6,0.35,0.85,"brNDC");
        labsl[i][j][k]->AddText(command);
        if(k%6==0) labsl[i][j][k]->Draw();

      }
    }
  }

  for(int i=0;i<3;i++)
  {
    for(int j=0;j<6;j++)
    {
      for(int k=0;k<6;k++)
      {
        bottom[18+i]->cd(6*j+k+1);
        hresisuperlayer[i][j][k]->Draw();
        fitGaussianAndBackground(hresisuperlayer[i][j][k],-0.4,0.4,0.0,0.2, verbose);
        ff2[i][j][k] = new TF1(*fitFcn);
        fs2[i][j][k] = new TF1(*backFcn);
        fb2[i][j][k] = new TF1(*signalFcn);
        ff2[i][j][k]->Draw("same");
        fs2[i][j][k]->Draw("same");
        fb2[i][j][k]->Draw("same");
        OUT << i << " " << j+1  << " " << k+1 << " " << 10000*fitFcn->GetParameter(4) << " " << 10000*fitFcn->GetParameter(5) << endl;

        sprintf(command," Sector: %d ",j+1);
        laba2[i][j][k] = new TPaveText(0.65,0.85,1.00,1.00,"brNDC");
        laba2[i][j][k]->AddText(command);
        if(k==0) laba2[i][j][k]->Draw();

        sprintf(command," SL: %d ",k+1);
        labsl2[i][j][k] = new TPaveText(0.05,0.6,0.35,0.85,"brNDC");
        labsl2[i][j][k]->AddText(command);
        labsl2[i][j][k]->Draw();

      }
    }
  }

  for(int i=0;i<numcan;i++)
  {
    sprintf(name,"canvas%d.%s.MeansOfResi.eps",i,pass);
    can[i]->SaveAs(name);
  }
  return 0;

}

// Quadratic background function
Double_t background(Double_t *x, Double_t *par) {
  return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}

// Breit-Wigner function
Double_t gaussian(Double_t *x, Double_t *par) {
  return par[0]*exp(-0.5*pow(((x[0]-par[1])/par[2]),2));
}

// Sum of background and peak function
Double_t fitFunction(Double_t *x, Double_t *par) {
  return background(x,par) + gaussian(x,&par[3]);
}

void fitGaussianAndBackground(TH1F *histo, Double_t low, Double_t high, Double_t mean, Double_t width, int verbose)
{
  if(verbose) cerr << "Fitting from " << low << " to " << high << endl;

  // create a TF1 with the range from low to high and 6 parameters
  fitFcn = new TF1("fitFcn",fitFunction, low, high, 6);

  //fitFcn->SetParameter(3, 500); // width
  fitFcn->SetParameter(5, width); // width
  fitFcn->SetParameter(4, mean);   // peak
  fitFcn->SetLineColor(2);

  if(verbose) histo->Fit("fitFcn","EVR");
  else        histo->Fit("fitFcn","EQR");

  // improve the picture:
  backFcn = new TF1("backFcn",background,low,high,3);
  backFcn->SetLineColor(3);
  signalFcn = new TF1("signalFcn",gaussian,low,high,3);
  signalFcn->SetLineColor(4);
  Double_t par[6];

  //fitFcn->Draw("same");
  // writes the fit results into the par array
  fitFcn->GetParameters(par);

  backFcn->SetParameters(par);
  backFcn->Draw("same");

  signalFcn->SetParameters(&par[3]);
  signalFcn->Draw("same");
  fitFcn->Draw("same");

}

//_____________________________________________________________________________
//
void PrintOptions(const char *name) {
  // Print options to the screen.
  cerr << endl;
  cerr << "Usage:" << name << " -p <string>  " << endl;
  cerr << endl;
  cerr << "\t-p<string> The string will designate for which pass this is." << endl;
  cerr << "\t\tThis string will be used as labels on the plots, as well as" << endl;
  cerr << "\t\tfor the names for the .txt file and .eps files produced." << endl;
  cerr << "\t-v  Verbose mode" << endl;
  cerr << "\t-h  Print this message." << endl;
  cerr << endl;
}
