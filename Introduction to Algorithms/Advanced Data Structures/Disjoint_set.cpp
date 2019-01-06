#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int data, rank;
  node *parent;
};

map<int, node> Map;

void makeSet(int data) {
  node *temp = new node;
  temp->data = data;
  temp->parent = temp;
  temp->rank = 0;
  Map[data] = *temp;
}

node *findSet(node *temp) {
  node *parent = temp->parent;
  if (parent == temp)
    return parent;
  temp->parent = findSet(temp->parent);
  return temp->parent;
}

bool Union(int data1, int data2) {
  node *temp1 = &Map[data1];
  node *temp2 = &Map[data2];
  node *parent1 = findSet(temp1);
  node *parent2 = findSet(temp2);
  if (parent1->data == parent2->data)
    return false;
  if (parent1->rank >= parent2->rank) {
    parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank+1 : parent1->rank;
    parent2->parent = parent1;
  } else {
    parent1->parent = parent2;
  }
  return true;
}


int FindSetData(int data) {
  return findSet(&Map[data])->data;
}

int main(void) {
  makeSet(1);
  makeSet(2);
  makeSet(3);
  makeSet(4);
  makeSet(5);
  makeSet(6);
  makeSet(7);

  Union(1, 2);
  Union(2, 3);
  Union(4, 5);
  Union(6, 7);
  Union(5, 6);
  Union(3, 7);

  cout << FindSetData(1) << endl;
  cout << FindSetData(2) << endl;
  cout << FindSetData(3) << endl;
  cout << FindSetData(4) << endl;
  cout << FindSetData(5) << endl;
  cout << FindSetData(6) << endl;
  cout << FindSetData(7) << endl;
}
