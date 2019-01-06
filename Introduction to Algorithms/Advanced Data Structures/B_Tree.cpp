#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int *keys;
  int t;
  node **C;
  int n;
  bool leaf;

  node(int _t, bool _leaf);
  void insertNonFull(int k);
  void splitChild(int i, node *y);
  void traverse();
  node *search(int k);
  int findKey(int k);
  void Remove(int k);
  void RemoveFromLeaf(int idx);
  void RemoveFromNonLeaf(int idx);
  int getPred(int idx);
  int getSucc(int idx);
  void fill(int idx);
  void borrowFromPrev(int idx);
  void borrowFromNext(int idx);
  void merge(int idx);
  friend class BTree;
};

class BTree {
public:
  node *root;
  int t;

  BTree(int _t) {
    root = NULL;
    t = _t;
  }
  void traverse() {
    if (root != NULL)
      root->traverse();
  }
  node *search(int k) {
    return (root == NULL) ? NULL : root->search(k);
  }
  void insert(int k);
  void Remove(int k);
};

node::node(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;
  keys = new int[2*t-1];
  C = new node*[2*t];
  n = 0;
}

void node::traverse() {
  int i;
  for (i = 0; i < n; i++) {
    if (!leaf)
      C[i]->traverse();
    cout << keys[i] << " ";
  }
  if (!leaf)
    C[i]->traverse();
}

node *node::search(int k) {
  int i = 0;
  while (i < n && k > keys[i])
    i++;
  if (keys[i] == k)
    return this;
  if (leaf)
    return NULL;
  return C[i]->search(k);
}

int node::findKey(int k) {
  int idx = 0;
  while (idx < n && keys[idx] < k)
    idx++;
  return idx;
}

void node::Remove(int k) {
  int idx = findKey(k);
  if (idx < n && keys[idx] == k) {
    if (leaf)
      RemoveFromLeaf(idx);
    else
      RemoveFromNonLeaf(idx);
  } else {
    if (leaf)
      return;
    bool flag = ((idx == n) ? true : false);
    if (C[idx]->n < t)
      fill(idx);
    if (flag && idx > n)
      C[idx-1]->Remove(k);
    else
      C[idx]->Remove(k);
  }
  return;
}

void node::RemoveFromLeaf(int idx) {
  for (int i = idx+1; i < n; i++)
    keys[i-1] = keys[i];
  n--;
  return;
}

void node::RemoveFromNonLeaf(int idx) {
  int k = keys[idx];
  if (C[idx]->n >= t) {
    int pred = getPred(idx);
    keys[idx] = pred;
    C[idx]->Remove(pred);
  } else if (C[idx+1]->n >= t) {
    int succ = getSucc(idx);
    keys[idx] = succ;
    C[idx+1]->Remove(succ);
  } else {
    merge(idx);
    C[idx]->Remove(k);
  }
  return;
}

int node::getPred(int idx) {
  node *cur = C[idx];
  while (!cur->leaf)
    cur = cur->C[cur->n];
  return cur->keys[(cur->n)-1];
}

int node::getSucc(int idx) {
  node *cur = C[idx+1];
  while (!cur->leaf)
    cur = cur->C[0];
  return cur->keys[0];
}

void node::fill(int idx) {
  if (idx != 0 && C[idx-1]->n >= t)
    borrowFromPrev(idx);
  else if (idx != n && C[idx+1]->n >= t)
    borrowFromNext(idx);
  else {
    if (idx != n)
      merge(idx);
    else
      merge(idx-1);
  }
}

void node::borrowFromPrev(int idx) {
  node *child = C[idx];
  node *sibling = C[idx-1];
  for (int i = child->n-1; i >= 0; i--)
    child->keys[i+1] = child->keys[i];
  if (!child->leaf) {
    for (int i = child->n; i >= 0; i--)
      child->C[i+1] = child->C[i];
  }
  child->keys[0] = keys[idx-1];
  if (!child->leaf)
    child->C[0] = sibling->C[sibling->n];
  keys[idx-1] = sibling->keys[sibling->n - 1];
  child->n += 1;
  sibling->n -= 1;
  return;
}

