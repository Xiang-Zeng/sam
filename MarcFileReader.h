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
    MarcFileReader(string filePath, string matcodePath="");
    ~MarcFileReader();

    template <class Type>
    Type s2num(const string& str);
    string int2s(int n);

    void ReadMarc(StructuralAnalysisModel* sam);
    void ReadMatcode(StructuralAnalysisModel* sam); // Read fiber sections from matcode file
    double marcs2d(string s, string p); //deal with the strange number format in Marc input file. e.g. -4.100000000+3
    void getList(ifstream &fin,vector<int> &list);

private:
    ifstream fin;
    ifstream finmat;
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
