#include <iostream>
#include "AllMaps.h"
#include "mapText.h"
#include "nav.h"
using namespace std;

int main() {
	cout << "MAIN" << endl;
	/*Map res("example.txt");
	res.run();
	res.print('X', 4);
	cout << "GET DATA : " << res.getData(7, 6) << endl;
	cout << "GET DATA : " << res.getData(0, 1) << endl;
	int start[] = { 2,0 };
	int end[] = { 2,5 };
	NavRoutes result(res, start, end);
	Map result2;
	result2.create();
	result2.run();
	result2.print('Y',3);*/
	AllMaps all;
	all.run();
	cout <<"SIZE : "<< all.size() << endl;
	for (int i = 0; i < all.size(); i++) all.getData(i).print();
	Map createNew;
	createNew.create();
	all.insert(createNew);
	cout << "Press Enter to Continue....";
	cin.sync();
	cin.ignore();
	return 0;
}