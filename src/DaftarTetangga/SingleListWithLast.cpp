#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class Graph
{
  struct Node
  {
    int vertex;
    list<int> Neighbors;
    Node *next;
  };
  Node *head;
  Node *last;
  unordered_map<int, Node *> vertexMap;

public:
  Graph() : head(nullptr), last(nullptr) {}

  void insertVertex(int v)
  {
    Node *newNode = new Node{v, {}, nullptr};
    if (!head)
    {
      head = last = newNode;
    }
    else
    {
      last->next = newNode;
      last = newNode;
    }
    vertexMap[v] = newNode;
  }

  void insertEdge(int v, int w)
  {
    if (vertexMap.find(v) != vertexMap.end() && vertexMap.find(w) != vertexMap.end())
    {
      vertexMap[v]->Neighbors.push_back(w);
      vertexMap[w]->Neighbors.push_back(v);
    }
  }

  void deleteEdge(int v, int w)
  {
    if (vertexMap.find(v) != vertexMap.end() && vertexMap.find(w) != vertexMap.end())
    {
      vertexMap[v]->Neighbors.remove(v);
      vertexMap[w]->Neighbors.remove(w);
    }
  }

  void display()
  {
    Node *current = head;

    while (current)
    {
      cout << "Vertex " << current->vertex << " is connected to ";
      for (int neighbor : current->Neighbors)
      {
        cout << neighbor << " ";
      }
      cout << endl;
      current = current->next;
    }
  }
};

int main()
{
  Graph graph;

  graph.insertVertex(1);
  graph.insertVertex(2);
  graph.insertVertex(3);

  graph.insertEdge(1, 2);
  graph.insertEdge(2, 3);

  cout << endl;
  graph.display();

  return 0;
}