#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <Windows.h>
using namespace std;
template <typename Container>
void input(Container& container)
{
    int size;
    cout << "Введите количество элементов: ";
    cin >> size;
    cout << "Введите элементы: ";
    for (int i = 0; i < size; ++i)
    {
        int element;
        cin >> element;
        container.push_back(element);
    }
}
template <typename Container>
void print(const Container& container)
{
    for (const auto& element : container)
    {
        cout << element << " ";
    }
    cout << endl;
}
template <typename Container>
void swapmidel(Container& container) //Задание 1
{
    auto mid1 = container.begin();
    advance(mid1, container.size() / 2 - 1);
    auto mid2 = container.begin();
    advance(mid2, container.size() / 2);
    swap(*mid1, *mid2);
}
void insertZeroes(vector<int>& V) //Задание 2
{
    V.insert(V.begin() + V.size() / 2, 5, 0);
}
void insertmid(list<int>& L1, list<int>& L2) //Задание 3
{
    auto mid = L1.begin();
    advance(mid, L1.size() / 2);
    L2.splice(L2.end(), L1, mid, next(mid));
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<int> V;
    deque<int> D;
    list<int> L;
    list<int> L2;
    int choice;
    cout << "Введите номер задания (1-10):" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Каждый исходный контейнер содержит не менее двух элементов, количество элементов является четным" << endl;
        cout << "Ввод данных для вектора:" << endl;
        input(V);
        if ((V.size() % 2 != 0) || (V.size() < 2))
        {
            cout << "Количество элементов должно быть четным и не менее двух";
            break;
        }
        cout << "Ввод данных для дека:" << endl;
        input(D);
        if ((D.size() % 2 != 0) || (D.size() < 2))
        {
            cout << "Количество элементов должно быть четным и не менее двух"; 
            break;
        }
        cout << "Ввод данных для списка:" << endl;
        input(L);
        if ((L.size() % 2 != 0) || (L.size() < 2))
        {
            cout << "Количество элементов должно быть четным и не менее двух";
            break;
        }
        swapmidel(V);
        cout << "Измененный вектор:" << endl;
        print(V);
        swapmidel(D);
        cout << "Измененный дек:" << endl;
        print(D);
        swapmidel(L);
        cout << "Измененный список:" << endl;
        print(L); break;
    case 2:
        cout << "Ввод данных для вектора:" << endl;
        input(V);
        if ((V.size() % 2 != 0) || (V.size() < 2))
        {
            cout << "Количество элементов должно быть четным"; break;
        }
        insertZeroes(V);
        cout << "Измененный вектор:" << endl;
        print(V); 
        break;
    case 3:
        cout << "Ввод данных для списка L1:" << endl;
        input(L);
        if ((L.size() % 2 == 0) || (L.size() < 0))
        {
            cout << "Количество элементов должно быть нечетным и не менее двух";
            break;
        }
        cout << "Ввод данных для списка L2:" << endl;
        input(L2);
        insertmid(L, L2);
        cout << "Измененный список L1:" << endl;
        print(L);
        cout << "Измененный список L2:" << endl;
        print(L2);
        break;
    }
}