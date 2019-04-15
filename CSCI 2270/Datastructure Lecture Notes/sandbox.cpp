// Vector Example

#include <iostream>
#include <vector>

using namespace std;

int main(){
  //declare a vector or ints
  // no need to specify size (but you can)

  vector<int> v0;

  cout << "v0 length " << v0.size() << endl;

  v0 = {  1,2,7,0};
  cout << "v0 index 1&2: " << v0[1] << "," << v0[2] << endl; // Thisis how you index into vectors
  cout << "v0 length " << v0.size() << endl;

  // With vectors we can append at the end
  // the container will automatically accomodate the size

  v0.push_back(9);
  cout << "v0 length " << v0.size() << endl;

  // can reduce the sizeov vector
  v0.pop_back(); // dequeues the last element
  cout << "v0 length " << v0.size() << endl;

  // to initialize size, just pass size to constructor
  vector<int> v1(7);
  cout << "v1 length " << v1.size() << endl;

  // can also resize
  v1.resize(20);
  cout << "v1 length " << v1.size() << endl;

  cout << "indexing into a position where there is no value returns: "<< v1[2] << endl;

  return 0;
}
