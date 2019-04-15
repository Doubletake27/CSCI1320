#include "graphs.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


Graph::Graph(){

}

Graph::~Graph(){
  while(vertices.size()!=1){
    // cout << "Deleting ID: " << vertices[vertices.size()-1].id << endl;
    vertices.pop_back();
  }
  vertices.pop_back();
}

void Graph::addEdge(int v1, int v2){
  for(int i = 0; i < vertices.size();i++){
    if(vertices[i].id==v1){
      for(int j = 0; j < vertices.size(); j++){
        if(vertices[j].id == v2 && i!=j){
          cout << "Adding Edge Between " << v1 << " and " << v2 << endl;
          vertices[i].Edges.push_back(&vertices[j]);
          // add another vertex in the other direction
          vertices[j].Edges.push_back(&vertices[i]);
        }
      }
    }
  }
}

void Graph::addVertex(int id){
  bool found = false;

  for(int i = 0; i< vertices.size(); i++){
    if(vertices[i].id == id){
      found = true;
      cout << vertices[i].id << " already exists" << endl;
    }
  }

  if(!found){
    cout << "Adding Vertex ID: " << id << endl;
    vertex v;
    v.id = id;
    v.visited = false;
    v.dist = 0; //added for Exam
    vertices.push_back(v);
  }
}

void Graph::displayEdges(){

}

void Graph::printDFT(){
  vertex * v = &vertices[0]; //Using the First Vertex
  DFTraversal(v);
}

void Graph::printBFT(){
  vertex * v = &vertices[0];
  BFTraversal(v);
}

void Graph::setAllVerticesUnvisited(){
  for(int i=0; i < vertices.size(); i++){
    vertices[i].visited = false;
    vertices[i].dist = 0;
  }
}

vertex* Graph::findVertex(int id){
  vertex * v = nullptr;
  for(int i=0; i < vertices.size(); i++){
    if(vertices[i].id == id){
      v = &vertices[i];
    }
  }
  return v;
}
/// BEGINNING of EXAM FUNCTION
int Graph::countNodesWithDist(int id, int dist){
  if(Graph::findVertex(id)!=nullptr){
    Graph::setAllVerticesUnvisited();
    Graph::BFTraversal(Graph::findVertex(id));
    int sum = 0;
    for(int i = 0; i < vertices.size(); i++){
      // cout << vertices[i].id << "(" << vertices[i].dist << ") ";
      if(vertices[i].dist == dist){
        sum++;
      }
    }
    // cout << endl;
    return sum;
  }else{
    return 0;
  }
}
/// END of Exam Function

void Graph::BFTraversal(vertex *v){
  // cout << "Starting vertex (root): " << v -> id << "-> ";
  v->visited = true;

  // use the STL queue to keep track of vertices to be visited
  queue<vertex*> q; // Queue to store vertex pointers using built in functions

  // Enqueue the starting vertex
  q.push(v);

  // Need another vertex pointer
  vertex *n;

  while(!q.empty()){
    // q dequeue
    n = q.front(); // peek front of queue
    q.pop(); // removes first value from queue

    for(int x = 0; x < n-> Edges.size(); x++){
      //check if vertex has been visited
      if(!n-> Edges[x]->visited){
        n->Edges[x]->dist = n->dist+1;
        n->Edges[x]->visited = true;
        q.push(n->Edges[x]);
        // cout << n->Edges[x]->id << " ";
      }
    }
  }
  // cout << endl;

}

void Graph::DFTraversal(vertex *v){

}
