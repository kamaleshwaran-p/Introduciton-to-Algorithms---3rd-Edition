// Time Complexity: O(n * log n) -> [Expected RunTime]
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int partition(int Arr[], int l, int r) {
  int i(l - 1);
  int x(Arr[r]);
  for(int j(l); j < r; j++) {
    if(Arr[j] <= x) {
      i++;
      swap(Arr[i], Arr[j]);
    }
  }
  swap(Arr[i+1], Arr[r]);
  return i+1;
}

void quickSort(int Arr[], int l, int r) {
  if(l < r) {
    int m = partition(Arr, l, r);
    quickSort(Arr, l, m-1);
    quickSort(Arr, m+1, r);
  }
}

int main(void) {
  int n;
  cin >> n;
  int Arr[n];
  for(int i(0); i < n; i++)
    cin >> Arr[i];
  quickSort(Arr, 0, n-1);
  for(int i(0); i < n; i++)
    cout << Arr[i] << " ";
  cout << endl;
}
