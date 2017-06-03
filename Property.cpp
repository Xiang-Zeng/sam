#include "Property.h"

Property::Property()
{

}

Json::Value Property::toJson(){
    Json::Value jprops;
    jprops["hinges_V"]=Json::Value(hinges_V);
    jprops["hinges_PMM"]=Json::Value(hinges_PMM);
    jprops["hinges_M"]=Json::Value(hinges_M);

    for(unsigned int i=0;i<elements.size();++i){
        Json::Value jelem;
        jelem["name"]=Json::Value(elements[i].name);
        jelem["type"]=Json::Value(elements[i].type);
        jelem["subtype"]=Json::Value(elements[i].subtype);
        jelem["section"]=Json::Value(elements[i].section);
        jelem["numIntPt"]=Json::Value(elements[i].numIntPt);
        jelem["geoTransf"]=Json::Value(elements[i].geoTransf);
        jprops["elements"].append(jelem);
    }

    for(unsigned int i=0;i<materials.size();++i){
        jprops["materials"].append(materials[i].toJson());
    }

    for(unsigned int i=0;i<sections.size();++i){
        jprops["sections"].append(sections[i].toJson());
    }

    return jprops;

}
