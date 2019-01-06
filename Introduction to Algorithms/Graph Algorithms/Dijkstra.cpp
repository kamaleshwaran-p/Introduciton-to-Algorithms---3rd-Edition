// Vector and Priority Queue Implementation - O(E log V)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

void addEdge(vector<pii> adj[], int u, int v, int w) {
  adj[u].emplace_back(v, w);
  adj[v].emplace_back(u, w);
}

void shortestPath(vector<pii> adj[], int V, int src) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> dist(V, INT_MAX);
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto i : adj[u]) {
      int v = i.first;
      int weight = i.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  for (int i = 0; i < V; i++)
    cout << i << " " << dist[i] << endl;
}

int main(void) {
  int v, e;
  cin >> v >> e;
  vector<pii> adj[v];
  for (int i = 0; i < e; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    addEdge(adj, x-1, y-1, w);
  }
  shortestPath(adj, v, 0);
}



// Matrix Implementation - O(n^2)
/* #include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define V 9

int minDist(int dist[], bool visited[]) {
  int min = INT_MAX, min_index;
  for (int i = 0; i < V; i++)
    if (!visited[i] && dist[i] <= min)
      min = dist[i], min_index = i;
  return min_index;
}

void print(int dist[]) {
  for (int i = 0; i < V; i++)
    cout << i << " " << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src) {
  int dist[V];
  bool visited[V];
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, visited[i] = false;
  dist[src] = 0;
  for (int i = 0; i < V-1; i++) {
    int u = minDist(dist, visited);
    visited[u] = true;
    for (int v = 0; v < V; v++)
      if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u]+graph[u][v])
        dist[v] = dist[u] + graph[u][v];
  }
  print(dist);
}

int main(void) {
  int graph[V][V] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
  };
  dijkstra(graph, 0);
} */
