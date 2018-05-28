#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mapText.h"
#include "LinkList.h"
using namespace std;

class AllMaps {
private:
	ofstream myfileWrite;
	ifstream myfileRead;
	linkedlistADT<Map> allMap;
public:
	AllMaps();
};