#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter the search string:" << endl;
    string seas = "";
    cin >> seas;
    cout << "Enter the substing to be searched:" << endl;
    string subs = "";
    cin >> subs;

    int lseas = seas.length();
    int lsubs = subs.length();

    int n = 0;

    bool match = false;
    for(int i = 0;i<(lseas-lsubs+1);i++){ // Loop through seas
        for(int k=0;k<lsubs;k++){ // loop through subs
          //cout << seas[i+k] << "("<< subs[k]<<")";
          if(seas[i+k]==subs[k]){
            match = true;
          }else{
            match = false;
            break;
          }
        }
        //cout << endl;
        if(match){
          n++;
        }
    }


    cout << "Number of occurences: " << n;


    return 0;
}
