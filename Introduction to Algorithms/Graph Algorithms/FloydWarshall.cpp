#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MAX 10000

int Arr[4][4] = {{0, 3, MAX, 7},
                 {8, 0, 2, MAX},
                 {5, MAX, 0, 1},
                 {2, MAX, MAX, 0}};

void FloydWarshall(int n) {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        Arr[i][j] = min(Arr[i][j], (Arr[i][k] + Arr[k][j]));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << Arr[i][j] << " ";
    cout << endl;
  }
}

int main(void) {
  FloydWarshall(4);
}
