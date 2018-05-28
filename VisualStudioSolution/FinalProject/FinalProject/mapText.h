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
protected:
	void create();
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
	void operator=(const Map & a);
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

void Map::create() {
	string filename;
	int x, y;
	try {
		cout << "Please insert file name : ";
		getline(cin, filename);
		cout << "Please input x dimention: ";
		cin >> x;
		cout << "Please input y dimention: ";
		cin >> y;
	}
	catch(const char* msg){
		cout << msg << endl;
	}
	


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
	}else {
		cout << "An Error Occured : File isn't openning!" << endl;;
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

void Map::operator=(const Map & a) {
	this->location = a.location;
	this->name = a.name;
	if (a.runCond){
		this->run();
	}
}

bool Map::getData(int x, int y) {
	if (x < data.size()) {
		if (y < data[x].size()) {
			return data[x][y];
		}
	}
	return false;
}

void Map::setName(string name){
	this->name = name;
}

void Map::setLocation(string loc){
	this->location = loc;
}

int Map::getSize(char position) {
	if (position == 'x') {
		return this->data.size();
	}else if (position == 'y') {
		return this->data[0].size();
	}else {
		return -1;
	}

}

string Map::getLocation() {
	return this->location;
}

string Map::getName() {
	return name;
}

#endif