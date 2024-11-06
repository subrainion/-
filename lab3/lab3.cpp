#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
#include "Human.cpp"
#include "Names.cpp"
#include "Cities.cpp"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	cout << "������� ����� ������� (1-5):";
	cin >> choice;
	//3
	switch (choice)
	{
	case 1:
		{
		Human Cleopatra("���������", 152);
		Human Pushkin("������", 167);
		Human Vladimir("��������", 189);
		cout << "1.2" << endl;
		Cleopatra.print();
		Pushkin.print();
		Vladimir.print();
		cout << "1.3" << endl;
		Names Cleopatr("", "���������", "");
		Names Pushki("������", "���������", "���������");
		Names Vladimi("����������", "��������", "");
		cout << Cleopatr.print() << endl;
		cout << Pushki.print() << endl;
		cout << Vladimi.print();
		break;
		}
	case 2:
		{
		Names Cleopatra("", "���������", "");
		Names Pushkin("������", "���������", "���������");
		Names Vladimir("����������", "��������", "");
		Human Cle(Cleopatra.print(), 152);
		Human Pu(Pushkin.print(), 167);
		Human Vla(Vladimir.print(), 189);
		Cle.print();
		Pu.print();
		Vla.print();
		break;
		}
	case 3:
		{
		Cities A{ "A" };
		Cities B{ "B" };
		Cities C{ "C" };
		Cities D{ "D" };
		Cities E{ "E" };
		Cities F{ "F" };
		A.addway("B", 5);
		A.addway("F", 1);
		A.addway("D", 6);
		B.addway("A", 5);
		B.addway("C", 3);
		C.addway("B", 3);
		C.addway("D", 4);
		D.addway("C", 4);
		D.addway("A", 6);
		D.addway("E", 2);
		E.addway("F", 2);
		F.addway("E", 2);
		A.print();
		B.print();
		C.print();
		D.print();
		E.print();
		F.print();
		break;
		}
	case 4:
	{
		string name, link;
		int cost, count;
		cout << "������� �������� ������: ";
		cin >> name;
		Cities A(name);
		cout << "������� ���������� ��������� �������(������� '0'  ��� ��������): ";
		cin >> count;
		if (count == 0)
		{
			A.print();
			break;
		}
		for (int i = 0; i != count; i++)
		{
			cout << "������� ��������� ����� � ��������� ����: ";
			cin >> link >> cost;
			A.addway(link, cost);
		};
		A.print();
		break;
		}
	case 5:
		{
		break;
		}
	}
}