#ifndef MARCFILEREADER_H
#define MARCFILEREADER_H

#include <fstream>
#include <string>
#include <map>
#include "StructuralAnalysisModel.h"

class MarcFileReader
{
public:
    MarcFileReader(string filePath);
    ~MarcFileReader();
    void ReadMarc(StructuralAnalysisModel* sam);

private:
    ifstream fin;
    enum keys{
        sizing,
        title,
    };
    int _nNodes=0;
    int _nElems=0;
    map<string,keys> keywords;
};

#endif // MARCFILEREADER_H
