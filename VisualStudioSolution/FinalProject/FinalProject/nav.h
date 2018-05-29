#include <iostream>
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
protected:
	void create();
public:
	NavRoutes();
	NavRoutes(Map & data, int start[], int end[]);
	void setStartPoint(int x, int y);
	void setEndPoint(int x, int y);
	
	int getX();
	int getY();
	
	bool checkColl();

	bool right();
	bool left();
	bool up();
	bool down();
};

#endif