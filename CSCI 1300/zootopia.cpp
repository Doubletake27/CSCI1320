#include <iostream>
using namespace std;

int main(){
  int userInput = 1;
  double agility = 0;
  double strength = 0;
  double speed = 0;
  double hireScore = 0;
  while (userInput < 4 && userInput >= 1){
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. Fox" << endl;
    cout << "2. Bunny" << endl;

    cout << "3. Sloth" << endl;
    cout << "4. Quit" << endl;
    cin >> userInput;

    if (userInput <= 4 && userInput >= 1){
      switch (userInput){
        case 1:
        cout << "Enter agility:" << endl;
        cin >> agility;
        cout << "Enter strength:" << endl;
        cin >> strength;

        hireScore = 1.8 * agility;
        hireScore = hireScore + 2.16 * strength;
        cout << "Hire Score: " << hireScore << endl;
        break;

        case 2:
        cout << "Enter agility:" << endl;
        cin >> agility;
        cout << "Enter speed:" << endl;
        cin >> speed;

        hireScore = 1.8 * agility;
        hireScore = hireScore + 3.24 * speed;
        cout << "Hire Score: " << hireScore << endl;
        break;

        case 3:
        cout << "Enter strength:" << endl;
        cin >> strength;
        cout << "Enter speed:" << endl;
        cin >> speed;

        hireScore = 2.16 * strength;
        hireScore = hireScore + 3.24 * speed;
        cout << "Hire Score: " << hireScore << endl;
        break;

        case 4:
        cout << "Good bye!" << endl;
        break;
      }
    }else{
      cout << "Invalid option" << endl;
      //break;
    }
  }
}
