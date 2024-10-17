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
    cout << "������� ���������� ���������: ";
    cin >> size;
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
    }
}