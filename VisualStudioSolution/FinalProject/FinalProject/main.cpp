#include <iostream>
#include "mapText.h"
#include "nav.h"
using namespace std;

int main() {
	cout << "MAIN" << endl;
	Map res("example.txt");
	res.run();
	res.print('X', 4);
	cout << "GET DATA : " << res.getData(7, 6) << endl;
	cout << "GET DATA : " << res.getData(0, 1) << endl;
	int start[] = { 2,0 };
	int end[] = { 2,5 };
	NavRoutes result(res, start, end);
	cout << "Press Enter to Continue....";
	cin.sync();
	cin.ignore();
	return 0;
}