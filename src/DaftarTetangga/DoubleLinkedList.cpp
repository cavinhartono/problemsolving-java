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
    Node *prev;
    Node *next;
  };

  Node *head;
  Node *tail;
  unordered_map<int, Node *> vertexMap;

public:
  Graph() : head(nullptr), tail(nullptr){};

  void insertVertex(int v)
  {
    Node *newNode = new Node{v, {}, nullptr, nullptr};
    if (!head)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
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
      vertexMap[v]->Neighbors.remove(w);
      vertexMap[w]->Neighbors.remove(v);
    }
  }

  void display()
  {
    Node *current = head;
    while (current)
    {
      cout << "Vertex " << current->vertex << " is connected to: ";
      for (int neighbor : current->Neighbors)
        cout << neighbor << " ";
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
  graph.display();

  return 0;
}