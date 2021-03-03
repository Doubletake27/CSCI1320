#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the length:" << endl;

    int n = 0;
    cin >> n;

    for(int i=0;i<n;i++){
      for(int j=0;j<n-i-1;j++){
        cout << ' ';
      }
      for(int j=0;j<2*i+1;j++){
        cout << '*';
      }
      cout << endl;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<i+1;j++){
        cout << ' ';
      }
      for(int j=0;j<2*n-2*i-3;j++){
        cout << '*';
      }
      if(i!=n-1){
        cout << endl;
      }
    }

    return 0;
}
