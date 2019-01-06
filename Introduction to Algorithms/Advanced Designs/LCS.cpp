#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

char b[10][10];
int c[10][10];

// Time Complexity - O(m*n)
void LCS(string X, string Y) {
  int m = X.length(), n = Y.length();
  for (int i = 1; i <= m; i++)
    c[i][0] = 0;
  for (int i = 0; i <= n; i++)
    c[0][i] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i] == Y[j]) {
        c[i][j] = c[i-1][j-1] + 1;
        b[i][j] = '/';
      } else if (c[i-1][j] >= c[i][j-1]) {
        c[i][j] = c[i-1][j];
        b[i][j] = '|';
      } else {
        c[i][j] = c[i][j-1];
        b[i][j] = ' ';
      }
    }
  }
}

void print_LCS(string X, int i, int j) {
  if (i == 0 || j == 0)
    return;
  if (b[i][j] == '/') {
    print_LCS(X, i-1, j-1);
    cout << X[i];
  } else if (b[i][j] == '|') {
    print_LCS(X, i-1, j);
  } else {
    print_LCS(X, i, j-1);
  }
}

int main(void) {
  string str1, str2;
  cin >> str1 >> str2;
  LCS(str1, str2);
  print_LCS(str1, str1.length(), str2.length());
  cout << endl;
}
