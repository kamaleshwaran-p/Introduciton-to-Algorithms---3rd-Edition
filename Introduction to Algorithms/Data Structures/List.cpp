#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
  int n, a;
  cin >> n;
  list<int> ls;
  for (int i = 0; i < n; i++) {
    cin >> a;
    i%2 == 0 ? ls.push_back(a) : ls.push_front(a);
  }
  ls.sort();
  for (auto itr = ls.begin(); itr != ls.end(); itr++)
    cout << *itr << " ";
  cout << endl;
}

// Inbuilt functions
// front() - Returns the first element in the list
// back() - Returns the last element in the list
// push_front(a) - Adds the element 'a' at the beginning of the list
// push_back(a) - Adds the element 'a' at the ending of the list
// pop_front() - Removes the first element of the list
// pop_back() - Removes the last element of the list
// begin() - Returns a pointer to the first position of the list
// end() - Returns a pointer to the last position of the list
// empty() - Checkes if the list is empty or not
// insert(itr, a) - Adds element 'a' before the 'itr' position
// erase(itr) - Removes the element at the position 'itr'
// remove() - Removes all the elements in the list
// reverse() - Reverses the list elements
// size() - Returns the size of the list
// sort() - Sorts the list
// assign(itr, a) - Replaces the value 'a' with the existing value at the position 'itr'
