#include<iostream>
using namespace std;
#include<cmath>
#include<ctime>

int main(){
  int d = 3;
  //cout << time(NULL) << " seconds has passed since 00:00:00 GMT, Jan 1 1970" << endl;
  srand(time(NULL));
  for(int i = 0; i < 12; i++){
    cout << rand()%(d+1) <<" ";
  }
  cout << endl;
  return 0;
}
