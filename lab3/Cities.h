#ifndef CITIES_H
#define CITIES_H

#include <string>
#include <vector>
using namespace std;

class Cities
{
	struct Way { //zadanide 3
		string city;
		int cost;
	public:
		Way(string city, int cost);
	};
	string name;
	vector<Way> ways;

public:
	Cities(string name);

	void addway(string city, int cost);
	void print();
};
#endif // !CITIES_H
