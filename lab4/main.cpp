#include <iostream>
#include <limits>
#include "Time.h"
using namespace std;
void create()
{
    cout << "Введите время, часы(0-23 и минуты(0-59): ";
}
bool valid()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода: требуется использвание чисел.";
        return false;
    }
    return true;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	short int hours;
	short int minutes;
	int choice;
    create();
    cin >> hours >> minutes;
    if (!valid()) {
        return 1;
    }
    if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
        cout << "Ошибка: часы и минуты должны быть в диапазоне 0-23 и 0-59 соответственно." << endl;
        return 1;
    }
    Time time(hours, minutes);
    do
	{
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести текущее время" << endl;
        cout << "2. Вычитание минут" << endl;
        cout << "3. Конструкторы" << endl;
        cout << "4. Обнуление часов и минут" << endl;
        cout << "5. Обнуление минут" << endl;
        cout << "6. Количество часов" << endl;
        cout << "7. Часы и минуты не равны нулю" << endl;
        cout << "8. Значение часов и минут левого операнда равно соответствующим значениям правого операнда?" << endl;
        cout << "9. Значение часов и минут левого операнда не равно соответствующим значениям правого операнда?" << endl;
        cout << "0. Выход" << endl;
        cout << "Действие:";
		cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите корректное число для выбора действия.\n";
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            cout << "Время: " << time << endl;
            break;
        }
        case 2:
        {
            cout << "Введите количество минут для вычитания: ";
            unsigned int mins;
            cin >> mins;
            Time time1 = time.subtraction(mins);
            cout << "Время после вычитания минут: " << time1 << endl;
            break;
        }
        case 3:
        {
            cout << "Демонстрация конструкторов:" << endl;

            Time defaultT;
            cout << "Конструктор по умолчанию: " << defaultT << endl;

            Time paramT(11, 11);
            cout << "Конструктор с параметрами (11, 11): " << paramT << endl;

            Time copyT(paramT);
            cout << "Конструктор копирования: " << copyT << endl;
            break;
        }
        case 4:
        {
            -time;
            cout << time << endl;
            break;
        }
        case 5:
        {
            time--;
            cout << time << endl;
            break;
        }
        case 6:
        {
            short int hoursOnly = time;
            cout << "Часы: " << hoursOnly << endl;
            break;
        }
        case 7:
        {
            bool isNonZero = static_cast<bool>(time);
            cout << "Время не равно нулю: " << (isNonZero ? "true" : "false") << endl;
            break;
        }
        case 8:
        {
            create();
            cin >> hours >> minutes;
            if (!valid()) {
                return 1;
            }
            if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
                cout << "Ошибка: часы и минуты должны быть в диапазоне 0-23 и 0-59 соответственно." << endl;
                return 1;
            }
            Time time1(hours, minutes);
            if (time == time1)
                cout << "Значение часов и минут левого операнда равно соответствующим значениям правого операнда" << endl;
            else
                cout << "Значение часов и минут левого операнда не равно соответствующим значениям правого операнда" << endl;
            break;
        }
        case 9:
        {
            create();
            cin >> hours >> minutes;
            if (!valid()) {
                return 1;
            }
            if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
                cout << "Ошибка: часы и минуты должны быть в диапазоне 0-23 и 0-59 соответственно." << endl;
                return 1;
            }
            Time time1(hours, minutes);
            if (time != time1)
                cout << "Значение часов и минут левого операнда не равно соответствующим значениям правого операнда" << endl;
            else
                cout << "Значение часов и минут левого операнда равно соответствующим значениям правого операнда" << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Неверное действие" << endl;
            break;
        }
	} while (choice != 0);
}