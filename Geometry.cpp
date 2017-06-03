#include "Geometry.h"

Geometry::Geometry()
{

}

Json::Value Geometry::toJson(){
    Json::Value jgeo;
    for(unsigned int i=0;i<nodes.size();++i){
        Json::Value jnode;
        jnode["name"]=Json::Value(nodes[i].name);
        jnode["ndf"]=Json::Value(nodes[i].ndf);
        for(int j=0;j<3;++j){
            jnode["crd"].append(nodes[i].crd[j]);
        }
        jgeo["nodes"].append(jnode);
    }
    for(unsigned int i=0;i<elements.size();++i){
        Json::Value jelem;
        jelem["name"]=Json::Value(elements[i].name);
        jelem["type"]=Json::Value(elements[i].type);
        for(unsigned int j=0;j<elements[i].con.size();++j){
            jelem["con"].append(elements[i].con[j]);
        }
        jgeo["elements"].append(jelem);
    }
    for(unsigned int i=0;i<masses.size();++i){
        Json::Value jmass;
        //jmass[""]=Json::Value(masses[i].);
        // to do
        jgeo["masses"].append(jmass);
    }
    return jgeo;

}
