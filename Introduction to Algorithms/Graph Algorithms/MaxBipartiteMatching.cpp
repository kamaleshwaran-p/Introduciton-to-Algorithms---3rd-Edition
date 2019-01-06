#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define M 6
#define N 6

bool bpm(int graph[M][N], int u, bool seen[], int match[]) {
  for (int v = 0; v < N; v++) {
    if (graph[u][v] && !seen[v]) {
      seen[v] = true;
      if (match[v] < 0 || bpm(graph, match[v], seen, match)) {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}

int maxBPM(int graph[M][N]) {
  int match[N];
  for (int i = 0; i < N; i++)
    match[i] = -1;
  int result = 0;
  for (int u = 0; u < M; u++) {
    bool seen[N];
    for (int i = 0; i < N; i++)
      seen[i] = false;
    if (bpm(graph, u, seen, match))
      result++;
  }
  return result;
}

int main(void) {
  int graph[M][N] = {{0, 1, 1, 0, 0, 0},
                     {1, 0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0, 0},
                     {0, 0, 1, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 1}};
  cout << maxBPM(graph) << endl;
}
