#ifndef CONVERTFILE_H
#define CONVERTFILE_H
#include <string>

class ConvertFile
{
public:
    ConvertFile();
    FILE* FromTxtToBin(std::string path);
    FILE* FromBinToTxt(std::string path);
};

#endif // CONVERTFILE_H
