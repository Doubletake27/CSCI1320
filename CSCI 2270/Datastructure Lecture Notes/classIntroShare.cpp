// classIntro.cpp
// example class: 12-hour time clock

#include <iostream>
#include <string>

using namespace std;

class Time12
{
private:
	int hour;
	int minute;
	string mer;

public:
	//constructors:
	Time12( int h, int m, string me );
	Time12( ){};

	//display function
	void printTime();

	// mutator functions:
	void setHour( int h ); 
	void setMinute( int m );
	// accessor functions
	int getHour();
	int getMinute();

};

int main()
{

	return 0;
}

Time12::Time12( int h, int m, string me ){ // constructor definition, is special kind of public method

	if ( h >= 0 && h <= 12 )
		hour = h;
	else
		cout << "bad choice " << endl;

	if( m >=0 && m <=60 )
		minute = m;
	else
		cout << "wrong choice for minute " << endl;

	mer = me;
}

void Time12::printTime(){
	cout << hour << ":" << minute << mer << endl;
}


void Time12::setHour( int h ){ // mutator
	if ( h >= 0 && h <= 12 )
		hour = h;
	else
		cout << "bad choice " << endl;
}

void Time12::setMinute( int m ){
	if( m >=0 && m <=60 )
		minute = m;
	else
		cout << "wrong choice for minute " << endl;

}

// accessor methods
int Time12::getHour() {
	return hour;
}

// accessor methods
int Time12::getMinute() {
	return minute;
}




