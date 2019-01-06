#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n;
int **arr;

void LUdecomposition() {
  int L[n][n], U[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      U[i][j] =0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      (i == j) ? L[i][j] = 1 : L[i][j] = 0;
  for (int k = 0; k < n; k++) {
    U[k][k] = arr[k][k];
    for (int i = k+1; i < n; i++) {
      L[i][k] = arr[i][k] / U[k][k];
      U[k][i] = arr[k][i];
    }
    for (int i = k+1; i < n; i++)
      for (int j = k+1; j < n; j++)
        arr[i][j] = arr[i][j] - (L[i][k] * U[k][j]);
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << L[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << U[i][j] << " ";
    cout << endl;
  }
}

int main(void) {
  cin >> n;
  arr = new int*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }
  LUdecomposition();
}
