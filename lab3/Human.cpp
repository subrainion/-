#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
#include "Human.h"
using namespace std; //zadanie 1.2

Human::Human(string name, int height) : name(name), height(height) {}
void Human::print()
{
	cout << name << ',' << " рост: " << height << endl;
}