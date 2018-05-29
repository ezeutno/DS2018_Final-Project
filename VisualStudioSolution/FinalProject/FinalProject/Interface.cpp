#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "interface.h"
using namespace std;

string b_horizontal = "";

void header(string title) {
	for (int i = 0; i < 31; i++) {
		b_horizontal += B_H;
	}

	system("CLS");
	cout << B_TL << b_horizontal.c_str() << B_TR << endl;
	cout << B_V << "\t      " << title.c_str() << "\t\t" << B_V << endl;
	cout << B_ML << b_horizontal.c_str() << B_MR << endl;
	cout << B_V << "\t\t\t\t" <<B_V<< endl;
}

void menu() {
	while (true) {
		header("MENU");
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
			cout << "lol1" << endl;
			break;
		case '2':
			cout << "lol2" << endl;
			break;
		case '3':
			cout << "lol3" << endl;
			break;
		case '4':
			exit(0);
		}
	}
}