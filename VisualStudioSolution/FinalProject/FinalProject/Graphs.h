#include <iostream>
#include <array>
#include "nav.h"
#include "LinkList.h"
using namespace std;

class Graph {
private:
	NavRoutes main;
	bool cond;
	//created a sorted insertion
	linkedlistADT< linkedlistADT<char> > AllRoutes;
	void insert(linkedlistADT<char> data);
protected:
	void right(NavRoutes main, linkedlistADT<char> list, vector< array<int,2> > points);
	void left(NavRoutes main, linkedlistADT<char> list, vector< array<int, 2> > points);
	void up(NavRoutes main, linkedlistADT<char> list, vector< array<int, 2> > points);
	void down(NavRoutes main, linkedlistADT<char> list, vector< array<int, 2> > points);

public:
	Graph();
	Graph(NavRoutes main);
	bool isRun();
	void run();
	void print();
};