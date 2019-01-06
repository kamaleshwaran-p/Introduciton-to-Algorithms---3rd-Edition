#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Edge {
public:
  int src, dest;
};

class Graph {
public:
  int V, E;
  Edge* edge;
};

Graph* CreateGraph(int V, int E) {
  Graph* graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

int Find(int parent[], int i) {
  if (parent[i] == -1)
    return i;
  return Find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
  int xset = Find(parent, x);
  int yset = Find(parent, y);
  if (xset != yset)
    parent[xset] = yset;
}

int isCycle(Graph* graph) {
  int *parent = new int[graph->V];
  memset(parent, -1, sizeof(int)*graph->V);
  for (int i = 0; i < graph->E; i++) {
    int x = Find(parent, graph->edge[i].src);
    int y = Find(parent, graph->edge[i].dest);
    if (x == y)
      return 1;
    Union(parent, x, y);
  }
  return 0;
}

int main(void) {
  int V = 3, E = 3;
  Graph* graph = CreateGraph(V, E);
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[1].src = 1;
  graph->edge[1].dest = 2;
  graph->edge[2].src = 0;
  graph->edge[2].dest = 2;
  (isCycle(graph)) ? cout << "YES\n" : cout << "NO\n";
}
