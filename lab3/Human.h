#ifndef HUMAN_H
#define HUMAN_H

#include <string>
using namespace std;
class Human //zadanie 1.2
{
	string name;
	int height;
public:
	Human(string name, int height);
	void print();
};
#endif // !HUMAN_H
