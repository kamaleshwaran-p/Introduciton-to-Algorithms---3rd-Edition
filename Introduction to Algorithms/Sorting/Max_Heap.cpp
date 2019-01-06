// Time Complexity: O(n * log n)
#include <bits/stdc++.h>
using namespace std;

void Print(priority_queue<int> p) {
  priority_queue<int> pq = p;
  while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

int main(void) {
  int n;
  cin >> n;
  priority_queue<int> p;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    p.push(a);
  }
  Print(p);
}

// Inbuilt functions
// push(a)  a: input
// size()
// empty()
// top()
// pop()
