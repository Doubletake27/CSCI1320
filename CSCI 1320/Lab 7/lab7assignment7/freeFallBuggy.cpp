// Program for calculating freefall distance as a function of time
// d = 1/2 * g * t^2


#include <iostream>
#include <string>

using namespace std;

int main( )
{
	int d;
	const int g = 9.8;
	const int t = 10;

	cout << "enter time: " << endl; 

	d = 1/2 * g * t; 

	cout << "distance = " << d << endl;


	return 0;
}
