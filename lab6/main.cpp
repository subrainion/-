#include <iostream>
#include "List.h"
#include "DList.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    List list1;
    List list2;
    int n, x, i, choice;
    cout << "Введите номер задания:";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        // Заполнение первого списка
        cout << "Введите количество элементов в первом списке:";
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cout << "Введите элемент для добавления:";
            cin >> x;
            list1.add(x);
        }

        // Заполнение второго списка
        cout << "Введите количество элементов во втором списке:";
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cout << "Введите элемент для добавления:";
            cin >> x;
            list2.add(x);
        }

        // Вывод списков
        cout << "Список L1: ";
        list1.print();
        cout << "Список L2: ";
        list2.print();

        // Формирование нового списка L
        List L = List::createListFromDifference(list1, list2);
        cout << "Список L (L1 - L2): ";
        L.print();
        break;
    }

    case 2:
    {
        DList dll;
        cout << "Введите количество элементов в списке:";
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cout << "Введите элемент для добавления:";
            cin >> x;
            dll.add(x);
        }

        int i, j;
        cout << "Введите начало и конец участка списка (i<j):";
        cin >> i >> j;

        if (dll.isSymmetric(i, j)) {
            cout << "Участок списка с i-го по j-й элемент симметричен" << endl;
        }
        else {
            cout << "Участок списка с i-го по j-й элемент несимметричен" << endl;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}
