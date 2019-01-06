#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int sum(int freq[], int i, int j) {
  int s = 0;
  for (int k = i; k <= j; k++)
    s += freq[k];
  return s;
}
// Time Complexity - O(n^4)
int Optimal_BST(int keys[], int freq[], int n) {
  int cost[n][n], root[n][n];
  for (int i = 0; i < n; i++)
    cost[i][i] = freq[i];
  for (int l = 1; l <= n; l++) {
    for (int i = 0; i <= n-l+1; i++) {
      int j = i + l - 1;
      cost[i][j] = INT_MAX;
      for (int r = i; r <= j; r++) {
        int t = ((r > i) ? cost[i][r-1]:0) + ((r < j) ? cost[r+1][j]:0) + sum(freq, i, j);
        if (t < cost[i][j]) {
          cost[i][j] = t;
          root[i][j] = r;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      (i > j) ? cout << 0 << " " : cout << cost[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      (i >= j) ? cout << 0 << " " : cout << root[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}



int main(void) {
  int keys[] = {4, 6, 8, 2, 10, 12, 14};
  int freq[] = {6, 6, 6, 5, 5, 5, 5};
  int n = 7;
  Optimal_BST(keys, freq, n);
}
