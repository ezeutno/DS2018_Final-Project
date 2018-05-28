#include "AllMaps.h"

AllMaps::AllMaps(){

	myfileWrite = ofstream("AllMaps.txt");
	myfileRead = ifstream("AllMaps.txt");
	if (myfileRead.is_open()) {
		string line;
		while (getline(myfileRead, line)) {
			char *str = new char[line.length()+ 1];
			strcpy_s(str,sizeof(str), line.c_str());
			char *pch;
			string name;
			string location;
			int i = 0;
			char *next_pch;
			pch = strtok_s(str, ";",&next_pch);
			while (pch) {
				if (i == 0) name = pch;
				else location = pch;
				pch = strtok_s(NULL, ";", &next_pch);
				i++;
			}
			Map *newRes = new Map(location, name);
			allMap.push_back(*newRes);
		}
		myfileRead.close();
	}
	else {
		cout << "An Error Occured : File isn't openning!" << endl;;
	}
}

