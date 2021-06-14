#include "multisort.h"
#include "convertfile.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int MultiSort::bufferSize() const
{
    return _bufferSize;
}

void MultiSort::setBufferSize(int bufferSize)
{
    _bufferSize = bufferSize;
    max_of_thread = 2;
}

void MultiSort::sort_main(FILE *f1)
{
    distribute_series(f1);

    FILE* f2 = fopen("f2.dat", "r+b"), *f3 = fopen("f3.dat", "r+b");
    fclose(f1); f1 = fopen("f1.dat", "w+b");
    int seriesSize1 = 0, seriesSize2 = _bufferSize, seriesSize3 = _bufferSize;
    int position1 = 0, position2 = 0, position3 = 0;
    first = 0;
    while(true) {
        std::cout << "f1:"; print_file(f1); std::cout << std::endl;
        std::cout << "f2:"; print_file(f2); std::cout << std::endl;
        std::cout << "f3:"; print_file(f3); std::cout << std::endl;
        if ((first == 1 && second == 1) || (first == 1 && third == 1) || (second == 1 && third == 1)) break;
        if (!first) {
            if (second < third) {
                position1 = 0;
                position3 = 0;
                seriesSize1 = seriesSize2 + seriesSize3;
                for (int i = 0; i < second; i++) {
                    int number_of_thread = 0;
                    for (int j = 0; j < max_of_thread; j++) {
                        if ((i + j) >= second) break;
                        number_of_thread++;
                        threads.push_back(std::thread(merge, f2, f3, f1, position2, position3, position1, seriesSize2, seriesSize3));
                        position1 += seriesSize1;
                        position2 += seriesSize2;
                        position3 += seriesSize3;
                    }
                    for (int j = 0; j < number_of_thread; j++) {
                        threads[j].join();
                    }
                    i += threads.size() - 1;
                    threads.clear();
                }
                first = second;
                third -= second;
                second = 0;
                position1 = 0;
                fclose(f2); f2 = fopen("f2.dat", "w+b");
            } else {
                position1 = 0;
                position2 = 0;
                seriesSize1 = seriesSize2 + seriesSize3;
                for (int i = 0; i < third; i++) {
                    int number_of_thread = 0;
                    for (int j = 0; j < max_of_thread; j++) {
                        if ((i + j) >= third) break;
                        number_of_thread++;
                        threads.push_back(std::thread(merge, f2, f3, f1, position2, position3, position1, seriesSize2, seriesSize3));
                        position1 += seriesSize1;
                        position2 += seriesSize2;
                        position3 += seriesSize3;
                    }
                    for (int j = 0; j < number_of_thread; j++) {
                        threads[j].join();
                    }
                    i += threads.size() - 1;
                    std:: cout << i << " " << threads.size() << std::endl;
                    threads.clear();
                }
                first = third;
                second -= third;
                third = 0;
                position1 = 0;
                fclose(f3); f3 = fopen("f3.dat", "w+b");
            }
        } else if (!second) {
            if (first < third) {
                position2 = 0;
                position3 = 0;
                seriesSize2 = seriesSize1 + seriesSize3;
                for (int i = 0; i < first; i++) {
                    int number_of_thread = 0;
                    for (int j = 0; j < max_of_thread; j++) {
                        if ((i + j) >= first) break;
                        number_of_thread++;
                        threads.push_back(std::thread(merge, f1, f3, f2, position1, position3, position2, seriesSize1, seriesSize3));
                        position1 += seriesSize1;
                        position2 += seriesSize2;
                        position3 += seriesSize3;
                    }
                    for (int j = 0; j < number_of_thread; j++) {
                        threads[j].join();
                    }
                    i += threads.size() - 1;
                    threads.clear();
                }
                second = first;
                third -= first;
                first = 0;
                position2 = 0;
                fclose(f1); f1 = fopen("f1.dat", "w+b");
            } else {
                position2 = 0;
                position1 = 0;
                seriesSize2 = seriesSize1 + seriesSize3;
                for (int i = 0; i < third; i++) {
                    int number_of_thread = 0;
                    for (int j = 0; j < max_of_thread; j++) {
                        if ((i + j) >= third) break;
                        number_of_thread++;
                        threads.push_back(std::thread(merge, f1, f3, f2, position1, position3, position2, seriesSize1, seriesSize3));
                        position1 += seriesSize1;
                        position2 += seriesSize2;
                        position3 += seriesSize3;
                    }
                    for (int j = 0; j < number_of_thread; j++) {
                        threads[j].join();
                    }
                    i += threads.size() - 1;
                    threads.clear();
                }
                second = third;
                first -= third;
                third = 0;
                position2 = 0;
                fclose(f3); f3 = fopen("f3.dat", "w+b");
            }
        } else {
            if (first < second) {
                position3 = 0;
                position2 = 0;
                seriesSize3 = seriesSize1 + seriesSize2;
                for (int i = 0; i < first; i++) {
                    int number_of_thread = 0;
                    for (int j = 0; j < max_of_thread; j++) {
                        if ((i + j) >= first) break;
                        number_of_thread++;
                        threads.push_back(std::thread(merge, f1, f2, f3, position1, position2, position3, seriesSize1, seriesSize2));
                        position1 += seriesSize1;
                        position2 += seriesSize2;
                        position3 += seriesSize3;
                    }
                    for (int j = 0; j < number_of_thread; j++) {
                        threads[j].join();
                    }
                    i += threads.size() - 1;
                    threads.clear();
                }
                third = first;
                second -= first;
                first = 0;
                position3 = 0;
                fclose(f1); f1 = fopen("f1.dat", "w+b");
            } else {
                position3 = 0;
                position1 = 0;
                seriesSize3 = seriesSize2 + seriesSize1;
                for (int i = 0; i < second; i++) {
                    int number_of_thread = 0;
                    for (int j = 0; j < max_of_thread; j++) {
                        if ((i + j) >= second) break;
                        number_of_thread++;
                        threads.push_back(std::thread(merge, f1, f2, f3, position1, position2, position3, seriesSize1, seriesSize2));
                        position1 += seriesSize1;
                        position2 += seriesSize2;
                        position3 += seriesSize3;
                    }
                    for (int j = 0; j < number_of_thread; j++) {
                        threads[j].join();
                    }
                    i += threads.size() - 1;
                    threads.clear();
                }
                third = second;
                first -= second;
                second = 0;
                position3 = 0;
                fclose(f2); f2 = fopen("f2.dat", "w+b");
            }
        }
    }

    int result = 0;

    if (first == 1 && second == 1) {last_merge(f1, f2, f3, position1, position2); result = 3; }
    else if (third == 1 && second == 1) {last_merge(f3, f2, f1, position3, position2); result = 1; }
    else if (first == 1 && third == 1) {last_merge(f1, f3, f2, position1, position3);  result = 2; }

    //std::cout << "f1:"; print_file(f1); std::cout << std::endl;
    //std::cout << "f2:"; print_file(f2); std::cout << std::endl;
    //std::cout << "f3:"; print_file(f3); std::cout << std::endl;

    if (result == 2) {
        rewind(f2);
        fclose(f1); f1 = fopen("f1.dat", "wb");
        int value;
        int is_read = fread(&value, sizeof (int), 1, f2);
        while (is_read) {
            fwrite(&value, sizeof (int), 1, f1);
            is_read = fread(&value, sizeof (int), 1, f2);
        }
    }
    if (result == 3) {
        rewind(f3);
        fclose(f1); f1 = fopen("f1.dat", "wb");
        int value;
        int is_read = fread(&value, sizeof (int), 1, f3);
        while (is_read) {
            fwrite(&value, sizeof (int), 1, f1);
            is_read = fread(&value, sizeof (int), 1, f3);
        }
    }
    fclose(f1); fclose(f2); fclose(f3);
}

