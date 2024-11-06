#ifndef NAMES_H
#define NAMES_H

#include <string>
using namespace std;

class Names //zadanide 1.3
{
	string surname;
	string name;
	string patronymic;
public:
	Names(string surname, string name, string patronymic);
	string print();
};
#endif // !NAMES_H
