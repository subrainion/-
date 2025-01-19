#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FileProcessor.h"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RUS");
    srand(static_cast<unsigned int>(time(0)));

    const string filename = "data.bin";
    const int count = 20; // ���������� ��������� �����
    const int n = 5; // ����������� ���������� �������

    FileProcessor::fillFileWithRandomData(filename, count);
    FileProcessor::findMaxOddIndexedValue(filename);
    FileProcessor::copyToSquareMatrix(filename, n);
}