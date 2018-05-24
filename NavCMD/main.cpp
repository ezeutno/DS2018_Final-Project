#include <iostream>
#include "mapText.h"
using namespace std;

int main(){
	cout<<"MAIN"<<endl;
	Map res("example.txt");
	res.create();
	cout<<endl;
	res.print();
	return 0;
}
