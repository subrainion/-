#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void FileProcessor::fillFileWithRandomData(const string& filename, int count) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        int randomValue = rand() % 100;
        outFile.write(reinterpret_cast<const char*>(&randomValue), sizeof(randomValue));
    }

    outFile.close();
}

void FileProcessor::findMaxOddIndexedValue(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    int value;
    int maxOddIndexedValue = 0;
    int index = 1;

    while (inFile.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        if (index % 2 != 0) 
        {
            if (abs(value) > maxOddIndexedValue)
            {
                maxOddIndexedValue = value;
            }
        }
        index++;
    }

    inFile.close();
    cout << "Наибольшее значение модулей компонент с нечетными номерами: " << maxOddIndexedValue << endl;
}

void FileProcessor::copyToSquareMatrix(const string& filename, int n) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int value;
    int index = 0;

    while (inFile.read(reinterpret_cast<char*>(&value), sizeof(value)) && index < n * n) {
        matrix[index / n][index % n] = value;
        index++;
    }

    inFile.close();

    cout << "Скопированная матрица:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Поиск столбца с максимальным количеством элементов, кратных сумме индексов
    int maxCount = 0;
    int columnIndex = -1;

    for (int col = 0; col < n; ++col) 
    {
        int count = 0;
        for (int row = 0; row < n; ++row) {
            if (matrix[row][col] % (row + col) == 0 && (row + col) != 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            columnIndex = col;
        }
    }
    cout << "Столбец с максимальным количеством элементов, кратных сумме индексов: " << columnIndex + 1 << std::endl;
}
