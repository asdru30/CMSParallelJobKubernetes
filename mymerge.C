#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mymerge() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 30523; ++i)
  {
    TString filename = TString::Format("output%i.root", i);
    ch.Add(filename);
  }
ch.Merge("big.root");
}
