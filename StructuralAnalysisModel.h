#ifndef STRUCTURALANALYSISMODEL_H
#define STRUCTURALANALYSISMODEL_H

#include <vector>
#include <string>
#include "json/json.h"
#include "Units.h"
#include "Geometry.h"
#include "Property.h"

using namespace std;


class StructuralAnalysisModel
{
public:

    StructuralAnalysisModel();
    ~StructuralAnalysisModel();
    Json::Value toJson();
    void WriteJson(string path);

    string revision="";
    int   ndm=0;
    int   ndf=0;
    Geometry * geometry;
    Units * units;
    Property * property;
    string BIM="";

};

#endif // STRUCTURALANALYSISMODEL_H
