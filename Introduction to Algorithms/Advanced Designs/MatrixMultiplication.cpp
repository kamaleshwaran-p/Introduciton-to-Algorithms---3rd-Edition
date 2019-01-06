#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int m[10][10], s[10][10];

// Time Complexity - n^3
// Space Complexity - n^2
void matrix_multiplication(int p[], int n) {
  for (int i = 1; i < n; i++)
    m[i][i] = 0;
  for (int l = 2; l < n; l++) {
    for (int i = 1; i < n-l+1; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k <= j-1; k++) {
        int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
}

void print_parens(int i, int j) {
  if (i == j)
    cout << "A" << i;
  else {
    cout << "(";
    print_parens(i, s[i][j]);
    print_parens(s[i][j]+1, j);
    cout << ")";
  }
}

int main(void) {
  int n;
  cin >> n;
  int p[n+1];
  for (int i = 0; i <= n; i++)
    cin >> p[i];
  matrix_multiplication(p, n+1);
  print_parens(1, n);
  cout << endl;
}
