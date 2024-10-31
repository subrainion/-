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
	cout << name << ',' << " рост: " << height << endl;
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
		return name + ", рост: " + to_string(height);
	}
};
struct Путь { //zadanide 3
	string Город;
	int Стоимость;

	Путь(string город, int стоимость) : Город(город), Стоимость(стоимость) {}
};
class cities
{
public:
	string Название;
	vector<Путь> Пути;
	void print();

	cities(string название) : Название(название) {}

	void ДобавитьПуть(string город, int стоимость) 
	{
		Пути.push_back(Путь(город, стоимость));
	}
};
void cities::print()
{
	cout << "Город: " << Название << endl;
	cout << "Связанные города:" << endl;
	for (const auto& путь : Пути) {
		cout << "  " << путь.Город << ": " << путь.Стоимость << endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	cout << "Введите номер задания (1-5):";
	cin >> choice;
	//1.2
	human Cleopatra{ "Клеопатра", 152 };
	human Pushkin{ "Пушкин", 167 };
	human Vladimir{ "Владимир", 189 };
	//1.3
	names Cleopatr{ "Клеопатра"};
	names Pushki{ "Пушкин ", "Александр ", "Сергеевич"};
	names Vladimi{ "Маяковский ", "Владимир"};
	//3
	cities A{ "A" };
	cities B{ "B" };
	cities C{ "C" };
	cities D{ "D" };
	cities E{ "E" };
	cities F{ "F" };
	A.ДобавитьПуть("B", 5);
	A.ДобавитьПуть("F", 1);
	A.ДобавитьПуть("D", 6);
	B.ДобавитьПуть("A", 5);
	B.ДобавитьПуть("C", 3);
	C.ДобавитьПуть("B", 3);
	C.ДобавитьПуть("D", 4);
	D.ДобавитьПуть("C", 4);
	D.ДобавитьПуть("A", 6);
	D.ДобавитьПуть("E", 2);
	E.ДобавитьПуть("F", 2);
	F.ДобавитьПуть("E", 2);
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