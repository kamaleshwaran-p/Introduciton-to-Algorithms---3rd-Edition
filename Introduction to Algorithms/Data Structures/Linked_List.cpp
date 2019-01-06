#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node {
public:
  int value;
  Node *next;
};

class List {
public:
  Node nil;
};

void init_list(List *list) {
  list->nil.value = 0;
  list->nil.next = &(list->nil);
}

void insert(List *list, int key) {
  Node *node = new Node;
  node->value = key;
  node->next = list->nil.next;
  list->nil.next = node;
}

void destroy(List *list) {
  Node *node = &(list->nil);
  while (node->next != &(list->nil)) {
    Node *temp = node->next;
    node->next = node->next->next;
    free(temp);
  }
}

void del(List *list, int key) {
  Node *node = &(list->nil);
  while (node->next != &(list->nil)) {
    if (node->next->value == key) {
      Node *temp = node->next;
      node->next = node->next->next;
      free(temp);
    } else {
      node = node->next;
    }
  }
}

bool search(List *list, int key) {
  Node *node = &(list->nil);
  list->nil.value = key;
  while (node->next->value != key) {
    node = node->next;
  }
  if (node == &(list->nil))
    return false;
  return true;
}

void print(List *list) {
  Node *node = &(list->nil);
  while (node->next != &(list->nil)) {
    cout << node->next->value << " ";
    node = node->next;
  }
  cout << endl;
}

int main(void) {
  List *list = new List;
  init_list(list);
  for(int i = 1; i <= 5; i++)
    insert(list, i);
  print(list);
  cout << search(list, 3) << endl;
  del(list, 3);
  print(list);
  destroy(list);
  print(list);
}
