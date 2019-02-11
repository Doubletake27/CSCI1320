/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/
#include <iostream>
#include <string>
#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{

}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if(head == NULL){
    return 1;
  }else{
    return 0;
  }
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
  if(previous == nullptr){
    // Insert at beginning
    Country* temp = head;
    head = new Country;
    head -> name = countryName;
    head -> numberMessages = 0;
    head -> next = temp;
    cout << "adding: " << countryName << " (HEAD)" << endl;
  }else{
    // Insert in the middle
    Country *temp = new Country;
    temp -> next = previous -> next;
    temp -> numberMessages =  0;
    temp -> name = countryName;
    previous -> next = temp;
    cout << "adding: " << countryName << " (prev: " << previous -> name << ")" << endl;
  }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
  Country *address = searchNetwork(countryName);
  if(address == nullptr){
    cout << "Country does not exist." << endl;
  }else{
    Country *temp = address -> next;
    if(address == head){
      head = temp;
      delete address;
    }else{
      bool found = false;
      // Locate Previous Node
      Country *prev = head;
      while(!found){
        if(prev -> next == address){
          found = true;
          break;
        }else{
          prev = prev -> next;
        }
      }
      prev -> next = temp;
      delete address;
    }
    address = nullptr;
    temp = nullptr;
  }
}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
  string Countries[] = {"United States","Canada","Brazil","India","China","Australia"};
  string prev;
  Country *countryptr = new Country;

  head = countryptr; // Initializes head

  countryptr -> name = Countries[0];
  countryptr -> numberMessages = 0;
  countryptr -> next = new Country;

  cout << "adding: " << countryptr -> name << " (HEAD)" << endl;

  for(int i = 1; i < 6; i++){
    prev = countryptr -> name;
    countryptr = countryptr -> next; // Moves to the next country

    countryptr -> name = Countries[i];
    countryptr -> numberMessages = 0;
    if(i != 5 ){
      countryptr -> next = new Country;
    }else{
      countryptr -> next = nullptr;
    }

    cout << "adding: " << Countries[i] << " (prev: " << prev << ")" << endl;
  }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
  if(head!= nullptr){
    Country *current = head;
    while(current != nullptr){
      if(current -> name == countryName){
        break;
      }
      current = current -> next;
    }
    return current;
  }else{
    return nullptr;
  }
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
  Country *address = head;
  while(head != nullptr){
    head = address ->next;
    cout << "deleting: " << address -> name << endl;
    delete address;
    address = head;
  }
  cout << "Deleted network" << endl;
}


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string msg)
{
  Country *address = searchNetwork(receiver);
  if(address != nullptr){
    bool sent = false;
    Country *current = head;
    while(!sent){
      current -> message = msg;
      current -> numberMessages++;
      cout << current -> name << " [# messages received: " << current -> numberMessages << "] received: " << msg << endl;
      if(current == address){
        sent = true;
      }else{
        current = current -> next;
      }
    }
    current = nullptr;
  }else{
    cout << "Empty List" << endl;
  }
  address = nullptr;
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  if(head == nullptr){
    cout << "== CURRENT PATH ==" << endl;
    cout << "nothing in path" << endl;
    cout << "===" << endl;
  }else{
    Country *address = head;
    cout << "== CURRENT PATH ==" << endl;
    while(address != nullptr){
      cout << address -> name << " -> ";
      address = address -> next;
    }
    cout << "NULL" << endl << "===" << endl;
  }
}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
// Save address
// Find Next Box
// Find Following Box

void CountryNetwork::reverseEntireNetwork()
{
  if(head!= nullptr){
    Country *previous = nullptr;
    Country *current = head;
    Country *following = current -> next;
    while(following != nullptr){
      current -> next = previous;
      previous = current;
      current = following;
      following = current -> next;
    }
    current -> next = previous;
    head = current;
    previous = nullptr;
    current = nullptr;
    following = nullptr;
  }
}
