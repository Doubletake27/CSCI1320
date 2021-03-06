#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


void Graph::addEdge(string v1, string v2){
  for(int i = 0; i < vertices.size();i++){
    if(vertices[i].name==v1){
      for(int j = 0; j < vertices.size(); j++){
        if(vertices[j].name == v2 && i!=j){
          adjVertex av;
          av.v = &vertices[j];
          vertices[i].adj.push_back(av);
          // add another vertex in the other direction
          adjVertex av2;
          av2.v = &vertices[i];
          vertices[j].adj.push_back(av2);
        }
      }
    }
  }
}

void Graph::addVertex(string n){
  bool found = false;

  for(int i = 0; i< vertices.size(); i++){
    if(vertices[i].name == n){
      found = true;
      cout << vertices[i].name << " already exists" << endl;
    }
  }

  if(!found){
    vertex v;
    v.name = n;
    v.distance = 0;
    vertices.push_back(v);
  }

}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<" --> ";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v->name << " ";
        }
        cout<<endl;
    }

}

void Graph::breadthFirstTraverse(string sourceVertex){
  // Since we don't have a search function, implement
  // here to find the starting vertex

  // need a pointer to keep track of starting vertex

  vertex *vStart;

  for(int i=0; i < vertices.size(); i++){
    if(vertices[i].name == sourceVertex){
      vStart = &vertices[i];
    }
  }

  cout << "Starting vertex (root): " << vStart -> name << "-> ";
  vStart->visited = true;

  // use the STL queue to keep track of vertices to be visited
  queue<vertex*> q; // Queue to store vertex pointers using built in functions

  // Enqueue the starting vertex
  q.push(vStart);

  // Need another vertex pointer
  vertex *n;

  while(!q.empty()){
    // q dequeue
    n = q.front(); // peek front of queue
    q.pop(); // removes first value from queue

    for(int x = 0; x < n-> adj.size(); x++){
      //check if vertex has been visited
      if(!n-> adj[x].v->visited){
        n->adj[x].v->distance = n-> distance +1;
        n->adj[x].v->visited = true;
        q.push(n->adj[x].v);
        cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ") ";
      }
    }
  }
  cout << endl;
  // Henry's Custom Clearing Fuction
  for(int i=0; i < vertices.size(); i++){
    vertices[i].visited = false;
    vertices[i].distance = 0;
  }
  // End
}
