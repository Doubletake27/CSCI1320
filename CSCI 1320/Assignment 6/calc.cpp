#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a;
    float b; 
    cout << "Input Value A: ";
    cin >> a;
    cout << "Input Value B: ";
    cin >> b;
    float c = a+b;
    cout << "A + B = " << c << endl;
    float d = a-b;
    cout << "A - B = " << d << endl;
    float e = a*b;
    cout << "A * B = " << e << endl;
    float f = a/b;
    cout << "A / B = " << f << endl;
    float g = pow(a,b);
    cout << "A ^ B = " << g << endl;
}
