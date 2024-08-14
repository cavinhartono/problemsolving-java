#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &adj, int s, int t)
{
  adj[s].push_back(t);
  adj[t].push_back(s);
}

void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
  visited[s] = true;

  cout << s << " ";

  for (int i : adj[s])
  {
    if (!visited[s])
    {
      dfsRec(adj, visited, s);
    }
  }
}

void dfs(vector<vector<int>> &adj, int s)
{
  vector<bool> visited(adj.size(), false);
  dfsRec(adj, visited, s);
}

int main(int argc, char const *argv[])
{
  int v = 5;

  vector<vector<int>> adj(v);

  vector<vector<int>> Edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};

  for (auto &edge : Edges)
  {
    addEdge(adj, edge[0], edge[1]);
  }

  int source = 1;
  cout << "DFS from source: " << source << endl;
  dfs(adj, source);

  return 0;
}