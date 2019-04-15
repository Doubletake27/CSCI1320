#include "Graph.hpp"
#include <vector>
#include <queue>
// #include <iostream>

using namespace std;

// Public Functions
Graph::Graph(){}
Graph::~Graph(){}

void Graph::addVertex(std::string cityName){
  bool found = false;

  for(int i = 0; i< vertices.size(); i++){
    if(vertices[i].name == cityName){
      found = true;
      cout << vertices[i].name << " already exists" << endl;
    }
  }

  if(!found){
    vertex v;
    v.name = cityName;
    vertices.push_back(v);
  }

}

void Graph::addEdge(std::string city1, std::string city2, int distance){
  for(int i = 0; i < vertices.size();i++){
    if(vertices[i].name==city1){
      for(int j = 0; j < vertices.size(); j++){
        if(vertices[j].name == city2 && i!=j){
          Edge av;
          av.v = &vertices[j];
          av.distance =distance;
          vertices[i].Edges.push_back(av);
          // add another vertex in the other direction
          // Edge av2;
          // av2.v = &vertices[i];
          // av2.distance =distance;
          // vertices[j].Edges.push_back(av2);
        }
      }
    }
  }
}

void Graph::displayEdges(){
  for (int i = 0; i < vertices.size(); i++){
    cout << vertices[i].name << "-->";
    for (int j = 0; j < (vertices[i].Edges).size(); j++){
      cout << vertices[i].Edges[j].v->name << " (" << (vertices[i].Edges[j]).distance << " miles)";
      if (j != (vertices[i].Edges).size() - 1){
        cout << "***";
      }
    }
    cout << endl;
  }
}

void Graph::printDFT(){
  // DFT_traversal(&vertices[0]);
  setAllVerticesUnvisited();
  for (int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i].visited == false)
    {
        cout << vertices[i].name << endl;
    }
    DFT_traversal(&vertices[i]);
  }
}

void Graph::printBFT(){
  BFT_traversal(&vertices[0]);
}

void Graph::setAllVerticesUnvisited(){
  for(int i=0; i < vertices.size(); i++){
    vertices[i].visited = false;
  }
}

// Private Functions
vertex*  Graph::findVertex(std::string name){ // May have to move the *
  vertex * v = nullptr;
  for(int i=0; i < vertices.size(); i++){
    if(vertices[i].name == name){
      v = &vertices[i];
      break;
    }
  }
  return v;
}

void Graph::BFT_traversal(vertex *v){
  Graph::setAllVerticesUnvisited();

  cout << v->name << endl;
  vertex * vStart = v;
  // vStart->visited = true;

  // use the STL queue to keep track of vertices to be visited
  queue<vertex*> q; // Queue to store vertex pointers using built in functions

  // Need another vertex pointer
  vertex *n;

  // Enqueue the starting vertex
  q.push(vStart);

  bool allVisited = false;
  vertex *next;


  while(!allVisited){
    while(!q.empty()){
      // q dequeue
      n = q.front(); // peek front of queue
      n->visited = true;
      q.pop(); // removes first value from queu e

      for(int x = 0; x < n-> Edges.size(); x++){
        //check if vertex has been visited
        if(!n-> Edges[x].v->visited){
          n->Edges[x].v->visited = true;
          q.push(n->Edges[x].v);
          cout << n->Edges[x].v->name << endl;
        }
      }
    }

    allVisited = true;
    for(int i = 0; i < vertices.size();i++){
      if(!vertices[i].visited){
        allVisited = false;
        next = &vertices[i];
        q.push(next);
        cout << next->name << endl;
        // n->visited = true;
        break;
      }
    }
  }

}

void Graph::DFT_traversal(vertex *v){
  v->visited = true;
  for (int j = 0; j < (v->Edges).size(); j++)
  {
    if((v->Edges[j]).v->visited == false)
    {

      cout << v->Edges[j].v->name << endl;
      DFT_traversal((v->Edges[j].v));
    }
  }
}
