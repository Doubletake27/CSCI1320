#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Student{
  int idNumber;
  string name;
  string dept;
};

void readInFile(Student arr[], int arrL, string filename);

int main(int argc, char *argv[]){
  if(argc != 2){
    cout << "incorrect number of arguments" << endl;
    return -1;
  }else{
    const int N = 10;
    Student arr[N];

    cout << "Executable name" << argv[0] << endl;
    cout << "Reading in file: " << argv[1] << endl;

    // string fname = "students.txt";

    readInFile(arr, N, argv[1]);

    return 0;
  }
}

void readInFile(Student arr[], int arrL,string filename){
  ifstream inStream;
  inStream.open(filename);
  string sidString,studentName,major; // Temp Variables to store into

  if(inStream.is_open()){
    for(int i = 0; i < arrL; i++){
      getline(inStream,sidString,',');
      arr[i].idNumber = stoi(sidString);
      // cout << sidString << endl;

      getline(inStream,studentName,',');
      arr[i].name = studentName;
      // cout << studentName << endl;

      getline(inStream,major,'\n');
      arr[i].dept = major;
      // cout << major << endl;
    }
  }else{
    cout << "AAAhh Lawdy, you borked it real good!";
    exit(0);
  }
  inStream.close();
}
