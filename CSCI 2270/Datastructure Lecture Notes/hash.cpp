#include <iostream>
using namespace std;

struct Student{
  string name;
  int sid;
};

hashSum(string key, int keyLength, int size){
  int sum = 0;
  for(int i = 0; i < keyLength; i++){
    sum += key[i];
  }
  return (sum%size);
}


int main(){
  int hashSize = 4;
  Student hashTable[hashSize];

  Student sIn;
  sIn.name = "anna";
  sIn.sid = 823;
  int index = hashSum(sIn.name,4,hashSize);

  cout << " index for " << sIn.name << " = " << index << endl;
  hashTable[index] = sIn;

  Student sOut = hashTable[hashSum("anna",4,hashSize)];

  return 0;
}
// md5sum can be useful
