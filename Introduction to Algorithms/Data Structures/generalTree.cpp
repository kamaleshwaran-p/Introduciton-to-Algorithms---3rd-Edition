#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int key;
  vector<node *> child;

  node(int key) {
    this->key = key;
  }
};

node *root = NULL;
vector<node *> v;

node *Search(int key) {
  for (int i = 0; i < v.size(); i++)
    if (v[i]->key == key)
      return v[i];
}

void Insert(int parent, int key) {
  node *temp = new node(key);
  node *p = Search(parent);
  (p->child).push_back(temp);
  v.push_back(temp);
}

void levelOrder() {
  if (root != NULL) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      while (n--) {
        node *temp = q.front();
        cout << temp->key << " ";
        q.pop();
        for (int i = 0; i < temp->child.size(); i++)
          q.push(temp->child[i]);
      }
      cout << endl;
    }
  }
}

int main(void) {
  root = new node(32);
  v.push_back(root);
  int n;
  cin >> n;
  pair<int, int> arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i].first >> arr[i].second;
  for (int i = 0; i < n; i++)
    Insert(arr[i].first, arr[i].second);
  levelOrder();
}