void node::borrowFromNext(int idx) {
  node *child = C[idx];
  node *sibling = C[idx+1];
  child->keys[(child->n)] = keys[idx];
  if (!child->leaf)
    child->C[(child->n)+1] = sibling->C[0];
  keys[idx] = sibling->keys[0];
  for (int i = 1; i < sibling->n; i++)
    sibling->keys[i-1] = sibling->keys[i];
  if (!sibling->leaf) {
    for (int i = 1; i <= sibling->n; i++)
      sibling->C[i-1] = sibling->C[i];
  }
  child->n += 1;
  sibling->n -= 1;
  return;
}

void node::merge(int idx) {
  node *child = C[idx];
  node *sibling = C[idx+1];
  child->keys[t-1] = keys[idx];
  for (int i = 0; i < sibling->n; i++)
    child->keys[i+t] = sibling->keys[i];
  if (!child->leaf) {
    for (int i = 0; i <= sibling->n; i++)
      child->C[i+t] = sibling->C[i];
  }
  for (int i = idx+1; i < n; i++)
    keys[i-1] = keys[i];
  for (int i = idx+2; i <= n; i++)
    C[i-1] = C[i];
  child->n += sibling->n + 1;
  n--;
  delete(sibling);
  return;
}

void BTree::insert(int k) {
  if (root == NULL) {
    root = new node(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2*t-1) {
      node *s = new node(t, false);
      s->C[0] = root;
      s->splitChild(0, root);
      int i = 0;
      if (s->keys[0] < k)
        i++;
      s->C[i]->insertNonFull(k);
      root = s;
    } else {
      root->insertNonFull(k);
    }
  }
}

void node::insertNonFull(int k) {
  int i = n - 1;
  if (leaf) {
    while (i >= 0 && keys[i] > k) {
      keys[i+1] = keys[i];
      i--;
    }
    keys[i+1] = k;
    n = n + 1;
  } else {
    while (i >= 0 && keys[i] > k)
      i--;
    if (C[i+1]->n == 2*t-1) {
      splitChild(i+1, C[i+1]);
      if (keys[i+1] < k)
        i++;
    }
    C[i+1]->insertNonFull(k);
  }
}

void node::splitChild(int i, node *y) {
  node *z = new node(y->t, y->leaf);
  z->n = t - 1;
  for (int j = 0; j < t-1; j++)
    z->keys[j] = y->keys[j+t];
  if (!y->leaf) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j+t];
  }
  y->n = t - 1;
  for (int j = n; j >= i+1; j--)
    C[j+1] = C[j];
  C[i+1] = z;
  for (int j = n-1; j >= i; j--)
    keys[j+1] = keys[j];
  keys[i] = y->keys[t-1];
  n = n + 1;
}

void BTree::Remove(int k) {
  if (!root)
    return;
  root->Remove(k);
  if (root->n == 0) {
    node *temp = root;
    if (root->leaf)
      root = NULL;
    else
      root = root->C[0];
    delete temp;
  }
  return;
}

int main(void) {
  BTree t(3);
  t.insert(1);
  t.insert(3);
  t.insert(7);
  t.insert(10);
  t.insert(11);
  t.insert(13);
  t.insert(14);
  t.insert(15);
  t.insert(18);
  t.insert(16);
  t.insert(19);
  t.insert(24);
  t.insert(25);
  t.insert(25);
  t.insert(26);
  t.insert(21);
  t.insert(4);
  t.insert(5);
  t.insert(20);
  t.insert(22);
  t.insert(2);
  t.insert(17);
  t.insert(12);
  t.insert(6);

  t.traverse();
  cout << endl;

  t.Remove(6);
  t.traverse();
  cout << endl;

  t.Remove(13);
  t.traverse();
  cout << endl;

  t.Remove(7);
  t.traverse();
  cout << endl;

  t.Remove(4);
  t.traverse();
  cout << endl;

  t.Remove(2);
  t.traverse();
  cout << endl;

  t.Remove(16);
  t.traverse();
  cout << endl;
}
