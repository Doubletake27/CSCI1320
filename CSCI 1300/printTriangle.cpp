#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter the height:" << endl;

    int n = 0;
    cin >> n;

    string abc = "abcdefghijklmnopqrstuvwxyz";

    int l = 0;

    for(int i = 0; i<n;i++){
      for(int j = 0; j<n-i;j++){
        cout << abc[l];
        if(l!=25){
          l++;
        }else{
          l=0;
        }
      }
      if(i!=n-1){
        cout << endl;
      }
    }


    return 0;
}
