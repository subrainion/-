#include <iostream>
#include "Time.h"
using namespace std;
void create()
{
    cout << "¬ведите врем€, часы(0-23 и минуты(0-59): ";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	short int hours;
	short int minutes;
	int choice;
    create();
    cin >> hours >> minutes;
    Time time(hours, minutes);
    do
	{
        cout << "¬ыберите действие:" << endl;
        cout << "1. ¬ывести врем€" << endl;
        cout << "2. ¬ычитание минут" << endl;
        cout << "3.  онструкторы" << endl;
        cout << "4. ќбнуление часов и минут" << endl;
        cout << "5. ќбнуление минут" << endl;
        cout << "6.  оличество часов" << endl;
        cout << "7. „асы и минуты не равны нулю" << endl;
        cout << "8. «начение часов и минут левого операнда равно соответствующим значени€м правого операнда" << endl;
        cout << "9. «начение часов и минут левого операнда не равно соответствующим значени€м правого операнда" << endl;
        cout << "0. ¬ыход" << endl;
        cout << "ƒействие:";
		cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "¬рем€: " << time << endl;
            break;
        }
        case 2:
        {
            cout << "¬ведите количество минут дл€ вычитани€: ";
            unsigned int mins;
            cin >> mins;
            Time time1 = time.subtraction(mins);
            cout << "¬рем€ после вычитани€ минут: " << time1 << endl;
            break;
        }
        case 3:
        {
            cout << "ƒемонстраци€ конструкторов:" << endl;

            Time defaultT;
            cout << " онструктор по умолчанию: " << defaultT << endl;

            Time paramT(11, 11);
            cout << " онструктор с параметрами (11, 11): " << paramT << endl;

            Time copyT(paramT);
            cout << " онструктор копировани€: " << copyT << endl;
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {
            create();
            cin >> hours >> minutes;
            Time time1(hours, minutes);
            if (time == time1)
                cout << "«начение часов и минут левого операнда равно соответствующим значени€м правого операнда";
            else
                cout << "«начение часов и минут левого операнда не равно соответствующим значени€м правого операнда";
            break;
        }
        case 9:
        {
            create();
            cin >> hours >> minutes;
            Time time1(hours, minutes);
            if (time != time1)
                cout << "«начение часов и минут левого операнда не равно соответствующим значени€м правого операнда";
            else
                cout << "«начение часов и минут левого операнда равно соответствующим значени€м правого операнда";
            break;
        }
        default:
            break;
        }
	} while (choice != 0);
}