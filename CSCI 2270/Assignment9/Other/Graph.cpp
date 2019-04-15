#include "Graph.hpp"
#include <list>

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{

}

// struct vertex
// {
//     std::string name;
//     bool visited;
//     std::vector<Edge> Edges; //stores edges to adjacent vertices
// };

void Graph::addVertex(std::string cityName)
{
  vertex* n = new vertex;
  n->name = cityName;
  vertices.push_back(*n);
  // cout << vertices.size();
}

void Graph::addEdge(std::string city1, std::string city2, int distance)
{
  vertex* cOne = findVertex(city1);
  vertex* cTwo = findVertex(city2);

  Edge* n = new Edge;
  n->distance = distance;
  n->v = cTwo;
  cOne->Edges.push_back(*n);
}

void Graph::displayEdges()
{
  for (int i = 0; i < vertices.size(); i++)
  {
    cout << vertices[i].name << "-->";
    for (int j = 0; j < (vertices[i].Edges).size(); j++)
    {
      cout << vertices[i].Edges[j].v->name << " (" << (vertices[i].Edges[j]).distance << " miles)";
      if (j != (vertices[i].Edges).size() - 1)
      {
        cout << "***";
      }
    }
    cout << endl;
  }
}

void Graph::printDFT()
{
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

void Graph::printBFT()
{
  setAllVerticesUnvisited();
  for (int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i].visited == false)
    {
        cout << vertices[i].name << endl;
    }
    BFT_traversal(&vertices[i]);
  }
}

void Graph::setAllVerticesUnvisited()
{
  for (int i = 0; i < vertices.size(); i++)
  {
    vertices[i].visited = false;
  }
}

vertex* Graph::findVertex(std::string name)
{
  for (int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i].name == name)
    {
      return &(vertices[i]);
    }
  }
  return nullptr;
}

void Graph::BFT_traversal(vertex *v)
{
  list<vertex> queue;

  // Mark the current node as visited and enqueue it
  v->visited = true;
  queue.push_back(*v);

  // 'i' will be used to get all adjacent
  // vertices of a vertex

  while(!queue.empty())
  {
      // Dequeue a vertex from queue and print it
      vertex v = queue.front();
      queue.pop_front();

      // Get all adjacent vertices of the dequeued
      // vertex s. If a adjacent has not been visited,
      // then mark it visited and enqueue it
      for (int i = 0; i < (v.Edges).size(); i++)
      {
          if (!((v.Edges[i]).v->visited))
          {
              cout << v.Edges[i].v->name << endl;
              (v.Edges[i]).v->visited = true;
              queue.push_back(*((v.Edges[i]).v));
          }
      }
  }
}

void Graph::DFT_traversal(vertex *v)
{
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
