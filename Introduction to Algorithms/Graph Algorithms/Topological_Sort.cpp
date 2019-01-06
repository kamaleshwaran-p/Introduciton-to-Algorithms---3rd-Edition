#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
public:
  int v;
  list<int> *adj;
  Graph(int v);
  void addEdge(int u, int v);
  void Topological_Sort();
  void Topological_Sort_Util(int v, bool visited[], stack<int> &St);
};

Graph::Graph(int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int u) {
  adj[v].push_back(u);
}

void Graph::Topological_Sort_Util(int v, bool visited[], stack<int> &St) {
  visited[v] = true;
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      Topological_Sort_Util(*i, visited, St);
  St.push(v);
}

void Graph::Topological_Sort() {
  stack<int> St;
  bool visited[v];
  for (int i = 0; i < v; i++)
    visited[i] = false;
  for (int i = 0; i < v; i++)
    if (!visited[i])
      Topological_Sort_Util(i, visited, St);
  while (!St.empty()) {
    cout << St.top() << " ";
    St.pop();
  }
  cout << endl;
}

int main(void) {
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  g.Topological_Sort();
}
