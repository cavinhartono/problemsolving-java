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
  Node *last;
  unordered_map<int, Node *> vertexMap;

public:
  Graph() : head(nullptr), last(nullptr) {}

  void insertVertex(int v)
  {
    Node *newNode = new Node{v, {}, nullptr, nullptr};

    if (!head)
    {
      head = last = newNode;
    }
    else
    {
      last->next = newNode;
      newNode->prev = last;
      last = newNode;
    }
    vertexMap[v] = newNode;
  }
};

int main()
{
  Graph graph;

  graph.insertVertex(1);
  graph.insertVertex(2);
  graph.insertVertex(3);
  
  return 0;
}