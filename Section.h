#ifndef SECTION_H
#define SECTION_H

#include "Fiber.h"
#include <vector>

class Section
{
public:
    Section();

    vector<Fiber> fibers;
    string Avz="";
    string Avy="";
    string type="";
    double G=0.0;
    string name="";
    double Jx=0.0;
};

#endif // SECTION_H
