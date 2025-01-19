#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>

class FileProcessor {
public:
    static void fillFileWithRandomData(const std::string& filename, int count);
    static void findMaxOddIndexedValue(const std::string& filename);
    static void copyToSquareMatrix(const std::string& filename, int n);
};

#endif // FILEPROCESSOR_H
