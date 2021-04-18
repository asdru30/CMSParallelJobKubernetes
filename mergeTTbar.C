#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeTTbar() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 697; ++i)
  {
    TString filename = TString::Format("TTbar%i.root", i);
    ch.Add(filename);
  }
ch.Merge("TTbar.root");
}
