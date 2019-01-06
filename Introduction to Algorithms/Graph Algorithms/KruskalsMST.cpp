#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Edge {
public:
  int src, dest, weight;
};

class Graph {
public:
  int V, E;
  Edge *edge;
};

Graph *CreateGraph(int v, int e) {
  Graph *graph = new Graph;
  graph->V = v;
  graph->E = e;
  graph->edge = new Edge[e];
  return graph;
}

class Subset {
public:
  int parent;
  int rank;
};

int find(Subset subset[], int i) {
  if (subset[i].parent != i)
    subset[i].parent = find(subset, subset[i].parent);
  return subset[i].parent;
}

void Union(Subset subset[], int x, int y) {
  int xroot = find(subset, x);
  int yroot = find(subset, y);
  if (subset[xroot].rank > subset[yroot].rank)
    subset[yroot].parent = xroot;
  else if (subset[xroot].rank < subset[yroot].rank)
    subset[xroot].parent = yroot;
  else {
    subset[yroot].parent = xroot;
    subset[xroot].rank++;
  }
}

/*int Comp(const void *a, const void *b) {
  Edge *a1 = (Edge *)a;
  Edge *b1 = (Edge *)b;
  return (a1->weight > b1->weight);
}*/

bool Compare(Edge a, Edge b) {
  return (a.weight < b.weight);
}

void KruskalsMST(Graph *graph) {
  int V = graph->V;
  Edge result[V];
  int e = 0;
  int i = 0;
  sort(graph->edge, (graph->edge + graph->E), Compare);
//  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), Comp);
  Subset subset[V];
  for (int v = 0; v < V; v++) {
    subset[v].parent = v;
    subset[v].rank = 0;
  }
  while (e < V-1) {
    Edge next_edge = graph->edge[i++];
    int x = find(subset, next_edge.src);
    int y = find(subset, next_edge.dest);
    if (x != y) {
      result[e++] = next_edge;
      Union(subset, x, y);
    }
  }
  for (int j = 0; j < e; j++)
    cout << result[j].src << " " << result[j].dest << "->" << result[j].weight << endl;
}

int main(void) {
  int V = 4;
  int E = 5;
  Graph *graph = CreateGraph(V, E);

  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[0].weight = 10;

  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[1].weight = 6;

  graph->edge[2].src = 0;
  graph->edge[2].dest = 3;
  graph->edge[2].weight = 5;

  graph->edge[3].src = 1;
  graph->edge[3].dest = 3;
  graph->edge[3].weight = 15;

  graph->edge[4].src = 2;
  graph->edge[4].dest = 3;
  graph->edge[4].weight = 4;

  KruskalsMST(graph);
}
