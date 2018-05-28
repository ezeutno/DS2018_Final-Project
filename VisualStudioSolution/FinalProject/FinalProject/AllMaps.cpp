#include "AllMaps.h"

AllMaps::AllMaps(){
	myfileWrite = ofstream("AllMaps.txt");
	myfileRead = ifstream("AllMaps.txt");
	if (myfileRead.is_open()) {
		string line;
		while (getline(myfileRead, line)) {
			char str[] = line;
		}
		myfileRead.close();
	}
	else {
		cout << "An Error Occured : File isn't openning!" << endl;;
	}
}
