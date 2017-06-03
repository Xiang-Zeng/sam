#include "StructuralAnalysisModel.h"
#include <fstream>

StructuralAnalysisModel::StructuralAnalysisModel()
{
    geometry = new Geometry;
    units = new Units;
    property = new Property;
}

StructuralAnalysisModel::~StructuralAnalysisModel()
{
    delete geometry;
    delete units;
    delete property;
}


Json::Value StructuralAnalysisModel::toJson(){
    Json::Value jsim;
    jsim["revision"]=Json::Value(revision);
    jsim["ndm"]=Json::Value(ndm);
    jsim["ndf"]=Json::Value(ndf);
    jsim["geometry"]=geometry->toJson();
    jsim["units"]=units->toJson();
    jsim["property"]=property->toJson();
    jsim["BIM"]=Json::Value(BIM);
    return jsim;
}

void StructuralAnalysisModel::WriteJson(string path){
    Json::StyledWriter sw;
    ofstream fout(path);
    fout << sw.write(this->toJson());
    fout.close();
}
