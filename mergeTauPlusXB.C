#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeTauPlusXB() {
TChain ch("aod2nanoaod/Events");
for (int i = 8175; i < 11181; ++i)
  {
    TString filename = TString::Format("output%i.root", i);
    ch.Add(filename);
  }
ch.Merge("Run2012B_TauPlusX.root");
}
