#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
  int v;
  list<int> *adj;
  void fillOrder(int v, bool visited[], stack<int> &st);
  void DFSUtil(int v, bool visited[]);
public:
  Graph(int v);
  void addEdge(int v, int u);
  void printSCC();
  Graph GraphTranspose();
};

Graph::Graph(int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      DFSUtil(*i, visited);
}

Graph Graph::GraphTranspose() {
  Graph g(v);
  for (int i = 0; i < v; i++) {
    list<int>::iterator itr;
    for (itr = adj[i].begin(); itr != adj[i].end(); itr++)
      g.adj[*itr].push_back(i);
  }
  return g;
}

void Graph::addEdge(int v, int u) {
  adj[v].push_back(u);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &st) {
  visited[v] = true;
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      fillOrder(*i, visited, st);
  st.push(v);
}

void Graph::printSCC() {
  stack<int> st;
  bool visited[v];
  for (int i = 0; i < v; i++)
    visited[i] = false;
  for (int i = 0; i < v; i++)
    if (!visited[i])
      fillOrder(i, visited, st);
  Graph Gt = GraphTranspose();
  for (int i = 0; i < v; i++)
    visited[i] = false;
  while (!st.empty()) {
    int V = st.top();
    st.pop();
    if (!visited[V]) {
      Gt.DFSUtil(V, visited);
      cout << endl;
    }
  }
}

int main(void) {
  Graph g(5);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.printSCC();
}
