#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// Run Time - 2^n
int rodCut(int Arr[], int n) {
  if (n == 0)
    return 0;
  int q = INT_MIN;
  for (int i = 1; i <= n; i++)
    q = max(q, Arr[i]+rodCut(Arr, n-i));
  return q;
}

int cutRodTopDown(int Arr[], int n, int Res[]) {
  if (Res[n] >= 0)
    return Res[n];
  int q;
  if (n == 0)
    q = 0;
  else {
    q = INT_MIN;
    for (int i = 1; i <= n; i++)
      q = max(q, Arr[i]+cutRodTopDown(Arr, n-i, Res));
  }
  Res[n] = q;
  return q;
}
// Run Time - n^2
int topDown(int Arr[], int n) {
  int Res[n+1];
  for (int i = 0; i <= n; i++)
    Res[i] = INT_MIN;
  return cutRodTopDown(Arr, n, Res);
}

// Run Time - n^2
int bottomUp(int Arr[], int n) {
  int Res[n+1];
  Res[0] = 0;
  for (int i = 1; i <= n; i++) {
    int q = INT_MIN;
    for (int j = 1; j <= i; j++)
      q = max(q, Arr[j]+Res[i-j]);
    Res[i] = q;
  }
  return Res[n];
}

int main(void) {
  // input from 1 to 10, since length of the rod if less than or equal to 10
  // as the array input has only the values of 10 slices
  int Arr[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  int n;
  cin >> n;
  cout << rodCut(Arr, n) << endl;
  cout << topDown(Arr, n) << endl;
  cout << bottomUp(Arr, n) << endl;
}
