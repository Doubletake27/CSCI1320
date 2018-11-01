// Program for calculating freefall distance as a function of time
// d = 1/2 * g * t^2


#include <iostream>
//#include <string>

using namespace std;

int main()
{
	float d;
	const float g = 9.8;
	float t;

	cout << "enter time: " << endl;
	cin >> t;

	d = 0.5 * g * t * t;

	cout << "distance = " << d << endl;

	return 0;
}
