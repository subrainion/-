#include <iostream>
#include "Time.h"
using namespace std;
void create()
{
    cout << "������� �����, ����(0-23 � ������(0-59): ";
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
        cout << "�������� ��������:" << endl;
        cout << "1. ������� �����" << endl;
        cout << "2. ��������� �����" << endl;
        cout << "3. ������������" << endl;
        cout << "4. ��������� ����� � �����" << endl;
        cout << "5. ��������� �����" << endl;
        cout << "6. ���������� �����" << endl;
        cout << "7. ���� � ������ �� ����� ����" << endl;
        cout << "8. �������� ����� � ����� ������ �������� ����� ��������������� ��������� ������� ��������" << endl;
        cout << "9. �������� ����� � ����� ������ �������� �� ����� ��������������� ��������� ������� ��������" << endl;
        cout << "0. �����" << endl;
        cout << "��������:";
		cin >> choice;
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
                cout << "�������� ����� � ����� ������ �������� ����� ��������������� ��������� ������� ��������";
            else
                cout << "�������� ����� � ����� ������ �������� �� ����� ��������������� ��������� ������� ��������";
            break;
        }
        case 9:
        {
            create();
            cin >> hours >> minutes;
            Time time1(hours, minutes);
            if (time != time1)
                cout << "�������� ����� � ����� ������ �������� �� ����� ��������������� ��������� ������� ��������";
            else
                cout << "�������� ����� � ����� ������ �������� ����� ��������������� ��������� ������� ��������";
            break;
        }
        default:
            break;
        }
	} while (choice != 0);
}