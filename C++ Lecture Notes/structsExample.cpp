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
}

int main(){
  const int N = 17;

  string fileName = "lab10test.txt";

  ifstream inStream;

  WordLetters a[N];

  inStream.open(fileName);

  for(int i = 0; i < N; i++){
    inStream >> a[i].word;
    a[i].nlet = a[i].word.length();
  }

}
