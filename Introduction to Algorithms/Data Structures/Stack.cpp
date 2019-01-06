#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
  int n, a;
  cin >> n;
  stack<int> S;

  for (int i = 0; i < n; i++) {
    cin >> a;
    S.push(a);
  }

  cout << "Size: " << S.size() << endl;

  while (!S.empty()) {
    cout << S.top() << " ";
    S.pop();
  }
  cout << endl;
}

// Inbuit functions:
// empty() – Returns whether the stack is empty
// size() – Returns the size of the stack
// top() – Returns a reference to the top most element of the stack
// push(g) – Adds the element ‘g’ at the top of the stack
// pop() – Deletes the top most element of the stack
