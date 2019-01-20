#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
  cout << "Number of Arguments: ";
  cout << argc << endl;
  cout << "Program Arguments" << endl;
  for(int i = 0; i < argc; i++){
    cout << "Argument #" << i << ": ";
    cout <<  argv[i] << endl;
  }
}

// RUN this in Command Line:
// a.exe arg1 arg2 arg3
