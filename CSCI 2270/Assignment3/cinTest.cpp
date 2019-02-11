#include <iostream>
#include <string>
using namespace std;

void testing(){
  for(int i = 0; i < 10; i++){
    cout << "next " << i << endl;
  }
}

int main(){
  string test;
  string location;
  cout << "Enter name of the country to receive the message: " << endl;
  getline(cin,location);
  cout << "Input a comma separated string: " << endl;
  getline(cin,test);
  cout << "Location: " << location << " Test: "<< test << endl;
  testing();
}

// cout << "Enter name of the country to receive the message: " << endl;
// getline(cin,location);
// cout << "Enter the message to send: " << endl;
// getline(cin,note);
// cout << note << endl;
// h.transmitMsg(location, note);
// break;
