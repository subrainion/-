#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
using namespace std;
class Human //zadanie 1.2
{
	string name;
	int height;
public:
	Human(string name, int height) : name(name), height(height) {}
	int getheight() { return height; }
	void print()
	{
		cout << name << ',' << " рост: " << height << endl;
	}
};