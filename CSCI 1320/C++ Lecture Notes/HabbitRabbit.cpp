#include <iostream>
using namespace std;

int main(){
  for(int i = 1; i<171;i++){
    bool print = false;
    if(i%3 == 0){
      cout<< "Habbit";
      print = true;
    }
    if(i%7 == 0 ){
      cout <<"Rabbit";
      print = true;
    }
    if(!print){
      cout << i;
    }
    cout << endl;
  }
  return 0;
}
