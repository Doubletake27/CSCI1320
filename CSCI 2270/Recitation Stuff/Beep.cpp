#include <iostream>
using namespace std;

void fun(int n){
    if(n > 0) {
        fun(n-1);
        cout << n;
        fun(n-1);
    }
    else
        return;
}
int main(){
    fun(3);
    return 0;
}
