#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
using namespace std;
class Names //zadanide 1.3
{
	string surname;
	string name;
	string patronymic;
public:
	Names(string surname, string name, string patronymic) : surname(surname), name(name), patronymic(patronymic) {}
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