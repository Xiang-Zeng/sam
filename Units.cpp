#include "Units.h"

Units::Units()
{

}

Json::Value Units::toJson(){
    Json::Value junits;
    junits["length"]=Json::Value(length);
    junits["force"]=Json::Value(force);
    junits["temperature"]=Json::Value(temperature);
    return junits;
}
