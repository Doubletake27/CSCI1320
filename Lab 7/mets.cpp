#include <iostream>
using namespace std;

int main(){
  float const LBKG = 2.2; // kg to lbs converison factor
  double weight,calories;
  int mets,time; // time in minutes

  cout << "Weight(lbs): ";
  cin >> weight;
  cout << "METS: ";
  cin >> mets;
  cout << "Time Spent (Minutes): ";
  cin >> time;

  weight = weight / LBKG; // converts weight to kg
  calories = weight * mets * time * 0.0175;

  cout << "You Burned " << calories << " Calories." << endl;

  return 0;
}
