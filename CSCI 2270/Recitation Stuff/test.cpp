#include <iostream>
using namespace std;

struct DateType{
  int day;
  int month;
  int year;
};

struct PersonType{
  int age;
  float weight;
  DateType birthday;
};

int main(){
  PersonType person;

  person.birthday.year = 2000;
  cout << person.birthday.year << endl;
}
