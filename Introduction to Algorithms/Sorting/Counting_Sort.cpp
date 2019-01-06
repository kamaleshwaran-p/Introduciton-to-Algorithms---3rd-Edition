// Time Complexity: O(k + n)    k -> max value in the input array
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void Counting_Sort(int A[], int B[], int n, int k) {
  int C[k+1];
  for(int i = 0; i <= k; i++)
    C[i] = 0;
  for(int i = 0; i < n; i++)
    C[A[i]]++;
  for(int i = 1; i <= k; i++)
    C[i] += C[i-1];
  for(int i = n-1; i >= 0; i--) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }
}

int main(void) {
  int n;
  cin >> n;
  int A[n], B[n];
  for(int i = 0; i < n; i++)
    cin >> A[i];
  int max = INT_MIN;
  for(int i = 0; i < n; i++)
    if(max < A[i])
      max = A[i];
  Counting_Sort(A, B, n, max);
  for(int i = 0; i < n; i++)
    cout << B[i] << " ";
  cout << endl;
}
