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
	string getName();
	bool isRun();
	bool getData(int x, int y);
	void setName(string name);
	void setLocation(string loc);
	int getSize(char position);
	string getLocation();
	void run();
	void edit();
	void save();
	void print(char = '*', int = 1);
	Map& operator=(const Map & a);
};

Map::Map() {
	runCond = false;
}

Map::Map(string loc, string name) {
	runCond = false;
	location = loc;
	this->name = name;
}

bool Map::isRun() {
	return runCond;
}

void Map::run() {
	runCond = true;
	myfileRead.open(location.c_str());
	if (myfileRead.is_open()) {
		string line;
		while (getline(myfileRead, line)) {
			vector<bool> tempLine;
			for (int i = 0; i<line.length(); i++) {
				if (line.at(i) == '0') {
					tempLine.push_back(false);
				}
				else {
					tempLine.push_back(true);
				}
			}
			data.push_back(tempLine);
		}
		myfileRead.close();
	}
}

void Map::print(char block, int border) {
	vector< vector<bool> >::iterator i;
	vector<bool>::iterator a;
	//name	
	cout << "Problem Name : " << this->name << endl;
	//border
	for (int c = 0; c<border; c++) {
		for (a = data[0].begin(); a != data[0].end(); ++a) cout << "-";
		for (int d = 0; d<border; d++) cout << "--";
		cout << endl;
	}
	for (i = data.begin(); i != data.end(); ++i) {
		vector<bool> res = *i;
		for (int d = 0; d<border; d++) cout << "|";
		for (a = res.begin(); a != res.end(); ++a) {
			if (*a) cout << block;
			else cout << ' ';
		}
		for (int d = 0; d<border; d++) cout << "|";
		cout << endl;
	}
	//border
	for (int c = 0; c<border; c++) {
		for (a = data[0].begin(); a != data[0].end(); ++a) cout << "-";
		for (int d = 0; d<border; d++) cout << "--";
		cout << endl;
	}
}

Map& Map::operator=(const Map & a) {
	Map newMap(a.location,a.name);
	return newMap;
}

bool Map::getData(int x, int y) {
	if (x < data.size()) {
		if (y < data[x].size() ) {
			return data[x][y];
		}
	}
	return false;
}

int Map::getSize(char position) {
	if (position == 'x')  {
		return this->data.size();
	}else if(position == 'y'){
		return -1;
		return this->data[0].size();
	}else {
		return -1;
	}
		
}

string Map::getLocation(){
	return this->location;
}

string Map::getName() {
	return name;
}

#endif
