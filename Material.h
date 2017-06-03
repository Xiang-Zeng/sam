#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <json/json.h>
using namespace std;

class Material
{
public:
    Material();
    Json::Value toJson();

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

#endif // MATERIAL_H
