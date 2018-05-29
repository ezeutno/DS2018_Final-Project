#include "Graphs.h"

void Graph::insert(linkedlistADT<char> data){
	linkedlistADT< linkedlistADT<char> >::iterator iter;
	linkedlistADT< linkedlistADT<char> >::iterator before;
	before = AllRoutes.begin();
	bool newtempCond = false;
	for (iter = AllRoutes.begin(); iter != AllRoutes.end(); iter++) {
		linkedlistADT<char> newdata = *iter;
		if (newdata.size()> data.size()) {
			AllRoutes.insert(before, data);
			newtempCond = true;
			break;
		}else before++;
	}
	if (AllRoutes.size() == 0 || !newtempCond) {
		AllRoutes.push_back(data);
	}
}

void Graph::right(NavRoutes main, linkedlistADT<char> list, vector<array<int, 2>> points) {
	if (main.right()) {
		if (main.checkColl()) {
			insert(list);
		}else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				list.push_back('r');
				right(main, list, points);
				down(main, list, points);
				up(main, list, points);
			}
		}
	}
}

void Graph::left(NavRoutes main, linkedlistADT<char> list, vector<array<int, 2>> points){
	if (main.left()) {
		if (main.checkColl()) {
			insert(list);
		}
		else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				list.push_back('l');
				left(main, list, points);
				down(main, list, points);
				up(main,list, points);
			}
		}
	}
}

void Graph::up(NavRoutes main, linkedlistADT<char> list, vector<array<int, 2>> points){
	if (main.up()) {
		if (main.checkColl()) {
			insert(list);
		}
		else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				list.push_back('u');
				right(main, list, points);
				left(main,list, points);
				up(main,list, points);
			}
		}
	}
}

void Graph::down(NavRoutes main, linkedlistADT<char> list, vector<array<int, 2>> points){
	if (main.down()) {
		if (main.checkColl()) {
			insert(list);
		}
		else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				list.push_back('d');
				right(main, list, points);
				down(main, list, points);
				left(main, list, points);
			}
		}
	}
}

Graph::Graph(){
	cond = false;
}

Graph::Graph(NavRoutes main){
	this->main = main;
	cond = false;
}

bool Graph::isRun(){
	return cond;
}

void Graph::run(){
	cond = true;
	linkedlistADT<char> movements;
	vector<array<int,2>> points;
	cout << "RIGHT" << endl;
	right(main, movements, points);
	cout << "LEFT" << endl;
	left(main, movements, points);
	cout << "DOWN" << endl;
	down(main, movements, points);
	cout << "UP" << endl;
	up(main, movements, points);
}

void Graph::print(){
	linkedlistADT< linkedlistADT<char> >::iterator iter;
	cout <<"SIZE : "<< AllRoutes.size() << endl;
	for (iter = AllRoutes.begin(); iter != AllRoutes.end(); iter++) {
		linkedlistADT<char> newdata = *iter;
		linkedlistADT<char>::iterator newiter;
		for (newiter = newdata.begin(); newiter != newdata.end(); newiter++) {
			cout << *newiter << "-";
		}
		cout << endl;
	}
}
