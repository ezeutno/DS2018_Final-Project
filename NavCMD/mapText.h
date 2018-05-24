#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Map{
	private:
		string name;
		string location;
		bool Created;
		ofstream myfileWrite;
		ifstream myfileRead;
		vector< vector<bool> > data;
	public:
		Map();
		Map(string loc);
		string getName();
		bool isCreated();
		bool getData(int x, int y);
		void create();
		void edit();
		void save();
		void print();
};

Map::Map(){
}

Map::Map(string loc){
	Created = false;
	location = loc;
}

bool Map::isCreated(){
	Created = false;
	return Created;
}

void Map::create(){
	Created = true;
	myfileRead.open(location.c_str());
	if (myfileRead.is_open()){
		string line;
    	while ( getline (myfileRead,line) ){
      		vector<bool> tempLine;
      		for(int i=0;i<line.length();i++){
      			if (line.at(i) == '0'){
      				tempLine.push_back(false);
				}else {
					tempLine.push_back(true);
				}
			}
			data.push_back(tempLine);
    	}
    myfileRead.close();
  }
}

void Map::print(){
	vector< vector<bool> >::iterator i;
	vector<bool>::iterator a;
	for (i=data.begin(); i != data.end(); ++i){
		vector<bool> res= *i;
		for (a=res.begin(); a != res.end(); ++a){
			 cout<<*a;
		}
		cout<<endl;
	}
		 
}

string Map::getName(){
	return name;
}
