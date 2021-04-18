#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeTauPlusXC() {
TChain ch("aod2nanoaod/Events");
for (int i = 22661; i < 30523; ++i)
  {
    TString filename = TString::Format("output%i.root", i);
    ch.Add(filename);
  }
ch.Merge("Run2012C_TauPlusX.root");
}
