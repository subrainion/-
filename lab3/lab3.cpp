#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
using namespace std;
class human //zadanie 1.2
{
	string name;
	int height;
public:
	human(string name, int height) : name(name), height(height) {}
	int getheight() { return height; }
	void print()
	{
		cout << name << ',' << " рост: " << height << endl;
	}
};
class names //zadanide 1.3
{
	string surname;
	string name;
	string patronymic;
public:
	names(string surname, string name, string patronymic) : surname(surname), name(name), patronymic(patronymic) {}
	string print()
	{
		string result;
		if (!surname.empty())
			result += surname + " ";
		if (!name.empty())
			result += name + " ";
		if (!patronymic.empty())
			result += patronymic;
		return result;
	}
};
struct way { //zadanide 3
	string city;
	int cost;

	way(string city, int cost) : city(city), cost(cost) {}
};
class cities
{
	string name;
	vector<way> ways;
public:
	cities(string name) : name(name) {}

	void addway(string city, int cost) 
	{
		ways.push_back(way(city, cost));
	}
	void print()
	{
		cout << "Город: " << name << endl;
		cout << "Связанные города:" << endl;
		for (const auto& way : ways)
		{
			cout << "  " << way.city << ": " << way.cost << endl;
		}
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	cout << "Введите номер задания (1-5):";
	cin >> choice;
	//3
	switch (choice)
	{
	case 1:
		{
		human Cleopatra("Клеопатра", 152);
		human Pushkin("Пушкин", 167);
		human Vladimir("Владимир", 189);
		cout << "1.2" << endl;
		Cleopatra.print();
		Pushkin.print();
		Vladimir.print();
		cout << "1.3" << endl;
		names Cleopatr("", "Клеопатра", "");
		names Pushki("Пушкин", "Александр", "Сергеевич");
		names Vladimi("Маяковский", "Владимир", "");
		cout << Cleopatr.print() << endl;
		cout << Pushki.print() << endl;
		cout << Vladimi.print();
		break;
		}
	case 2:
		{
		names Cleopatra("", "Клеопатра", "");
		names Pushkin("Пушкин", "Александр", "Сергеевич");
		names Vladimir("Маяковский", "Владимир", "");
		human Cle(Cleopatra.print(), 152);
		human Pu(Pushkin.print(), 167);
		human Vla(Vladimir.print(), 189);
		Cle.print();
		Pu.print();
		Vla.print();
		break;
		}
	case 3:
		{
		cities A{ "A" };
		cities B{ "B" };
		cities C{ "C" };
		cities D{ "D" };
		cities E{ "E" };
		cities F{ "F" };
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
		cout << "Введите название города: ";
		cin >> name;
		cities A(name);
		cout << "Введите количество связанных городов(введите '0'  для пропуска): ";
		cin >> count;
		if (count == 0)
		{
			A.print();
			break;
		}
		for (int i = 0; i != count; i++)
		{
			cout << "Введите связанный город и стоимость пути: ";
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