#include <iostream>
#include <array>
#include <list>
#include "nav.h"
#include "LinkList.h"
using namespace std;


class Graph {
private:
	NavRoutes main;
	bool cond;
	//created a sorted insertion
	list< list<char> > AllRoutes;
	void insert(list<char> data);
protected:
	void right(NavRoutes main, list<char> list, vector< array<int,2> > points);
	void left(NavRoutes main, list<char> list, vector< array<int, 2> > points);
	void up(NavRoutes main, list<char> list, vector< array<int, 2> > points);
	void down(NavRoutes main, list<char> list, vector< array<int, 2> > points);

public:
	Graph();
	Graph(NavRoutes main);
	bool isRun();
	void run();
	void print();
};