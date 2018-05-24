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
		Map(string loc, string = "Problem");
		string getName();
		bool isCreated();
		bool getData(int x, int y);
		void setName(string name);
		void setLocation(string loc);
		void create();
		void edit();
		void save();
		void print(char = '*', int = 1);
};

Map::Map(){
}

Map::Map(string loc, string name){
	Created = false;
	location = loc;
	this->name = name;
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

void Map::print(char block, int border){
	vector< vector<bool> >::iterator i;
	vector<bool>::iterator a;
	//name	
	cout<<"Problem Name : "<<name<<endl;
	//border
	for(int c=0;c<border;c++){
		for (a= data[0].begin(); a != data[0].end(); ++a) cout<<"-";
		for (int d=0;d<border;d++) cout<<"--";
		cout<<endl;
	}
	for (i= data.begin(); i != data.end(); ++i){
		vector<bool> res= *i;
		for (int d=0;d<border;d++) cout<<"|";
		for (a=res.begin(); a != res.end(); ++a){
				if(*a) cout<<block;
				else cout<<' ';
		}
		for (int d=0;d<border;d++) cout<<"|";
		cout<<endl;
 	}
 	//border
	for(int c=0;c<border;c++){
		for (a= data[0].begin(); a != data[0].end(); ++a) cout<<"-";
		for (int d=0;d<border;d++) cout<<"--";
		cout<<endl;
	}
}

bool Map::getData(int x, int y){
	if (data.size() > x){
		if(data[x].size() > y){
			return data[x][y];
		}
	}
	return false;
}

string Map::getName(){
	return name;
}
