#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main (void) {
  int n, a;
  cin >> n;


  deque<int> D1(n);
  for (int i = 0; i < n; i++)
    cin >> D1[i];
  for (int i = 0; i < n; i++)
    cout << D1[i] << " ";
  cout << endl;
  

  deque<int> D;
  for (int i = 0; i < n; i++) {
    cin >> a;
    i%2 == 0 ? D.push_back(a) : D.push_front(a);
  }

  cout << D.front() << endl;
  cout << D.back() << endl;
  cout << "Size: " << D.size() << endl;
  // printing as it is
  for (auto itr = D.begin(); itr != D.end(); itr++)
    cout << *itr << " ";
  cout << endl;
  // printing in reverse order
  for (auto itr = D.rbegin(); itr != D.rend(); itr++)
    cout << *itr << " ";
  cout << endl;
}

// Inbuit functions
// push_back(a) - Adds the element ‘a’ at the back of the deque
// push_front(a) - Adds the element 'a' at the front of the deque
// emplace_front(a) - Adds the element 'a' at the front of the deque
// emplace_back(a) - Adds the element 'a' at the back of the deque
// insert(itr, a) - Adds the element 'a' at the position itr (itr is the pointer to the position)
// pop_back() - Deletes the last element of the deque
// pop_front() - Deletes the first element of the deque
// size() - Gives the size of the deque
// max_size() - Gives the maximum size of elements that a deque can hold
// resize(a) - resizes the deque to size 'a'
// empty() - Returns a boolean value if the deque is empty or not
// begin() - Returns a pointer to the first element of the deque
// end() - Retunns a pointer to the last element os the deque
// rbegin() - Returns a pointer to the last element of the deque (reverses the positions)
// rend() - Retunrs a pointer to the first element of the deque (reverses the positions)
// assign(s, a) - creates a deque of size 's' where the value of all elements are 'a'
// assign(itr1, itr2) - creates a deque contains elements of values [itr1, itr2)
// clear() - deletes all the elements in the deque
// erase(itr) - deletes the value at the position 'itr'
// erase(itr1, itr2) - deletes all the elements in range [itr1, itr2)
// at(a) - Returns the value at the position 'a'
// deque1.swap(deque2) - swaps deque1 and deque2
