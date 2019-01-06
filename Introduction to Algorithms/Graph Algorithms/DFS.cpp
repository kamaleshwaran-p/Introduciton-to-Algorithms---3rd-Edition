#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
public:
  int v;
  list<int> * adj;
  Graph(int v);
  void DFSUtil(int v, bool visited[]);
  void addEdge(int v, int u);
  void DFS(int v);
};

Graph::Graph(int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int u) {
  adj[v].push_back(u);
}

void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      DFSUtil(*i, visited);
}

void Graph::DFS(int v) {
  bool visited[v];
  for (int i = 0; i < v; i++)
    visited[i] = false;
  DFSUtil(v, visited);
  cout << endl;
}

int main(void) {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.DFS(2);
}
