#include <iostream>
#include "mapText.h"
#include "nav.h"
using namespace std;

int main(){
	cout<<"MAIN"<<endl;
	Map res("example.txt");
	res.run();
	res.print('*',1);
	cout<<res.getData(7,6)<<endl;
	int start[] = {2,0};
	int end[] = {2,5};
	NavRoutes(res,start,end);
	return 0 ;
}
