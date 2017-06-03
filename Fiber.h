#ifndef FIBER_H
#define FIBER_H

#include <string>
#include "json/json.h"
using namespace std;

class Fiber
{
public:
    Fiber();
    Json::Value toJson();

    string material="";
    double area=0.0;
    double zCoord=0.0;
    double yCoord=0.0;

};

#endif // FIBER_H
