#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
using namespace std;
class human //zadanie 1.2
{
public:
	string name;
	int height;
	void print();
};
void human::print()
{
	cout << name << ',' << " ����: " << height << endl;
}
class names //zadanide 1.3
{
public:
	string surname;
	string name;
	string patronymic;
	void print();
};
void names::print()
{
	if (surname.empty())
		cout << name << patronymic << endl;
	if (patronymic.empty())
		cout << surname << name << endl;
	else
		cout << surname << name << patronymic << endl;
}
class humanwithname //zadanide 2.2
{
public:
	string name;
	int height;

	humanwithname(string name, int height) : name(name), height(height) {}

	string ToString() const {
		return name + ", ����: " + to_string(height);
	}
};
struct ���� { //zadanide 3
	string �����;
	int ���������;

	����(string �����, int ���������) : �����(�����), ���������(���������) {}
};
class cities
{
public:
	string ��������;
	vector<����> ����;
	void print();

	cities(string ��������) : ��������(��������) {}

	void ������������(string �����, int ���������) 
	{
		����.push_back(����(�����, ���������));
	}
};
void cities::print()
{
	cout << "�����: " << �������� << endl;
	cout << "��������� ������:" << endl;
	for (const auto& ���� : ����) {
		cout << "  " << ����.����� << ": " << ����.��������� << endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	cout << "������� ����� ������� (1-5):";
	cin >> choice;
	//1.2
	human Cleopatra{ "���������", 152 };
	human Pushkin{ "������", 167 };
	human Vladimir{ "��������", 189 };
	//1.3
	names Cleopatr{ "���������"};
	names Pushki{ "������ ", "��������� ", "���������"};
	names Vladimi{ "���������� ", "��������"};
	//3
	cities A{ "A" };
	cities B{ "B" };
	cities C{ "C" };
	cities D{ "D" };
	cities E{ "E" };
	cities F{ "F" };
	A.������������("B", 5);
	A.������������("F", 1);
	A.������������("D", 6);
	B.������������("A", 5);
	B.������������("C", 3);
	C.������������("B", 3);
	C.������������("D", 4);
	D.������������("C", 4);
	D.������������("A", 6);
	D.������������("E", 2);
	E.������������("F", 2);
	F.������������("E", 2);
	switch (choice)
	{
	case 1:
		Cleopatra.print();
		Pushkin.print();
		Vladimir.print();
		Cleopatr.print();
		Pushki.print();
		Vladimi.print();
		break;
	case 2:
		break;
	case 3:
		A.print();
		B.print();
		C.print();
		D.print();
		E.print();
		F.print();
		break;
	case 4:
		break;
	case 5:

		break;
	}
}