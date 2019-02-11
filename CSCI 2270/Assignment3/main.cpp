/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
#include <iostream>
#include <string>
#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
  CountryNetwork h;

  string location;
  string name;
  string previous;
  string note;
  bool exists;

  Country *address = nullptr;

  int choice = 0;
  while(choice != 8){
    displayMenu();
    cin >> choice;
    switch(choice){
      case 0: // This is for Resetting Questions
        break;

      case 1: // Build Network
        h.loadDefaultSetup();
        h.printPath();
        break;

      case 2: // Print Network Path
        h.printPath();
        break;

      case 3: // Transmit Message

        cout << "Enter name of the country to receive the message: " << endl;
        cin.ignore();
        getline(cin,location);

        cout << "Enter the message to send: " << endl;
        getline(cin,note);
        h.transmitMsg(location, note);
        break;

      case 4: // Add Country

        cout << "Enter a new country name: " << endl;
        cin.ignore();
        getline(cin,name);

        exists = false;

        cout << "Enter the previous country name (or First):" << endl;

        while(!exists){
          // cin.ignore();
          getline(cin,previous);

          if(previous == "First"){
            exists = true;
            address = nullptr;
          }else{
            address = h.searchNetwork(previous);
            if(address!=nullptr){
              exists = true;
            }else{
              cout << "INVALID country...Please enter a VALID previous country name: " << endl;
              // cin.ignore();
            }
          }
        }
        h.insertCountry(address,name);

        h.printPath();
        break;

      case 5: // Delete Country
        cout << "Enter a country name: " << endl;
        cin >> location;
        h.deleteCountry(location);
        h.printPath();
        break;

      case 6: // Reverse Network
        h.reverseEntireNetwork();
        h.printPath();
        break;

      case 7: // Clear Network
        h.deleteEntireNetwork();
        break;

      case 8: // Quit
        cout << "Quitting... cleaning up path:"<< endl;
        h.printPath();
        if(!h.isEmpty()){
          h.deleteEntireNetwork();
        }
        if(h.isEmpty()){
          cout << "Path cleaned" << endl;
          cout << "Goodbye!" << endl;
        }else{
          cout << "Error: Path NOT cleaned" << endl;
          choice = 0;
        }
        break;
    }
    cout << endl;
  }
  return 0;
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    // cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
