#include "Section.h"


Section::Section()
{

}

Json::Value Section::toJson(){
    Json::Value jsec;
    for(unsigned int i=0;i<fibers.size();i++){
        jsec["fibers"].append(fibers[i].toJson());
    }
    jsec["Avz"]=Json::Value(Avz);
    jsec["Avy"]=Json::Value(Avy);
    jsec["type"]=Json::Value(type);
    jsec["G"]=Json::Value(G);
    jsec["name"]=Json::Value(name);
    jsec["Jx"]=Json::Value(Jx);
    return jsec;
}
