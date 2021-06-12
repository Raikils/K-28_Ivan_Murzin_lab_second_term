#ifndef BASICSORT_H
#define BASICSORT_H
#include <string>

class BasicSort
{
private:
    std::string _file_path;
    void sort_main(FILE* f1);
    void step(FILE* f1, FILE* f2, FILE* f3, int k, int& b2, int& x2);
public:
    BasicSort(std::string path);
    void Sort();
};

#endif // BASICSORT_H
