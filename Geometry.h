#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <string>
#include <vector>
using namespace std;

class Geometry
{
public:
    Geometry();
    struct Node{
        string name="";
        int ndf=6;
        double crd[3]={0.0,0.0,0.0};
    };

    struct Element{
        string name="";
        vector <string> con;
        string type="";
    };

    struct Mass{
        // to do
    };


    vector <Node> nodes;
    vector <Element> elements;
    vector <Mass> masses;

};

#endif // GEOMETRY_H
