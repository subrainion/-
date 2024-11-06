#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
#include "Cities.h"
using namespace std;

Cities::Way::Way(string city, int cost) : city(city), cost(cost) {}
Cities::Cities(string name) : name(name) {}
void Cities::addway(string city, int cost)
{
	ways.push_back(Way(city, cost));
}
void Cities::print()
{
	cout << "Город: " << name << endl;
	cout << "Связанные города:" << endl;
	for (const auto& way : ways)
	{
		cout << "  " << way.city << ": " << way.cost << endl;
	}
}