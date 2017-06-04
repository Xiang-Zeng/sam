#include "MarcFileReader.h"
#include <iostream>
#include <sstream>
#include <math.h>
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
    keywords.insert(make_pair("connectivity",connectivity));
    keywords.insert(make_pair("coordinates",coordinates));
    keywords.insert(make_pair("hypoelastic",hypoelastic));
    keywords.insert(make_pair("isotropic",isotropic));
}

MarcFileReader::~MarcFileReader(){
    fin.close();
}

template <class Type>
Type MarcFileReader::s2num(const string& str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

double MarcFileReader::marcs2d(string s, string p) //deal with the strange number format in Marc input file. e.g. -4.100000000+3
{
    return s2num<double>(s)*pow(10,s2num<int>(p));
}

void MarcFileReader::getList(ifstream &fin,vector<int> &list)
{
    const int width=12;
    string s="";
    getline(fin,s);
    int n=s.length()/width;
    if(s.length()>13*width)     //id1  id2  ... id13  c
    {
        stringstream ss;
        ss<<s;
        for(int i=0;i<13;++i)
        {
            int id=0;
            ss>>id;
            list.push_back(id);
        }
        getline(fin,s);
        getList(fin,list);
    }
    else if (n==3)           //id1  id2  id3    or    id1 to id3
    {
        stringstream ss;
        string middle="";
        int a0=s2num<int>(s.substr(0,width));
        int a1=s2num<int>(s.substr(width,width));
        int a2=s2num<int>(s.substr(width*2,width));
        ss<<s.substr(width,width);
        ss>>middle;
        if(middle=="to")
        {
            for(int i=a0-1;i<a2;++i)
            {
                list.push_back(i);
            }
        }
        else
        {
            list.push_back(a0-1);
            list.push_back(a1-1);
            list.push_back(a2-1);
        }
    }
    else    //id1  id2  id3   ...  idn
    {
        stringstream ss;
        ss<<s;
        for(int i=0;i<n;++i)
        {
            int id=0;
            ss>>id;
            list.push_back(id);
        }
    }
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
            sam->geometry->elements.resize(_nElems);
            sam->geometry->nodes.resize(_nNodes);
            break;

        case connectivity:
            getline(fin,s);
            for(int i=0;i<_nElems;++i)
            {
                fin>>sam->geometry->elements[i].name>>sam->geometry->elements[i].type;
                if(sam->geometry->elements[i].type=="52")   //Euler beam
                {
                    sam->geometry->elements[i].con.resize(2);
                    fin>>sam->geometry->elements[i].con[0]>>sam->geometry->elements[i].con[1];
                }
                else if(sam->geometry->elements[i].type=="75")  //Shell
                {
                    sam->geometry->elements[i].con.resize(4);
                    fin>>sam->geometry->elements[i].con[0]>>sam->geometry->elements[i].con[1]
                       >>sam->geometry->elements[i].con[2]>>sam->geometry->elements[i].con[3];
                }
            }
            break;

        case coordinates:
            fin>>sam->ndm;  // dimension
            sam->ndf=(sam->ndm-1)*3; //degree of freedom
            getline(fin,s);
            for(int i=0;i<_nNodes;++i)
            {
                getline(fin,s);
                stringstream ss;
                ss<<s2num<int>(s.substr(0,10));
                ss>>sam->geometry->nodes[i].name;
                sam->geometry->nodes[i].ndf=sam->ndf;
                sam->geometry->nodes[i].crd[0]=marcs2d(s.substr(10,18),s.substr(28,2));
                sam->geometry->nodes[i].crd[1]=marcs2d(s.substr(30,18),s.substr(48,2));
                if(sam->ndm==3)
                {
                    sam->geometry->nodes[i].crd[2]=marcs2d(s.substr(50,18),s.substr(68,2));
                }
            }
            break;
        case hypoelastic:
            {
                getline(fin,s);
                getline(fin,s);
                stringstream ss;
                ss<<s2num<int>(s.substr(0,10));
                Section sec;
                ss>>sec.name;
                sec.type="fiber";
                sam->property->sections.push_back(sec);
                getline(fin,s);
                vector<int> elist;
                getList(fin,elist);
                for(unsigned int i=0;i<elist.size();++i)
                {
                    sam->geometry->elements[elist[i]].type=sec.name;
                }
            }
            break;
        case isotropic:
            {
                getline(fin,s);
                getline(fin,s);
                stringstream ss;
                ss<<s2num<int>(s.substr(0,10));
                Section sec;
                ss>>sec.name;
                sec.type="elastic";
                sam->property->sections.push_back(sec);
                getline(fin,s); // to do.
                vector<int> elist;
                getList(fin,elist);
                for(unsigned int i=0;i<elist.size();++i)
                {
                    sam->geometry->elements[elist[i]].type=sec.name;
                }
            }
            break;

        default:
            break;
        }

    }

}
