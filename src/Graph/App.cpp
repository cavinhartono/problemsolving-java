#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph
{
  int v;
  list<int> *adj;

public:
  Graph(int v)
  {
    this->v = v;
    adj = new list<int>[v];
  }

  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
  }

  /* Depth-First Search */
  void dfsUtil(int v, vector<bool> &visited)
  {
    visited[v] = true;

    cout << v << " ";

    for (int i : adj[v])
    {
      if (!visited[i])
      {
        dfsUtil(i, visited);
      }
    }
  }

  void dfs(int v)
  {
    vector<bool> visited(v, false);
    dfsUtil(v, visited);
  }

  /* Breadth-First Search */
  void bfs(int s)
  {
    vector<bool> visited(v, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
      s = q.front();
      cout << s << " ";
      q.pop();
    }

    for (int i : adj[s])
    {
      if (!visited[i])
      {
        visited[i] = true;
        q.push(i);
      }
    }
  }

  /* Iterative Deepening Search */
  bool depthLimitedSearch(int v, int target, int limit)
  {
    if (v == target)
    {
      cout << v << " ";
      return true;
    }

    if (limit <= 0)
      return false;

    for (int i : adj[v])
    {
      if (depthLimitedSearch(i, target, (limit - 1)))
      {
        cout << v << " ";
        return true;
      }
    }

    return false;
  }

  bool ids(int v, int target)
  {
    int limit = 0;

    while (true)
    {
      if (depthLimitedSearch(v, target, limit))
      {
        return true;
      }
      limit++;
    }

    return false;
  }
};

int main()
{
  Graph graph(4);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(2, 3);
  graph.addEdge(3, 3);

  cout << "\nDFS dimulai dari vertex 2: " << endl;
  graph.dfs(2);

  cout << "\nBFS dimulai dari vertex 2: " << endl;
  graph.bfs(2);

  cout << "\nIDS dimulai dari vertex 2: " << endl;
  graph.ids(0, 2);

  return 0;
}