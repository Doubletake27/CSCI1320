#include <iostream>
using namespace std;

int loopCount(int n, int l);

const int L = 4; // total number of letters

int main(){
  // l = 4; // number of letters + 1 for space
  int s = 3; // number of spaces

  int count = loopCount(s,L);

  cout << "There are " << count << " spaces in a hash table for an Alphabet with " << L << " letters and words with a max length of " << s << endl;
}

int loopCount(int n, int l){
  int count = 0;

  if(n!=0){
    for(int i = l; i <= L; i++){
      count += loopCount(n-1,l-1);
      count ++ ;
    }
  }

  return count;
}
