#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeW3JetsToLNu() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 1716; ++i)
  {
    TString filename = TString::Format("W32LNu%i.root", i);
    ch.Add(filename);
  }
ch.Merge("W3JetsToLNu.root");
}
