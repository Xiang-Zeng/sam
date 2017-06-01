#ifndef STRUCTURALANALYSISMODEL_H
#define STRUCTURALANALYSISMODEL_H

#include <vector>
#include <string>
#include "json/json.h"
using namespace std;

class Geometry
{
public:
    class Node{
    public:
        string name="";
        int ndf=6;
        double crd[3]={0.0,0.0,0.0};
    };

    class Element{
    public:
        string name="";
        vector <string> con;
        string type="";
    };

    class Mass{
    public:
        // to do
    };


    vector <Node> nodes;
    vector <Element> elements;
    vector <Mass> masses;
};

class Units
{
public:
    string length="";
    string force="";
    string temperature="";
};


class Properties
{
public:
    class Element{
    public:
        string name="";
        string type="";
        string subtype="";
        string section="";
        int numIntPt=0;
        string geoTransf="";
    };

    class Material{
    public:
        double nu=0.0;
        double rho=0.0;
        string name="";
        double fc=0.0;
        double Ec=0.0;
        double Et=0.0;
        string type="";
        double epscu=0.0;
        double ft=0.0;
        double fcu=0.0;
    };

    class Fiber{
    public:
        string material="";
        double area=0.0;
        double zCoord=0.0;
        double yCoord=0.0;
    };

    class Section{
    public:
        vector<Fiber> fibers;
        string Avz="";
        string Avy="";
        string type="";
        double G=0.0;
        string name="";
        double Jx=0.0;
    };


    vector <Element> elements;
    vector <Material> materials;
    vector <Section> sections;
    string hinges_V="";
    string hinges_PMM="";
    string hinges_M="";


};

class StructuralAnalysisModel
{
public:

    StructuralAnalysisModel();
    void WriteJSON(string path);

    string revision="";
    int   ndm=0;
    int   ndf=0;
    Geometry geometry;
    Units units;
    Properties properties;
    string BIM="";

};

#endif // STRUCTURALANALYSISMODEL_H
