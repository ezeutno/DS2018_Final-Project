#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "mapText.h"
using namespace std;

class AllMaps {
private:
	ofstream myfileWrite;
	ifstream myfileRead;
	vector<Map> allMap;
public:
	AllMaps();
	void print();
};