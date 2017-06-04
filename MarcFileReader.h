#ifndef MARCFILEREADER_H
#define MARCFILEREADER_H

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "StructuralAnalysisModel.h"

class MarcFileReader
{
public:
    MarcFileReader(string filePath);
    ~MarcFileReader();

    template <class Type>
    Type s2num(const string& str);

    void ReadMarc(StructuralAnalysisModel* sam);
    double marcs2d(string s, string p); //deal with the strange number format in Marc input file. e.g. -4.100000000+3
    void getList(ifstream &fin,vector<int> &list);

private:
    ifstream fin;
    enum keys{
        sizing,
        title,
        coordinates,
        hypoelastic,
        isotropic,
        connectivity
    };
    int _nNodes=0;
    int _nElems=0;
    map<string,keys> keywords;
};

#endif // MARCFILEREADER_H
