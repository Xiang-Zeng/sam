#ifndef MARCFILEREADER_H
#define MARCFILEREADER_H

#include <fstream>
#include <string>
#include "structuralanalysismodel.h"

class MarcFileReader
{
public:
    MarcFileReader(string filePath);
    ~MarcFileReader();
    void ReadMarc(StructuralAnalysisModel* sam);

private:
    ifstream fin;
};

#endif // MARCFILEREADER_H
