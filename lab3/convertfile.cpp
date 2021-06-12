#include "convertfile.h"

ConvertFile::ConvertFile()
{

}

FILE *ConvertFile::FromTxtToBin(std::string path)
{
    FILE* file_txt = fopen(path.c_str(), "r+");
    std::string bin_path = path;
    bin_path.erase(bin_path.size() - 3, 3);
    bin_path += "dat";
    FILE* file_bin = fopen(bin_path.c_str(), "w+b");
    int a;
    while (!feof(file_txt)) {
        int is_read = fscanf(file_txt, "%d", &a);
        if (is_read) fwrite(&a, sizeof (int), 1, file_bin);
    }
    fclose(file_txt);
    rewind(file_bin);
    return file_bin;
}

FILE *ConvertFile::FromBinToTxt(std::string path)
{
    FILE* file_bin = fopen(path.c_str(), "r+b");
    std::string txt_path = path;
    txt_path.erase(txt_path.size() - 3, 3);
    txt_path += "txt";
    FILE* file_txt = fopen(txt_path.c_str(), "w+");
    int a;
    bool first_write = true;
    while (!feof(file_bin)) {
        int is_read = fread(&a, sizeof (int), 1, file_bin);
        if (is_read) {
            if (first_write) {fprintf(file_txt, "%d", a); first_write = false;}
            else fprintf(file_txt, " %d", a);
        }
    }
    fclose(file_bin);
    rewind(file_txt);
    return file_bin;
}
