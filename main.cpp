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

    //manually assign values
    sam->units->force="N";
    sam->units->length="mm";
    sam->property->sections.rbegin()->Jx=2.5e9;
    sam->property->sections.rbegin()->G=11667;
    Fiber fiber;
    fiber.material="elastic";
    fiber.area=120000;
    fiber.zCoord=0;
    fiber.zCoord=0;
    sam->property->sections.rbegin()->fibers.push_back(fiber);
    Material mat;
    mat.nu=0.2;
    mat.rho=1.0;
    mat.name="elastic";
    mat.type="elastic";
    mat.Ec=28000;
    sam->property->materials.push_back(mat);


    sam->WriteJson("output.json");

    delete sam;
    return 0;
}

