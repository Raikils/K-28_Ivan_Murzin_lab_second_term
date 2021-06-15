#ifndef CONVERTFILE_H
#define CONVERTFILE_H
#include <string>

/*!
 * \brief The ConvertFile class
 * Interface to convert file
 */
class ConvertFile
{
public:
    /*!
     * Constactor of class
     */
    ConvertFile();
    /*!
     * Transforms txt file to bin
     */
    FILE* FromTxtToBin(std::string path);
    /*!
     * Transforms bin file to txt
     */
    FILE* FromBinToTxt(std::string path);
};

#endif // CONVERTFILE_H
