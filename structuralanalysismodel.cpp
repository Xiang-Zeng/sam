#include "structuralanalysismodel.h"
#include <fstream>

StructuralAnalysisModel::StructuralAnalysisModel()
{

}

void StructuralAnalysisModel::WriteJSON(string path){
    Json::Value jgeo;
    for(unsigned int i=0;i<geometry.nodes.size();++i){
        Json::Value jnode;
        jnode["name"]=Json::Value(geometry.nodes[i].name);
        jnode["ndf"]=Json::Value(geometry.nodes[i].ndf);
        for(int j=0;j<3;++j){
            jnode["crd"].append(geometry.nodes[i].crd[j]);
        }
        jgeo["nodes"].append(jnode);
    }
    for(unsigned int i=0;i<geometry.elements.size();++i){
        Json::Value jelem;
        jelem["name"]=Json::Value(geometry.elements[i].name);
        jelem["type"]=Json::Value(geometry.elements[i].type);
        for(unsigned int j=0;j<geometry.elements[i].con.size();++j){
            jelem["con"].append(geometry.elements[i].con[j]);
        }
        jgeo["elements"].append(jelem);
    }
    for(unsigned int i=0;i<geometry.masses.size();++i){
        Json::Value jmass;
        //jmass[""]=Json::Value(geometry.masses[i].);
        // to do
        jgeo["masses"].append(jmass);
    }

    Json::Value junits;
    junits["length"]=Json::Value(units.length);
    junits["force"]=Json::Value(units.force);
    junits["temperature"]=Json::Value(units.temperature);

    Json::Value jprops;
    jprops["hinges_V"]=Json::Value(properties.hinges_V);
    jprops["hinges_PMM"]=Json::Value(properties.hinges_PMM);
    jprops["hinges_M"]=Json::Value(properties.hinges_M);
    for(unsigned int i=0;i<properties.elements.size();++i){
        Json::Value jelem;
        jelem["name"]=Json::Value(properties.elements[i].name);
        jelem["type"]=Json::Value(properties.elements[i].type);
        jelem["subtype"]=Json::Value(properties.elements[i].subtype);
        jelem["section"]=Json::Value(properties.elements[i].section);
        jelem["numIntPt"]=Json::Value(properties.elements[i].numIntPt);
        jelem["geoTransf"]=Json::Value(properties.elements[i].geoTransf);
        jprops["elements"].append(jelem);
    }
    for(unsigned int i=0;i<properties.materials.size();++i){
        Json::Value jmat;
        jmat["nu"]=Json::Value(properties.materials[i].nu);
        jmat["rho"]=Json::Value(properties.materials[i].rho);
        jmat["name"]=Json::Value(properties.materials[i].name);
        jmat["fc"]=Json::Value(properties.materials[i].fc);
        jmat["Ec"]=Json::Value(properties.materials[i].Ec);
        jmat["Et"]=Json::Value(properties.materials[i].Et);
        jmat["type"]=Json::Value(properties.materials[i].type);
        jmat["epscu"]=Json::Value(properties.materials[i].epscu);
        jmat["ft"]=Json::Value(properties.materials[i].ft);
        jmat["fcu"]=Json::Value(properties.materials[i].fcu);
        jprops["materials"].append(jmat);
    }
    for(unsigned int i=0;i<properties.sections.size();++i){
        Json::Value jsec;
        for(unsigned int j=0;j<properties.sections[i].fibers.size();j++){
            Json::Value jfiber;
            jfiber["material"]=Json::Value(properties.sections[i].fibers[j].material);
            jfiber["area"]=Json::Value(properties.sections[i].fibers[j].area);
            jfiber["zCoord"]=Json::Value(properties.sections[i].fibers[j].zCoord);
            jfiber["yCoord"]=Json::Value(properties.sections[i].fibers[j].yCoord);
            jsec["fibers"].append(jfiber);
        }
        jsec["Avz"]=Json::Value(properties.sections[i].Avz);
        jsec["Avy"]=Json::Value(properties.sections[i].Avy);
        jsec["type"]=Json::Value(properties.sections[i].type);
        jsec["G"]=Json::Value(properties.sections[i].G);
        jsec["name"]=Json::Value(properties.sections[i].name);
        jsec["Jx"]=Json::Value(properties.sections[i].Jx);
        jprops["sections"].append(jsec);
    }

    Json::Value jsim;
    jsim["revision"]=Json::Value(revision);
    jsim["ndm"]=Json::Value(ndm);
    jsim["ndf"]=Json::Value(ndf);
    jsim["geometry"]=jgeo;
    jsim["units"]=junits;
    jsim["properties"]=jprops;
    jsim["BIM"]=Json::Value(BIM);

    Json::StyledWriter sw;
    ofstream fout(path);
    fout << sw.write(jsim);
    fout.close();
}
