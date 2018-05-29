#include "Graphs.h"

void Graph::insert(list<char> data){
	list< list<char> >::iterator iter;
	list< list<char> >::iterator before;
	before = AllRoutes.begin();
	bool newtempCond = false;
	for (iter = AllRoutes.begin(); iter != AllRoutes.end(); iter++) {
		list<char> newdata = *iter;
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

void Graph::right(NavRoutes main, list<char> listData, vector<array<int, 2>> points) {
	if (main.right()) {
		if (main.checkColl()) {
			listData.push_back('r');
			insert(listData);
		}else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				listData.push_back('r');
				right(main, listData, points);
				down(main, listData, points);
				up(main, listData, points);
			}
		}
	}
}

void Graph::left(NavRoutes main, list<char> listData, vector<array<int, 2>> points){
	if (main.left()) {
		if (main.checkColl()) {
			listData.push_back('l');
			insert(listData);
		}
		else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				listData.push_back('l');
				left(main, listData, points);
				down(main, listData, points);
				up(main, listData, points);
			}
		}
	}
}

void Graph::up(NavRoutes main, list<char> listData, vector<array<int, 2>> points){
	if (main.up()) {
		if (main.checkColl()) {
			listData.push_back('u');
			insert(listData);
		}
		else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				listData.push_back('u');
				right(main, listData, points);
				left(main, listData, points);
				up(main, listData, points);
			}
		}
	}
}

void Graph::down(NavRoutes main, list<char> listData, vector<array<int, 2>> points){
	if (main.down()) {
		if (main.checkColl()) {
			listData.push_back('d');
			insert(listData);
		}
		else {
			bool newcond = false;
			for (int i = 0; i < points.size(); i++) {
				if (main.getX() == points[i][0] && main.getY() == points[i][1]) newcond = true;
			}
			if (!newcond) {
				points.push_back({ main.getX() ,main.getY() });
				listData.push_back('d');
				right(main, listData, points);
				down(main, listData, points);
				left(main, listData, points);
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

void Graph::start(){
	iter = AllRoutes.begin();
}

bool Graph::has_next(){
	return iter != AllRoutes.end();
}

void Graph::next(){
	++iter;
}

list<char> Graph::getCurrentList(){
	return *iter;
}

bool Graph::isRun(){
	return cond;
}

void Graph::run(){
	cond = true;
	list<char> movements;
	vector<array<int,2>> points;
	cout << "Running Calculation......";
	right(main, movements, points);
	left(main, movements, points);
	down(main, movements, points);
	up(main, movements, points);
	cout << "Finished!"<<endl;
}

void Graph::print(){
	list< list<char> >::iterator iter;
	cout <<"Size : "<< AllRoutes.size() << endl;
	for (iter = AllRoutes.begin(); iter != AllRoutes.end(); iter++) {
		list<char> newdata = *iter;
		list<char>::iterator newiter;
		for (newiter = newdata.begin(); newiter != newdata.end(); newiter++) {
			cout << *newiter << "-";
		}
		cout << endl;
	}
}
