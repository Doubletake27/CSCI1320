// Output Example
#include <fstream>
#include <iostream>

using namespace std;

int main(){
  ofstream oFile("filename.txt");
  oFile << "Insert this text into filename.txt";
  oFile.close();
}
