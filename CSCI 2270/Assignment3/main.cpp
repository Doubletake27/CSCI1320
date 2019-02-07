/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
#include <iostream>
#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
  int choice = 0;
  while(choice != 8){
    displayMenu();
    cin >> choice;
    switch(choice){
      case 0; // This is for Resetting Questions
        break;

      case 1: // Build Network
        loadDefautSetup();
        printPath();
        break;

      case 2: // Print Network Path
        printPath();
        break;

      case 3: // Transmit Message
        string message,location;
        cout << "Enter the name of the country to receive the message: " << endl
        cin >> location;
        cout << "Enter the message to send: " << endl;
        cin >> message;
        transmitMsg(location, message);
        break;

      case 4: // Add Country
        string name, previous;
        Country *address = nullptr;
        do{
          cout << "Enter a new country name: " << endl;
          cin >> name;
          cout >> "Enter the previous country name (or First)" >> endl;
          cin >> previous;
          address = searchNetwork(previous);
          if(address != nullptr){
            if(previous != "First"){
              // Create New Entry
              insertCountry(address,name);
            }else{
              // Create new first entry (including updating head)
              insertCountry(nullptr,name);
            }
          }else{
            cout << "Invalid country...Please enter a VALID previous country name: " << endl;
          }
        }while(address == nullptr) // This is basically in case they enter not a country
        printPath();
        break;

      case 5: // Delete Country
        cout << "Enter the name of the country to delete: " << endl;
        cin >> location;
        address = searchNetwork(location);


        printPath();
        break;

      case 6: // Reverse Network

        break;

      case 7: // Clear Network

        break;

      case 8: // Quit
        printPath();
        deletEntireNetwork();
        if(isEmpty){
          cout << "Path cleaned" << endl;
          cout << "GoodBye!" << endl;
        }else{
          cout << "Error: Path NOT cleaned" << endl;
          choice = 0;
        }
        break;
    }
  }
  return 0;
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    cout << endl;
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
