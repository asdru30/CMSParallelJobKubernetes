#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeDYJetsToLL() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 2420; ++i)
  {
    TString filename = TString::Format("DY2LL%i.root", i);
    ch.Add(filename);
  }
ch.Merge("DYJetsToLL.root");
}
