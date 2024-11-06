#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
#include "Names.h"
using namespace std;

Names::Names(string surname, string name, string patronymic) : surname(surname), name(name), patronymic(patronymic) {}
string Names::print()
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