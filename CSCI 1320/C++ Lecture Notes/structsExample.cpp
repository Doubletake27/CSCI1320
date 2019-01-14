// String to store the word
// Int to store number of letters

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct WordLetters
{
  string word; // word
  int nlet; // number or letters
};

void readFile(string fileName, int numWords, WordLetters arr[]);

int main(){
  const int N = 17;

  string fileName = "lab10test.txt";
  WordLetters a[N];

  readFile(fileName,N,a);

  for(int i = 0; i < N; i++){
    cout << a[i].word << " " << a[i].nlet<<endl;
  }

  return 0;
}

void readFile(string fileName, int numWords, WordLetters arr[]){
  ifstream inStream;
  inStream.open(fileName);
  for(int i = 0; i < numWords; i++){
    inStream >> arr[i].word;
    arr[i].nlet = arr[i].word.length(); // Same as .size()
  }
  inStream.close();
}
