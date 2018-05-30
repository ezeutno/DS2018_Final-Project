#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "AllMaps.h"
#include "mapText.h"
#include "nav.h"
#include "Graphs.h"
#include "main.h"
#define B_V		(char)186
#define B_H		(char)205
#define B_TL	(char)201
#define B_TR	(char)187
#define B_ML	(char)204
#define B_MR	(char)185
#define B_BL	(char)200
#define B_BR	(char)188
using namespace std;

// global variable
string b_horizontal = "";
AllMaps all;

void header(string title) {
	b_horizontal = "";
	for (int i = 0; i < title.length(); i++) {
		b_horizontal += B_H;
	}
	system("CLS");
	cout << B_TL << b_horizontal.c_str() << B_TR << endl;
	cout << B_V  << title.c_str() << B_V << endl;
	cout << B_BL << b_horizontal.c_str() << B_BR << endl;
	b_horizontal = "";
}

void show_map() {
	header("SHOW MAP");
	int data;
	cout << "Insert Map Code\t\t\t: ";
	cin >> data;
	if (data > 0 && data <= all.size()) {
		Map newMap = all.getData(data - 1);
		if (!newMap.isRun())newMap.run();
		newMap.print();
	}else {
		cout << "Data must be between 1 & " << all.size() <<"!"<< endl;
	}
	cin.sync();
	cin.ignore();
	cin.sync();
	cin.ignore();
}

void select_map() {
	header("RUN ALL MAP SOLUTION");
	int data;
	cout << "Insert Map Code\t\t\t: ";
	cin >> data;
	if (data > 0 && data <= all.size()) {
		Map newMap = all.getData(data - 1);
		if (!newMap.isRun())newMap.run();
		newMap.print();
		NavRoutes newNav(newMap);
		int x, y;
		while (true) {
			cout << "Set X & Y Starting Point\t: ";
			cin >> x >> y;
			if (x < newMap.getSize('y') && y < newMap.getSize('x')) {
				if (newMap.getData(y,x)) {
					cout << "Starting point hit blockade!" << endl;
				}else {
					break;
				}
			}
			else cout << "Starting point out of border!" << endl;
		}
		newNav.setStartPoint(x, y);
		while (true) {
			cout << "Set X & Y Ending Point\t\t: ";
			cin >> x >> y;
			if (x < newMap.getSize('y') && y < newMap.getSize('x')) {
				if (newMap.getData(y, x)) {
					cout << "Ending point hit blockade!" << endl;
				}else {
					break;
				}
			}
			else cout << "Ending point out of border!" << endl;
		}
		newNav.setEndPoint(x, y);

		Graph newGraph(newNav);
		cout << "Do you want to get all solution? (yes-1/no-0) ";
		int choice = _getch();
		if (choice == '1') {
			newGraph.run(true);
		}
		else if (choice == '0') {
			newGraph.run(false);
		}
		cout << endl;
		newGraph.start();
		while (newGraph.has_next()) {
			system("CLS");
			header("SOLUTION");
			newNav.print(newGraph.getCurrentList());
			cout << "[1] Next Solution" << endl;
			cout << "[2] Show All Step" << endl;
			cout << "[0] Exit" << endl;
			int newdata = _getch();
			if (newdata == '1') {
				newGraph.next();
				if (!newGraph.has_next()) cout << "NO MORE SOLUTION, EXITING!" << endl;
			}else if (newdata == '2') {
				system("CLS");
				header("ALL SOLUTION");
				newMap.print();
				newGraph.print();
				break;
			}else if (newdata == '0') break;
		}
	}else {
		cout << "Data must be between 1 & " << all.size() << "!" << endl;
	}
	cin.sync();
	cin.ignore();
	cin.sync();
	cin.ignore();
}

void list_maps() {
	header("LIST MAPS");

	/*run all maps to the line*/
	all.print();
	cin.sync();
	cin.ignore();
}

void create_map() {
	header("CREATE MAP");
	Map createNew;
	createNew.create();
	all.insert(createNew);
	cin.sync();
	cin.ignore();
}

int main() {
	while (true) {
		if (!all.isRun()) all.run();
		header("MENU");
		system("Color 0E");
		cout << "[1] Run all map solution" << endl;
		cout << "[2] List all maps" << endl;
		cout << "[3] Create new map" << endl;
		cout << "[4] Show Map" << endl;
		cout << "[0] Exit" << endl;
		int x = _getch();
		switch (x) {
		case '1':
			select_map();
			break;
		case '2':
			list_maps();
			break;
		case '3':
			create_map();
			break;
		case '4':
			show_map();
			break;
		case '0':
			exit(0);
		}
	}
	return 0;
}