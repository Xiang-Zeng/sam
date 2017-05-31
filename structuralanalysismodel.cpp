#include "structuralanalysismodel.h"

StructuralAnalysisModel::StructuralAnalysisModel()
{

}

void WriteJSON(string path){
    ofstream fout(path);
    Json::Value jsim;




    Json::StyledWriter sw;
    fout << sw.write(jsim);
    fout.close();
}
