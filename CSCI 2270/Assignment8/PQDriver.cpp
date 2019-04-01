// Priority Queue Driver
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "PriorityQueue.hpp"

int serveNext(int totalCookTime);
int menu();

int main(int argc, char *argv[]){
  int maxQueueSize = stoi(argv[1]);
  string filename;
  int choice = 0;
  // int totalCookTime= 0;
  string name,sz,t;

  PriorityQueue pq(maxQueueSize);

  while(choice!=6){
    choice = menu();
    switch(choice){
      case 1:{ // Get group information from file
        cout << "Enter filename:" << endl;
        cin >> filename;

        ifstream groups;
        groups.open(filename);

        while(!groups.eof()){
          getline(groups,name,' ');
          getline(groups,sz,' ');
          getline(groups,t,'\n');

          pq.enqueue(name,stoi(sz),stoi(t));
          if(pq.isFull()){
            cout << "Heap full cannot enqueue" << endl;
          }
        }
        groups.close();
      }
        break;

      case 2: // Add group to Priority Queue
        if(!pq.isFull()){
          cout << "Enter Group Name: " << endl;
          cin >> name;
          cout << "Enter Group Size: " << endl;
          cin >> sz;
          cout << "Enter Estimated Cooking Time: " << endl;
          cin >> t;
          pq.enqueue(name,stoi(sz),stoi(t));
        }else{
          cout << "Heap full, cannot equeue" << endl;
        }

        break;

      case 3: // Show next group in the queue
        cout << "Group Name: " << pq.peek().groupName << endl;
        cout << "Group Size: " << pq.peek().groupSize << endl;
        cout << "Estimated Cooking Time:" << myQueue.peek().cookingTime << endl;
        break;

      case 4: // Serve next group
        if(!pq.isEmpty()){
          totalCookTime = serveNext(totalCookTime);
        }else{
          cout << "Heap empty, cannot dequeue" << endl;
        }
        break;

      case 5: // Serve entire queue
        if(!pq.isEmpty()){
          while(!pq.isEmpty()){
            totalCookTime = serveNext(totalCookTime);
          }
        }else{
          cout << "Heap empty, cannot dequeue" << endl;
        }
        break;

      case 6: // quit
        cout << "Goodbye!" << endl;
        break;
    }
  }


  return 0;
}

int serveNext(int totalCookTime){
  totalCookTime += pq.peek().cookingTime;
  cout << "Group Name: " << pq.peek().groupName << " - Total Cook Time for the Group: " << totalCookTime << endl;
  pq.dequeue();
  return totalCookTime;
}

int menu(){
  int choice;
  cout << "============Main Menu============" << endl;
  cout << "1. Get group information from file" << endl;
  cout << "2. Add a group to Priority Queue" << endl;
  cout << "3. Show next group to Priority Queue" << endl;
  cout << "4. Serve Next group" << endl;
  cout << "5. Serve Entire Queue" << endl;
  cout << "6. Quit" << endl;

  cin >> choice;

  return choice;
}
