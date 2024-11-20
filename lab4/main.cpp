#include <iostream>
#include <limits>
#include "Time.h"
using namespace std;
void create()
{
    cout << "������� �����, ����(0-23 � ������(0-59): ";
}
bool valid()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������ �����: ��������� ������������ �����.";
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
        cout << "������: ���� � ������ ������ ���� � ��������� 0-23 � 0-59 ��������������." << endl;
        return 1;
    }
    Time time(hours, minutes);
    do
	{
        cout << "�������� ��������:" << endl;
        cout << "1. ������� ������� �����" << endl;
        cout << "2. ��������� �����" << endl;
        cout << "3. ������������" << endl;
        cout << "4. ��������� ����� � �����" << endl;
        cout << "5. ��������� �����" << endl;
        cout << "6. ���������� �����" << endl;
        cout << "7. ���� � ������ �� ����� ����" << endl;
        cout << "8. �������� ����� � ����� ������ �������� ����� ��������������� ��������� ������� ��������?" << endl;
        cout << "9. �������� ����� � ����� ������ �������� �� ����� ��������������� ��������� ������� ��������?" << endl;
        cout << "0. �����" << endl;
        cout << "��������:";
		cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "������! ������� ���������� ����� ��� ������ ��������.\n";
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            cout << "�����: " << time << endl;
            break;
        }
        case 2:
        {
            cout << "������� ���������� ����� ��� ���������: ";
            unsigned int mins;
            cin >> mins;
            Time time1 = time.subtraction(mins);
            cout << "����� ����� ��������� �����: " << time1 << endl;
            break;
        }
        case 3:
        {
            cout << "������������ �������������:" << endl;

            Time defaultT;
            cout << "����������� �� ���������: " << defaultT << endl;

            Time paramT(11, 11);
            cout << "����������� � ����������� (11, 11): " << paramT << endl;

            Time copyT(paramT);
            cout << "����������� �����������: " << copyT << endl;
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
            cout << "����: " << hoursOnly << endl;
            break;
        }
        case 7:
        {
            bool isNonZero = static_cast<bool>(time);
            cout << "����� �� ����� ����: " << (isNonZero ? "true" : "false") << endl;
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
                cout << "������: ���� � ������ ������ ���� � ��������� 0-23 � 0-59 ��������������." << endl;
                return 1;
            }
            Time time1(hours, minutes);
            if (time == time1)
                cout << "�������� ����� � ����� ������ �������� ����� ��������������� ��������� ������� ��������" << endl;
            else
                cout << "�������� ����� � ����� ������ �������� �� ����� ��������������� ��������� ������� ��������" << endl;
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
                cout << "������: ���� � ������ ������ ���� � ��������� 0-23 � 0-59 ��������������." << endl;
                return 1;
            }
            Time time1(hours, minutes);
            if (time != time1)
                cout << "�������� ����� � ����� ������ �������� �� ����� ��������������� ��������� ������� ��������" << endl;
            else
                cout << "�������� ����� � ����� ������ �������� ����� ��������������� ��������� ������� ��������" << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "�������� ��������" << endl;
            break;
        }
	} while (choice != 0);
}