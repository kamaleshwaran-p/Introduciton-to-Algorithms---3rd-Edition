#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int Arr[4][4] = {{1, 0, 0, 0},
                 {0, 1, 1, 1},
                 {0, 1, 1, 0},
                 {1, 0, 1, 1}};

void TransitiveClosure(int n) {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        Arr[i][j] = Arr[i][j] | (Arr[i][k] & Arr[k][j]);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << Arr[i][j] << " ";
    cout << endl;
  }
}

int main(void) {
  TransitiveClosure(4);
}
