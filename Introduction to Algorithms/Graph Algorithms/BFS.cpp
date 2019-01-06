#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
public:
  int v;
  list<int> *adj;
  Graph(int v);
  void addEdge(int v, int u);
  void BFS(int s);
};

Graph::Graph(int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int u) {
  adj[v].push_back(u);
}

void Graph::BFS(int s) {
  bool visited[v];
  for (int i = 0; i < v; i++)
    visited[i] = false;
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty()) {
    s = q.front();
    cout << s << " ";
    q.pop();
    for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
      if (!visited[*i]) {
        visited[*i] = true;
        q.push(*i);
      }
    }
  }
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
  g.BFS(2);
}
