#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeVBF_HToTauTau() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 55; ++i)
  {
    TString filename = TString::Format("VBFH2TT%i.root", i);
    ch.Add(filename);
  }
ch.Merge("VBF_HToTauTau.root");
}
