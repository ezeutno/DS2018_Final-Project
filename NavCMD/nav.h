#include <iostream>
#include 'mapText.h'
using namespace std;

class NavRoutes{
	private:
		Map data;
		int[2] size;
		int[2] startPoint;
		int[2] currPoint;
		int[2] endPoint;
		void create();
	public:
		NavRoutes();
		NavRoutes(Map data);
};
