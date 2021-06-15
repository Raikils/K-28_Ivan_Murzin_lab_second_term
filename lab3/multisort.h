#ifndef MULTISORT_H
#define MULTISORT_H
#include <string>
#include <thread>
#include <vector>

/*!
 * \brief The BasicSort class
 * Algorithm using threads
 */
class MultiSort
{
private:
    std::string _file_path;
    int _bufferSize;
    int second;
    int third;
    int first;
    std::vector<std::thread> threads;
    int max_of_thread;
    void sort_main(FILE* f1);
    void distribute_series(FILE* f1);
    static void merge(std::string path1, std::string path2, std::string path3, int position1, int position2, int position3, int seriesSize1, int seriesSize2);
    void last_merge(FILE* input1, FILE* input2, FILE* output, int position1, int position2);
    void step(FILE* f1, FILE* f2, FILE* f3, int k, int& b2, int& x2);
    void print_file(FILE* f);
public:
    /*!
     * Constactor of class. Sets path of file. Sets buffer size 2
     */
    MultiSort(std::string path);
    /*!
     * Sort given file
     */
    void Sort();
    /*!
     * Returns size of buffer
     */
    int bufferSize() const;
    /*!
     * Sets size of buffer
     */
    void setBufferSize(int bufferSize);
};

#endif // MULTISORT_H
