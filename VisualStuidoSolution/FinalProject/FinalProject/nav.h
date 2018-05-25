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
	bool checkColl();
	bool right();
	bool left();
	bool up();
	bool down();
};

NavRoutes::NavRoutes() {
	create();
}

NavRoutes::NavRoutes(Map &data, int start[], int end[]) {
	this->data = data;
	cout << "LOCATION : " << this->data.getLocation() << endl;;
	this->data.run();
	size[0] = this->data.getSize('x');
	size[1] = this->data.getSize('y');
	setStartPoint(start[0], start[1]);
	setEndPoint(end[0], end[1]);
}

void NavRoutes::create() {

}

void NavRoutes::setStartPoint(int x, int y) {
	startPoint[0] = x;
	startPoint[1] = y;
	currPoint[0] = x;
	currPoint[1] = y;
}

void NavRoutes::setEndPoint(int x, int y) {
	endPoint[0] = x;
	endPoint[1] = y;
}

bool NavRoutes::right() {
	if (currPoint[1] + 1 < size[1]) {
		if (!data.getData(currPoint[0], currPoint[1] + 1)) {
			currPoint[1] += 1;
			return true;
		}
	}
	return false;
}

bool NavRoutes::left() {
	if (currPoint[1] - 1 >= 0) {
		if (!data.getData(currPoint[0], currPoint[1] - 1)) {
			currPoint[1] -= 1;
			return true;
		}
	}
	return false;
}

bool NavRoutes::down() {
	if (currPoint[0] + 1 < size[0]) {
		if (!data.getData(currPoint[0] + 1, currPoint[1])) {
			currPoint[0] += 1;
			return true;
		}
	}
	return false;
}

bool NavRoutes::up() {
	if (currPoint[0] - 1 >= 0) {
		if (!data.getData(currPoint[0] - 1, currPoint[1])) {
			currPoint[0] -= 1;
			return true;
		}
	}
	return false;
}

bool NavRoutes::checkColl() {
	return currPoint == endPoint;
}

#endif