void MultiSort::distribute_series(FILE *f1)
{
    FILE* f2 = fopen("f2.dat", "wb"), * f3 = fopen("f3.dat", "wb");
    int sum = 1, value;
    second = 0; third = 0;
    bool write_in_second = true;
    std::vector<int> buffer;
    while (!feof(f1)) {
        buffer.clear();
        for (int i = 0; i < _bufferSize; i++) {
            int is_read = fread(&value, sizeof (int), 1, f1);
            if (!is_read) break;
            else buffer.push_back(value);
        }
        std::sort(buffer.begin(), buffer.end());
        for (const auto& elem : buffer) {
            if (write_in_second) fwrite(&elem, sizeof (int), 1, f2);
            else fwrite(&elem, sizeof (int), 1, f3);
        }
        if (buffer.size()) {if (write_in_second) second++; else third++;}
        if (write_in_second && second == sum) { write_in_second = false; sum = second + third; }
        else if (!write_in_second && third == sum) { write_in_second = true; sum = second + third; }
    }
    if (buffer.size() < _bufferSize && buffer.size()) {
        int n = buffer.size();
        while (n < _bufferSize) {
            value = INT_MAX;
            if (write_in_second) fwrite(&value, sizeof (int), 1, f2);
            else fwrite(&value, sizeof (int), 1, f3);
            n++;
        }
    }
    value = INT_MAX;
    if (write_in_second) {
        for (int i = 0; i < (sum - second) * _bufferSize; i++) {
            fwrite(&value, sizeof (int), 1, f2);
        }
        second = sum;
    } else {
        for (int i = 0; i < (sum - third) * _bufferSize; i++) {
            fwrite(&value, sizeof (int), 1, f3);
        }
        third = sum;
    }
    fclose(f2); fclose(f3);
}

