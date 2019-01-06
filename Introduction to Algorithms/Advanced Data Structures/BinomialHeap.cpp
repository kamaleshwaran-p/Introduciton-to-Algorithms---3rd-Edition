#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int key, degree;
  node *parent, *child, *sibling;
};

node *newNode(int key) {
  node *temp = new node;
  temp->key = key;
  temp->degree = 0;
  temp->parent = temp->child = temp->sibling = NULL;
  return temp;
}

node *mergeBinomialTree(node *x, node *y) {
  if (x->key > y->key)
    swap(x, y);
  y->parent = x;
  y->sibling = x->child;
  x->child = y;
  x->degree++;
  return x;
}

list<node *> unionBinomialHeap(list<node *> l1, list<node *> l2) {
  list<node *> _new;
  list<node *>::iterator it = l1.begin();
  list<node *>::iterator ot = l2.begin();
  while (it != l1.end() && ot != l2.end()) {
    if ((*it)->degree <= (*ot)->degree) {
      _new.push_back(*it);
      it++;
    } else {
      _new.push_back(*ot);
      ot++;
    }
  }
  while (it != l1.end()) {
    _new.push_back(*it);
    it++;
  }
  while (ot != l2.end()) {
    _new.push_back(*ot);
    ot++;
  }
  return _new;
}

list<node *> adjust(list<node *> _heap) {
  if (_heap.size() <= 1)
    return _heap;
  list<node *> new_heap;
  list<node *>::iterator it1, it2, it3;
  it1 = it2 = it3 = _heap.begin();
  if (_heap.size() == 2) {
    it2 = it1;
    it2++;
    it3 = _heap.end();
  } else {
    it2++;
    it3 = it2;
    it3++;
  }
  while (it1 != _heap.end()) {
    if (it2 == _heap.end())
      it1++;
    else if ((*it1)->degree < (*it2)->degree) {
      it1++;
      it2++;
      if (it3 != _heap.end())
        it3++;
    } else if ((it3 != _heap.end()) && ((*it1)->degree == (*it2)->degree) && ((*it1)->degree == (*it3)->degree)) {
      it1++;
      it2++;
      it3++;
    } else if ((*it1)->degree == (*it2)->degree) {
      node *temp;
      *it1 = mergeBinomialTree(*it1, *it2);
      it2 = _heap.erase(it2);
      if (it3 != _heap.end())
        it3++;
    }
  }
  return _heap;
}

list<node *> insertTreeInHeap(list<node *> _heap, node *tree) {
  list<node *> temp;
  temp.push_back(tree);
  temp = unionBinomialHeap(_heap, temp);
  return adjust(temp);
}

list<node *> removeMinFromTree(node *tree) {
  list<node *> heap;
  node *temp = tree->child;
  node *lo;
  while (temp) {
    lo = temp;
    temp = temp->sibling;
    lo->sibling = NULL;
    heap.push_front(lo);
  }
  return heap;
}

list<node *> Insert(list<node *> _head, int key) {
  node *temp = newNode(key);
  return insertTreeInHeap(_head, temp);
}

node *getMin(list<node *> _heap) {
  list<node *>::iterator it = _heap.begin();
  node *temp = *it;
  while (it != _heap.end()) {
    if ((*it)->key < temp->key)
      temp = *it;
    it++;
  }
  return temp;
}

list<node *> extractMin(list<node *> _heap) {
  list<node *> new_heap, lo;
  node *temp = getMin(_heap);
  list<node *>::iterator it = _heap.begin();
  while (it != _heap.end()) {
    if (*it != temp)
      new_heap.push_back(*it);
    it++;
  }
  lo = removeMinFromTree(temp);
  new_heap = unionBinomialHeap(new_heap, lo);
  new_heap = adjust(new_heap);
  return new_heap;
}

void print_tree(node *h) {
  while (h) {
    cout << h->key << " ";
    print_tree(h->child);
    h = h->sibling;
  }
}

void print_heap(list<node *> heap) {
  list<node *>::iterator it = heap.begin();
  while (it != heap.end()) {
    print_tree(*it);
    it++;
  }
}

int main(void) {
  list<node *> heap;
  heap = Insert(heap, 10);
  heap = Insert(heap, 20);
  heap = Insert(heap, 30);
  heap = Insert(heap, 40);
  heap = Insert(heap, 50);

  print_heap(heap);
  cout << endl;

  node *temp = getMin(heap);
  cout << temp->key << endl;

  heap = extractMin(heap);
  print_heap(heap);
  cout << endl;
}
