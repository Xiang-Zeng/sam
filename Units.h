#ifndef UNITS_H
#define UNITS_H

#include <string>
#include "json/json.h"

class Units
{
public:
    Units();
    Json::Value toJson();

    std::string length="";
    std::string force="";
    std::string temperature="";
};

#endif // UNITS_H