void MultiSort::merge(FILE* input1, FILE* input2, FILE* output, int position1, int position2, int position3, int seriesSize1, int seriesSize2)
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //std::cout << position1 << " " << position2 << " " << position3 << " " << seriesSize1 << " " << seriesSize2 << std::endl;
    fseek(input1, sizeof (int) * position1, SEEK_SET);
    fseek(input2, sizeof (int) * position2, SEEK_SET);
    fseek(output, sizeof (int) * position3, SEEK_SET);
    int in1 = 1, in2 = 1;
    int value1, value2;
    fread(&value1, sizeof (int), 1, input1);
    fread(&value2, sizeof (int), 1, input2);
    while (in1 <= seriesSize1 && in2 <= seriesSize2) {
        if (value1 < value2) { fwrite(&value1, sizeof (int), 1, output); fread(&value1, sizeof (int), 1, input1); in1++; }
        else { fwrite(&value2, sizeof (int), 1, output); fread(&value2, sizeof (int), 1, input2); in2++; }
    }
    if (in1 > seriesSize1) {
        while (in2 <= seriesSize2) { fwrite(&value2, sizeof (int), 1, output); fread(&value2, sizeof (int), 1, input2); in2++; }
    } else {
        while (in1 <= seriesSize1) { fwrite(&value1, sizeof (int), 1, output); fread(&value1, sizeof (int), 1, input1); in1++; }
    }
}

void MultiSort::last_merge(FILE *input1, FILE *input2, FILE *output, int position1, int position2)
{
    fseek(input1, sizeof (int) * position1, SEEK_SET);
    fseek(input2, sizeof (int) * position2, SEEK_SET);
    int value1, value2;
    int is_read1, is_read2;
    is_read1 = fread(&value1, sizeof (int), 1, input1);
    is_read2 = fread(&value2, sizeof (int), 1, input2);
    while(is_read1 || is_read2) {
        if (!is_read2) {
           if (value1 !=INT_MAX) fwrite(&value1, sizeof (int), 1, output);
           is_read1 = fread(&value1, sizeof (int), 1, input1);
        } else if (!is_read1) {
            if (value2 !=INT_MAX) fwrite(&value2, sizeof (int), 1, output);
            is_read2 = fread(&value2, sizeof (int), 1, input2);
        } else {
            if (value1 < value2) {
                if (value1 !=INT_MAX) fwrite(&value1, sizeof (int), 1, output);
                is_read1 = fread(&value1, sizeof (int), 1, input1);
            } else {
                if (value2 !=INT_MAX) fwrite(&value2, sizeof (int), 1, output);
                is_read2 = fread(&value2, sizeof (int), 1, input2);
            }
        }
    }
}

void MultiSort::print_file(FILE *f)
{
    rewind(f);
    while (!feof(f)) {
        int a;
        fread(&a, sizeof (int), 1, f);
        std::cout << a << " ";
    }
}

MultiSort::MultiSort(std::string path): _file_path(path)
{
    _bufferSize = 2;
}

void MultiSort::Sort()
{
    ConvertFile conv;
    if (_file_path[_file_path.size() - 3] == 't') {
        sort_main(conv.FromTxtToBin(_file_path));
    } else sort_main(fopen(_file_path.c_str(), "r+b"));
    //FILE* f1
    //std::cout << "f1:"; print_file(f1); std::cout << std::endl;
    fclose(conv.FromBinToTxt("f1.dat"));
}
