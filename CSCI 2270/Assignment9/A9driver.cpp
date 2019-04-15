#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#include "Graph.hpp"

using namespace std;

int main(int argc, char* argv[]){
  if (argc > 0)
  {
    string filename = argv[1];
    Graph g;

    vector<vector<string>> myVector;
    ifstream GraphFile;
    GraphFile.open(filename);
    if (GraphFile.is_open())
    {
      string line;
      while (getline(GraphFile,line))
      {
        string item;
        stringstream ss(line);
        vector<string> myRow;
        while (getline(ss,item,','))
        {
          myRow.push_back(item);
        }
        myVector.push_back(myRow);
      }

      for (int i = 0; i < myVector.size(); i++)
      {
        for (int j = 1; j < myVector[i].size(); j++)
        {
          if (i == 0)
          {
            g.addVertex(myVector[i][j]);
            //cout << myVector[i][j];
          }
          else
          {
            if (stoi(myVector[i][j]) > 0)
            {
              g.addEdge(myVector[i][0], myVector[0][j], stoi(myVector[i][j]));
              cout << " ... Reading in " << myVector[i][0] << " -- " << myVector[0][j] << " -- " << myVector[i][j] << endl;
            }
          }
        }
      }
    }
    
    cout << "------------------------------" << endl;
    cout << "Breadth First Traversal" << endl;
    cout << "------------------------------" << endl;

    g.printBFT();


    cout << "------------------------------" << endl;
    cout << "Depth First Traversal" << endl;
    cout << "------------------------------" << endl;

    g.printDFT();

    cout << "------------------------------" << endl;
    cout << "Display Edges" << endl;
    cout << "------------------------------" << endl;

    g.displayEdges();
  }
  else
  {
    cout << "error in input" << endl;
  }

  return 0;
}
