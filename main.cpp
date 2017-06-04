#include <iostream>
#include <fstream>
#include <vector>

#include "MarcFileReader.h"
#include "StructuralAnalysisModel.h"
using namespace std;


int main()
{
    string path="input.dat";
    string matcodePath="matcode.txt";
    MarcFileReader mfr(path,matcodePath);
    StructuralAnalysisModel* sam = new StructuralAnalysisModel;
    mfr.ReadMarc(sam);
    mfr.ReadMatcode(sam);

    sam->units->force="N";
    sam->units->length="mm";

    sam->WriteJson("output.json");

    delete sam;
    return 0;
}

