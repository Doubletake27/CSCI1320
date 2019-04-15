#include <iostream>
#include <vector>
#include "graphs.hpp"

using namespace std;


int main(){

  //// TEST CASE 1 -- Provided
  cout << "--- Test Graph 1 -- Provided ---" << endl;

  Graph g;

  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);
  g.addVertex(4);
  g.addVertex(5);

  cout << endl;
  // Adding Edges
  g.addEdge(1,4);
  g.addEdge(4,2);
  g.addEdge(4,5);
  g.addEdge(2,5);
  g.addEdge(5,3);

  cout << endl;

  // These are the test cases presented in the problem example
  cout << "TEST1.1: ID = 2, DIST = 1; Count = " << g.countNodesWithDist(2,1) << endl; // Should Return 2
  cout << "TEST1.2: ID = 3, DIST = 2; Count = " << g.countNodesWithDist(3,2) << endl; // Should Return 2
  cout << "TEST1.3: ID = 3, DIST = 3; Count = " << g.countNodesWithDist(3,3) << endl; // Should Return 1
  cout << "TEST1.4: ID = 6, DIST = 1; Count = " << g.countNodesWithDist(6,1) << endl; // Should Return 0


  g.~Graph();

  //// TEST CASE 2 -- Its A Circle
  cout << endl;
  cout << "--- Test Graph 2  -- Its a Circle ---" << endl;

  Graph h;


  h.addVertex(1);
  h.addVertex(2);
  h.addVertex(3);
  h.addVertex(4);
  h.addVertex(5);

  cout << endl;
  // Adding Edges
  h.addEdge(1,2);
  h.addEdge(2,3);
  h.addEdge(3,4);
  h.addEdge(4,5);
  h.addEdge(5,1);

  // cout << "Sucessfully Added that Edge" << endl;

  cout << endl;

  h.printBFT();

  // These are the test cases presented in the problem examples
  cout << "TEST2.1: ID = 1, DIST = 1; Count = " << h.countNodesWithDist(1,1) << endl; // Should Return 2
  cout << "TEST2.2: ID = 3, DIST = 2; Count = " << h.countNodesWithDist(3,2) << endl; // Should Return 2

  h.~Graph();

  // cout << endl << endl;


  // sg.printBFT();

  return 0;
}
