#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <Windows.h>
using namespace std;
template <typename Container>
void input(Container& container)
{
    int size;
    cout << "Введите количество элементов: ";
    cin >> size;
    if (size < 1)
    {
        cout << "Неверное количество элементов";
        exit(1);
    }
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
void printEvenIndexedNumbers() //zadanie 4
{
    cout << "Введите набор вещественных чисел (для завершения ввода введите нечисловое значение):" << endl;

    // Используем istream_iterator для чтения чисел из стандартного ввода
    istream_iterator<double> start(cin), end;

    int index = 0;

    // Лямбда-выражение для фильтрации четных индексов
    auto is_even_index = [&index](double) mutable {
        return (index++ % 2) != 1; // Возвращаем true для нечетных индексов
        };

    // Используем remove_copy_if для копирования только четных индексов в выходной поток
    remove_copy_if(start, end, ostream_iterator<double>(cout, " "), is_even_index);
}
void remove_first_and_last_zero(list<int>& L) //zadanide 5
{
    auto first_zero = find(L.begin(), L.end(), 0);
    if (first_zero == L.end()) {
        return;
    }

    auto last_zero = find(L.rbegin(), L.rend(), 0);

    if (first_zero == (--last_zero.base())) {
        L.erase(first_zero);
        return;
    }
    L.erase(first_zero);
    L.erase((++last_zero).base());
}
void processD(deque<int>& D) //zadanide 6
{
    deque<int> D0;
    for (size_t i = 0; i < D.size() / 2; ++i) {
        D0.push_back(D[i]);
    }
    replace_copy_if(D0.rbegin(), D0.rend(), back_inserter(D), [](int x) { return x < 0; }, 0);
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
        cout << "Количество элементов вектора должно быть четным" << endl;
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
        cout << "Количество элементов списка L1 должно быть нечетным" << endl;
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
    case 4:
    {
        printEvenIndexedNumbers();
        break;
    }
    case 5:
    {
        input(L);
        remove_first_and_last_zero(L);
        print(L);
        break;
    }
    case 6:
    {
        cout << "Количество элементов должно быть четным." << endl;
        input(D);
        if (D.size() % 2 != 0)
        {
            cout << "Нечетное количество элементов." << endl;
            break;
        }
        processD(D);
        print(D);
        break;
    }
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    }
}