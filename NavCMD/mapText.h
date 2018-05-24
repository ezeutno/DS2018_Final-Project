#include <iostream>
#include <fstream>
using namespace std;

class Map{
	private:
		string name;
		string location;
		bool[][] data;
		int[] max;
	public:
		map(string loc);
		string getName();
		string getData(int x, int y);
		bool getData(int x, int y);
		void print();
};
