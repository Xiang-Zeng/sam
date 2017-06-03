#include "Material.h"

Material::Material()
{

}

Json::Value Material::toJson(){
    Json::Value jmat;
    jmat["nu"]=Json::Value(nu);
    jmat["rho"]=Json::Value(rho);
    jmat["name"]=Json::Value(name);
    jmat["fc"]=Json::Value(fc);
    jmat["Ec"]=Json::Value(Ec);
    jmat["Et"]=Json::Value(Et);
    jmat["type"]=Json::Value(type);
    jmat["epscu"]=Json::Value(epscu);
    jmat["ft"]=Json::Value(ft);
    jmat["fcu"]=Json::Value(fcu);
    return jmat;
}
