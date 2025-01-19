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
    cout << "������� ���������� ���������: ";
    cin >> size;
    if (size < 1)
    {
        cout << "�������� ���������� ���������";
        exit(1);
    }
    cout << "������� ��������: ";
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
void swapmidel(Container& container) //������� 1
{
    auto mid1 = container.begin();
    advance(mid1, container.size() / 2 - 1);
    auto mid2 = container.begin();
    advance(mid2, container.size() / 2);
    swap(*mid1, *mid2);
}
void insertZeroes(vector<int>& V) //������� 2
{
    V.insert(V.begin() + V.size() / 2, 5, 0);
}
void insertmid(list<int>& L1, list<int>& L2) //������� 3
{
    auto mid = L1.begin();
    advance(mid, L1.size() / 2);
    L2.splice(L2.end(), L1, mid, next(mid));
}
void printEvenIndexedNumbers() //zadanie 4
{
    cout << "������� ����� ������������ ����� (��� ���������� ����� ������� ���������� ��������):" << endl;

    // ���������� istream_iterator ��� ������ ����� �� ������������ �����
    istream_iterator<double> start(cin), end;

    int index = 0;

    // ������-��������� ��� ���������� ������ ��������
    auto is_even_index = [&index](double) mutable {
        return (index++ % 2) != 1; // ���������� true ��� �������� ��������
        };

    // ���������� remove_copy_if ��� ����������� ������ ������ �������� � �������� �����
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
    cout << "������� ����� ������� (1-10):" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "������ �������� ��������� �������� �� ����� ���� ���������, ���������� ��������� �������� ������" << endl;
        cout << "���� ������ ��� �������:" << endl;
        input(V);
        if ((V.size() % 2 != 0) || (V.size() < 2))
        {
            cout << "���������� ��������� ������ ���� ������ � �� ����� ����";
            break;
        }
        cout << "���� ������ ��� ����:" << endl;
        input(D);
        if ((D.size() % 2 != 0) || (D.size() < 2))
        {
            cout << "���������� ��������� ������ ���� ������ � �� ����� ����"; 
            break;
        }
        cout << "���� ������ ��� ������:" << endl;
        input(L);
        if ((L.size() % 2 != 0) || (L.size() < 2))
        {
            cout << "���������� ��������� ������ ���� ������ � �� ����� ����";
            break;
        }
        swapmidel(V);
        cout << "���������� ������:" << endl;
        print(V);
        swapmidel(D);
        cout << "���������� ���:" << endl;
        print(D);
        swapmidel(L);
        cout << "���������� ������:" << endl;
        print(L); break;
    case 2:
        cout << "���������� ��������� ������� ������ ���� ������" << endl;
        cout << "���� ������ ��� �������:" << endl;
        input(V);
        if ((V.size() % 2 != 0) || (V.size() < 2))
        {
            cout << "���������� ��������� ������ ���� ������"; break;
        }
        insertZeroes(V);
        cout << "���������� ������:" << endl;
        print(V); 
        break;
    case 3:
        cout << "���������� ��������� ������ L1 ������ ���� ��������" << endl;
        cout << "���� ������ ��� ������ L1:" << endl;
        input(L);
        if ((L.size() % 2 == 0) || (L.size() < 0))
        {
            cout << "���������� ��������� ������ ���� �������� � �� ����� ����";
            break;
        }
        cout << "���� ������ ��� ������ L2:" << endl;
        input(L2);
        insertmid(L, L2);
        cout << "���������� ������ L1:" << endl;
        print(L);
        cout << "���������� ������ L2:" << endl;
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
        cout << "���������� ��������� ������ ���� ������." << endl;
        input(D);
        if (D.size() % 2 != 0)
        {
            cout << "�������� ���������� ���������." << endl;
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