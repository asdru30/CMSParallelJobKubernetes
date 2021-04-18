#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeGluGluToHToTauTau() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 57; ++i)
  {
    TString filename = TString::Format("GGH2TT%i.root", i);
    ch.Add(filename);
  }
ch.Merge("GluGluToHToTauTau.root");
}
