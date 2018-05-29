#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#ifndef mapText_h
#define mapText_h

class Map {
private:
	string name;
	string location;
	bool runCond;
	ofstream myfileWrite;
	ifstream myfileRead;
	vector< vector<bool> > data;
public:
	Map();
	Map(string loc, string = "Problem");
	Map(const Map& data);
	string getName();
	bool isRun();
	void run();
	bool getData(int x, int y);
	void setName(string name);
	void setLocation(string loc);
	int getSize(char position);
	string getLocation();
	void create();
	void print(char = '*', int = 1);
	void operator=(Map & a);
	friend ofstream & operator<<(ofstream &, Map & b);
	friend ostream & operator<<(ostream &, Map & b);
};

#endif