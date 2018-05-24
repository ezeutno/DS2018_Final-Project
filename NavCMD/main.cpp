#include <iostream>
#include "mapText.h"
using namespace std;

int main(){
	cout<<"MAIN"<<endl;
	Map res("example.txt");
	res.create();
	res.print('*',1);
	cout<<res.getData(7,6)<<endl;
}
