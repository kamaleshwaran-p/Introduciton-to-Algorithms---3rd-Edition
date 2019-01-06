#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node {
public:
  int v;
  int weight;
  Node(int _v, int _weight) { v = _v; weight = _weight; }
  int getV() { return v; }
  int getWeight() { return weight; }
};

class Graph {
public:
  int V;
  list<Node> *adj;
  void topologicalSort(int v, bool visited[], stack<int> &st);
  Graph(int V);
  void addEdge(int u, int v, int weight);
  void shortestPath(int s);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<Node>[V];
}

void Graph::addEdge(int u, int v, int weight) {
  Node node(v, weight);
  adj[u].push_back(node);
}

void Graph::topologicalSort(int v, bool visited[], stack<int> &st) {
  visited[v] = true;
  list<Node>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); i++) {
    Node node = *i;
    if (!visited[node.getV()])
      topologicalSort(node.getV(), visited, st);
  }
  st.push(v);
}

void Graph::shortestPath(int s) {
  stack<int> st;
  int dist[V];
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;
  for (int i = 0; i < V; i++)
    if (!visited[i])
      topologicalSort(i, visited, st);
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[s] = 0;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    list<Node>::iterator i;
    if (dist[u] != INT_MAX)
      for (i = adj[u].begin(); i != adj[u].end(); i++)
        if (dist[i->getV()] > dist[u] + i->getWeight())
          dist[i->getV()] = dist[u] + i->getWeight();
  }
  for (int i = 0; i < V; i++)
    (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
  cout << endl;
}

int main(void) {
  Graph g(6);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 3, 6);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(2, 3, 7);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);
  int s = 1;
  g.shortestPath(s);
}
