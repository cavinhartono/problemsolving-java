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
      head->next = head;
    }
    else
    {
      last->next = newNode;
      newNode->next = head;
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

  void display()
  {
    if (!head)
    {
      return;
    }

    Node *current = head;
    do
    {
      cout << "Vertex " << current->vertex << " is connection to: ";
      for (int neighbor : current->Neighbors)
      {
        cout << neighbor << " ";
      }
      cout << endl;
      current = current->next;
    } while (current != head);
  }
};

int main()
{
  return 0;
}