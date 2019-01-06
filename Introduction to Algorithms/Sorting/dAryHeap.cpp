#include <bits/stdc++.h>
using namespace std;

#define endl  "\n"
#define PARENT(i, d)  ((i-1) / d)
#define CHILD(i, c, d)  (d*i + c + 1)

class HEAP {
public:
  vector<int> elements;
  int HeapSize = 0;
  int d;
};

void Max_Heapify(HEAP *heap, int i, int n) {
  int larger = i;
  int baseChild = CHILD(i, 0, heap->d);
  for(int j = 0; j < heap->d; j++) {
    int child = baseChild + j;
    if(child < n && heap->elements[child] > heap->elements[larger])
      larger = child;
  }
  if(larger != i) {
    swap(heap->elements[i], heap->elements[larger]);
    Max_Heapify(heap, larger, n);
  }
}

int Maximum(HEAP *heap) {
  return heap->elements[0];
}

int Extract_Max(HEAP *heap) {
  int max = heap->elements[0];
  heap->elements[0] = heap->elements[heap->HeapSize - 1];
  heap->HeapSize--;
  Max_Heapify(heap, 0, heap->HeapSize);
  return max;
}

void Increase_Key(HEAP *heap, int i, int key) {
  if(key < heap->elements[i]) {
    cout << "Key value is smaller than the current elements value\n";
    exit(-1);
  }
  while(i > 0 && heap->elements[PARENT(i, heap->d)] < key) {
    heap->elements[i] = heap->elements[PARENT(i, heap->d)];
    i = PARENT(i, heap->d);
  }
  heap->elements[i] = key;
}

void Insert(HEAP *heap, int key) {
  heap->HeapSize++;
  heap->elements.push_back(key);
  //heap->elements[heap->HeapSize - 1] = INT_MIN;
  Increase_Key(heap, heap->HeapSize-1, key);
}

void Print(HEAP *heap) {
  for(int i = 0; i < heap->HeapSize; i++)
    cout << heap->elements[i] << " ";
  cout << endl;
}

void HeapSort(HEAP *heap) {
  for(int i = heap->elements.size()-1; i >= 0; i--) {
    swap(heap->elements[0], heap->elements[i]);
    Max_Heapify(heap, 0, i);
  }
  for(int i = 0; i < heap->HeapSize; i++)
    cout << heap->elements[i] << " ";
  cout << endl;
}

int main(void) {
  HEAP *heap = new HEAP();
  cin >> heap->d;
  cout << "***** MENU *****\n";
  cout << "1.Insert\n2.Increase_Key\n3.Maximum\n4.Extract_Max\n5.HeapSort\n6.Print\n7.Exit\n";
  int prev = 0;
  while(true) {
    int ch;
    cin >> ch;
    switch (ch) {
      case 1:
        if(prev == 5) {
          // Not need for everytime, but after calling HeapSort it is required to
          // build a Max-Heap before performing Insert
          for(int i = (heap->HeapSize-1/heap->d); i >= 0; i--)
            Max_Heapify(heap, i, heap->HeapSize);
        }
        int num;
        cin >> num;
        Insert(heap, num);
        break;
      case 2:
        int pos, value;
        cin >> pos >> value;
        Increase_Key(heap, pos, value);
        break;
      case 3:
        cout << Maximum(heap) << endl;
        break;
      case 4:
        cout << Extract_Max(heap) << endl;
        break;
      case 5:
        HeapSort(heap);
        break;
      case 6:
        Print(heap);
        break;
      case 7:
        exit(0);
      default:
        cout << "Enter a valid case\n";
        break;
    }
    prev = ch;
  }
}
