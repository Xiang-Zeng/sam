#ifndef PROPERTY_H
#define PROPERTY_H

#include "Section.h"
#include "Material.h"

class Property
{
public:
    Property();

    struct Element{
        string name="";
        string type="";
        string subtype="";
        string section="";
        int numIntPt=0;
        string geoTransf="";
    };

    vector <Element> elements;
    vector <Material> materials;
    vector <Section> sections;
    string hinges_V="";
    string hinges_PMM="";
    string hinges_M="";


};

#endif // PROPERTY_H

