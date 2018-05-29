#include "AllMaps.h"

AllMaps::AllMaps(){
	cond = false;
}

bool AllMaps::isRun(){
	return cond;
}

void AllMaps::run(){
	cond = true;
	myfileRead.open("AllMaps.txt");
	if (myfileRead.is_open()) {
		string line;
		while (getline(myfileRead, line)) {
			char str[100000];
			strcpy_s(str, sizeof(str), line.c_str());
			char *pch;
			string name;
			string location;
			int i = 0;
			char *next_pch;
			pch = strtok_s(str, ";", &next_pch);
			while (pch) {
				if (i == 0) name = pch;
				else location = pch;
				pch = strtok_s(NULL, ";", &next_pch);
				i++;
			}
			allMap.push_back(Map(location,name));
		}
		myfileRead.close();
	}
	else {
		cout << "An Error Occured : File isn't openning!" << endl;;
	}
}

void AllMaps::insert(Map& data){
	allMap.push_back(data);
	myfileWrite.open("AllMaps.txt", ios::app);
	if (myfileWrite.is_open()) {
		myfileWrite << data << endl;
		myfileWrite.close();
	}else {
		cout << "An Error Occured : File isn't openning!" << endl;;
	}
}

size_t AllMaps::size(){
	return allMap.size();
}

Map AllMaps::getData(int i){
	return allMap[i];
}

