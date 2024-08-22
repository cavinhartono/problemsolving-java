#include <iostream>
#include <unordered_map>
#include <list>

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
  unordered_map<int, Node *> vertexMap;

public:
  Graph() : head(nullptr) {}

  void insertVertex(int v)
  {
    Node *newNode = new Node{v, {}, nullptr};
    if (!head)
    {
      head = newNode;
      head->next = head;
    }
    else
    {
      Node *temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
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
      head = nullptr;
    }
    else
    {
      temp->next = node->next;

      /* Mengecek apakah `head` cuman satu? */
      if (node == head)
      {
        head = node->next;
      }
      else
      {
        temp->next = node->next;

        if (node == head)
        {
          head = node->next;
        }

        delete node;
      }
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
      cout << "Vertex " << current->vertex << " is connected to: ";
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

  graph.insertEdge(1, 2);
  graph.insertEdge(2, 3);

  cout << endl;
  graph.display();

  graph.deleteVertex(2);
  graph.display();

  return 0;
}