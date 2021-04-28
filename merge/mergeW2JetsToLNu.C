#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include <iostream>

void mergeW2JetsToLNu() {
TChain ch("aod2nanoaod/Events");
for (int i = 1; i < 2607; ++i)
  {
    TString filename = TString::Format("W22LNu%i.root", i);
    ch.Add(filename);
  }
ch.Merge("W2JetsToLNu.root");
}
