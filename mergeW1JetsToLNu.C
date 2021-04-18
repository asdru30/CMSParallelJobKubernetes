#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeW1JetsToLNu() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 2774; ++i)
  {
    TString filename = TString::Format("W12LNu%i.root", i);
    ch.Add(filename);
  }
ch.Merge("W1JetsToLNu.root");
}
