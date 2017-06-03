#include "Fiber.h"

Fiber::Fiber()
{

}

Json::Value Fiber::toJson()
{
    Json::Value jfiber;
    jfiber["material"]=Json::Value(material);
    jfiber["area"]=Json::Value(area);
    jfiber["zCoord"]=Json::Value(zCoord);
    jfiber["yCoord"]=Json::Value(yCoord);
    return jfiber;

}
