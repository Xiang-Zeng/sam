#include "marcfilereader.h"

MarcFileReader::MarcFileReader(string filePath)
{
    fin.open(filePath);
}

MarcFileReader::~MarcFileReader(){
    fin.close();
}

void MarcFileReader::ReadMarc(StructuralAnalysisModel *sam)
{

}
