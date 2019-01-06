#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main (void) {
  int n, a;
  cin >> n;
  queue<int> Q;

  for (int i = 0; i < n; i++) {
    cin >> a;
    Q.push(a);
  }

  cout << "Size: " << Q.size() << endl;

  while (!Q.empty()) {
    cout << Q.front() << " ";
    Q.pop();
  }
  cout << endl;
}

// Inbuit functions:
// empty() – Returns whether the queue is empty
// size() – Returns the size of the queue
// front() – Returns a reference to the first element of the queue
// back() – Returns a reference to the last element of the queue
// push(g) – Adds the element ‘g’ at the end of the queue
// pop() – Deletes the first element of the queue
