// Time Complexity: O(n * log n)
#include <bits/stdc++.h>
using namespace std;

// As array index starts from 0, n changes to n-1 and l & r gets incremented by 1
void Max_Heapify(int Arr[], int i, int n) {
  int larger, l = (2 * i) + 1;
  int r = (2 * i) + 1 + 1;
  if(l <= n-1 && Arr[l] > Arr[i])
    larger = l;
  else
    larger = i;
  if(r <= n-1 && Arr[r] > Arr[larger])
    larger = r;
  if(i != larger) {
    swap(Arr[i], Arr[larger]);
    Max_Heapify(Arr, larger, n);
  }
}

void Min_Heapify(int Arr[], int i, int n) {
  int smaller, l = (2 * i) + 1;
  int r = (2 * i) + 1 + 1;
  if(l <= n-1 && Arr[l] < Arr[i])
    smaller = l;
  else
    smaller = i;
  if(r <= n-1 && Arr[r] < Arr[smaller])
    smaller = r;
  if(i != smaller) {
    swap(Arr[i], Arr[smaller]);
    Min_Heapify(Arr, smaller, n);
  }
}

int main(void) {
  int n;
  cin >> n;
  int Arr[n+1];
  for(int i = 0; i < n; i++)
    cin >> Arr[i];

  // Building Max-Heap
  for(int i = n/2; i >= 0; i--)
    Max_Heapify(Arr, i, n);
  cout << "Max-Heap: ";
  for(int i = 0; i < n; i++)
    cout << Arr[i] << " ";
  cout << endl;

  // HeapSort (Ascending Order)
  // Before doing HeapSort (Ascending Order), we want to create a Max-Heap
  for(int i = n-1; i >= 0; i--) {
    swap(Arr[0], Arr[i]);
    Max_Heapify(Arr, 0, i);
  }
  for(int i = 0; i < n; i++)
    cout << Arr[i] << " ";
  cout << endl;

  // Building Min-Heap
  for(int i = n/2; i >= 0; i--)
    Min_Heapify(Arr, i, n);
  cout << "Min-Heap: ";
  for(int i = 0; i < n; i++)
    cout << Arr[i] << " ";
  cout << endl;

  // HeapSort (Descending Order)
  // Before doing HeapSort (Descending Order), we want to create a Min-Heap
  for(int i = n-1; i >= 0; i--) {
    swap(Arr[0], Arr[i]);
    Min_Heapify(Arr, 0, i);
  }
  for(int i = 0; i < n; i++)
    cout << Arr[i] << " ";
  cout << endl;

  /*
  // Max_Heapify
  while(i <= n) {
    int larger, l = 2 * i;
    int r = (2 * i) + 1;
    if(l <= n && Arr[l] > Arr[i])
      larger = l;
    else
      larger = i;
    if(r <= n && Arr[r] > Arr[larger])
      larger = r;
    if(i != larger)
      swap(Arr[i], Arr[larger]);
    else
      break;
  }

  // Min_Heapify
  while(i <= n) {
    int smaller, l = 2 * i;
    int r = (2 * i) + 1;
    if(l <= n && Arr[l] < Arr[i])
      smaller = l;
    else
      smaller = i;
    if(r <= n && Arr[r] < Arr[smaller])
      smaller = r;
    if(i != smaller)
      swap(Arr[i], Arr[smaller]);
    else
      break;
  }*/
}
