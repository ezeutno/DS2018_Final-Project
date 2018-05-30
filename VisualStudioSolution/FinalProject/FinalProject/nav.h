#include <iostream>
#include <list>
#include <array>
#include <windows.h>
#include "mapText.h"
using namespace std;

#ifndef nav_h
#define nav_h

class NavRoutes {
private:
	Map data;
	int size[2];
	int startPoint[2];
	int currPoint[2];
	int endPoint[2];
public:
	NavRoutes();
	NavRoutes(Map &data);
	NavRoutes(Map & data, int start[], int end[]);
	void setStartPoint(int x, int y);
	void setEndPoint(int x, int y);
	
	int const getX();
	int const getY();
	Map getMap();
	int getSX();
	int getSY();
	int getEX();
	int getEY();
	
	bool checkColl();

	bool right();
	bool left();
	bool up();
	bool down();

	void print(list<char> listdata);
};

#endif