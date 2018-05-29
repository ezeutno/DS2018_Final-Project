#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "interface.h"
using namespace std;

interface::interface() {

}

void interface::header(string title) {
	for (int i = 0; i < 31; i++) {
		b_horizontal += B_H;
	}

	system("CLS");
	cout << B_TL << b_horizontal.c_str() << B_TR << endl;
	cout << B_V << "\t" << title.c_str() << "\t\t" << B_V << endl;
	cout << B_ML << b_horizontal.c_str() << B_MR << endl;
	cout << B_V << "\t\t\t\t" <<B_V<< endl;
}

void interface::select_map() {
	header("SELECT MAP");
	cout << B_BL << b_horizontal.c_str() << B_BR << endl;
	cin.sync();
	cin.ignore();
}

void interface::list_maps() {
	header("LIST MAPS");
	cout << B_BL << b_horizontal.c_str() << B_BR << endl;
	cin.sync();
	cin.ignore();
}

void interface::create_map() {
	header("CREATE MAP");
	cout << B_BL << b_horizontal.c_str() << B_BR << endl;
	cin.sync();
	cin.ignore();
}

void interface::menu() {
	while (true) {
		header("      MENU");
		system("Color 0E");
		cout << B_V << "\t1. Select map\t\t" << B_V << endl;
		cout << B_V << "\t2. List all maps\t" << B_V << endl;
		cout << B_V << "\t3. Create new map\t" << B_V << endl;
		cout << B_V << "\t4. Exit\t\t\t" << B_V << endl;
		cout << B_V << "\t\t\t\t" << B_V << endl;
		cout << B_BL << b_horizontal.c_str() << B_BR << endl;
		b_horizontal = "";
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
			exit(0);
		}
	}
}
