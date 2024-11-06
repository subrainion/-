#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <vector>
using namespace std;
struct Way { //zadanide 3
	string city;
	int cost;

	Way(string city, int cost) : city(city), cost(cost) {}
};
class Cities
{
	string name;
	vector<Way> ways;
public:
	Cities(string name) : name(name) {}

	void addway(string city, int cost)
	{
		ways.push_back(Way(city, cost));
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