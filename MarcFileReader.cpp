#include "MarcFileReader.h"
#include <iostream>
#include <sstream>
using namespace std;

MarcFileReader::MarcFileReader(string filePath)
{
    fin.open(filePath);
    if(!fin.good())
    {
        cout<<"failed to open file "<<filePath.c_str()<<"!\n";
        fin.close();
        exit(1);
    }

    keywords.clear();
    keywords.insert(make_pair("title",title));
    keywords.insert(make_pair("sizing",sizing));
}

MarcFileReader::~MarcFileReader(){
    fin.close();
}

void MarcFileReader::ReadMarc(StructuralAnalysisModel *sam)
{
    while(!fin.eof())
    {
        string s="";
        getline(fin,s);
        if(s=="\r"||s=="\n"||s[0]=='$')
        {
            continue;
        }

        istringstream iss(s);
        string keyword="";
        iss>>keyword;
        switch (keywords.find(keyword)->second)
        {
        case sizing:
            iss>>_nElems>>_nElems>>_nNodes;
            break;
        default:
            break;
        }

    }

}
