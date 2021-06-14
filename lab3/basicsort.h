#ifndef BASICSORT_H
#define BASICSORT_H
#include <string>

class BasicSort
{
private:
    std::string _file_path;
    int _bufferSize;
    int second;
    int third;
    int first;
    void sort_main(FILE* f1);
    void distribute_series(FILE* f1);
    void merge(FILE* input1, FILE* input2, FILE* output, int position1, int position2, int position3, int seriesSize1, int seriesSize2);
    void last_merge(FILE* input1, FILE* input2, FILE* output, int position1, int position2);
    void step(FILE* f1, FILE* f2, FILE* f3, int k, int& b2, int& x2);
    void print_file(FILE* f);
public:
    BasicSort(std::string path);
    void Sort();
    int bufferSize() const;
    void setBufferSize(int bufferSize);
};

#endif // BASICSORT_H
