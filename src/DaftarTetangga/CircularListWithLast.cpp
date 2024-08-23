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

  void deleteVertex(int v)
  {
    if (vertexMap.find(v) == vertexMap.end())
    {
      return;
    }

    Node *node = vertexMap[v];
    Node *temp = head;

    while (temp->next != node)
    {
      temp = temp->next;
    }

    if (node == head && head->next == head)
    {
      delete head;
      head = last = nullptr;
    }
    else
    {
      temp->next = node->next;

      if (node == head)
      {
        head = node->next;
        last->next = head;
      }

      if (node == last)
      {
        last = temp;
      }
      delete node;
    }

    for (int neighbor : vertexMap[v]->Neighbors)
    {
      vertexMap[neighbor]->Neighbors.remove(v);
    }

    vertexMap.erase(v);
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
  Graph graph;

  graph.insertVertex(1);
  graph.insertVertex(2);
  graph.insertVertex(3);
  graph.insertVertex(4);

  graph.insertEdge(1, 2);
  graph.insertEdge(2, 3);
  graph.insertEdge(3, 4);

  cout << endl;
  graph.display();

  cout << "jika nomor vertex ke-3 dihapus..." << endl;
  graph.deleteVertex(3);
  cout << endl;
  graph.display();

  cout << "jika bagian 1 dan 3 dihapus..." << endl;
  graph.deleteEdge(1, 3);
  cout << endl;
  graph.display();

  return 0;
}