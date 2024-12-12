#include <iostream>
#include "List.h"
#include "DList.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    List list1;
    List list2;
    int n, x, i, choice;
    cout << "������� ����� �������:";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        // ���������� ������� ������
        cout << "������� ���������� ��������� � ������ ������:";
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cout << "������� ������� ��� ����������:";
            cin >> x;
            list1.add(x);
        }

        // ���������� ������� ������
        cout << "������� ���������� ��������� �� ������ ������:";
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cout << "������� ������� ��� ����������:";
            cin >> x;
            list2.add(x);
        }

        // ����� �������
        cout << "������ L1: ";
        list1.print();
        cout << "������ L2: ";
        list2.print();

        // ������������ ������ ������ L
        List L = List::createListFromDifference(list1, list2);
        cout << "������ L (L1 - L2): ";
        L.print();
        break;
    }

    case 2:
    {
        DList dll;
        cout << "������� ���������� ��������� � ������:";
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cout << "������� ������� ��� ����������:";
            cin >> x;
            dll.add(x);
        }

        int i, j;
        cout << "������� ������ � ����� ������� ������ (i<j):";
        cin >> i >> j;

        if (dll.isSymmetric(i, j)) {
            cout << "������� ������ � i-�� �� j-� ������� �����������" << endl;
        }
        else {
            cout << "������� ������ � i-�� �� j-� ������� �������������" << endl;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}
