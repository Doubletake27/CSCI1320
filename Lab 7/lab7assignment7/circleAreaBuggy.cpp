// cicleAreaBuggy.cpp
// Program to calculate the area of a circle
// User is promted for the radius

#include <iostream>
using namespace std;

int main()
{
	double area;
	const double pi = 3.14;
	double radius = 4;

	cout << "Please enter radius: " << endl;
	cin >> radius;

	area = pi * radius * radius;

	cout << "The area of a circle with radius " << radius  <<
	  " is " << area << "." << endl;

    return 0;
}
