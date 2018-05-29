#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "mapText.h"
using namespace std;

#ifndef AllMaps_H
#define AllMaps_H

class AllMaps {
private:
	ofstream myfileWrite;
	ifstream myfileRead;
	vector<Map> allMap;
	bool cond;
public:
	AllMaps();
	bool isRun();
	void run();
	void insert(Map&);
	size_t size();
	Map getData(int i);
	void print();
};

#endif 


