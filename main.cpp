#include <iostream>
#include <fstream>
#include <vector>

#include "MarcFileReader.h"
#include "StructuralAnalysisModel.h"
using namespace std;


int main()
{
    string path="input.dat";
    MarcFileReader mfr(path);
    StructuralAnalysisModel* sam = new StructuralAnalysisModel;
    mfr.ReadMarc(sam);

    sam->units->force="N";
    sam->units->length="mm";

    sam->WriteJson("output.json");

    delete sam;
    return 0;
}

