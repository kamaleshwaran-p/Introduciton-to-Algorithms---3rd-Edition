// Time Complexity:
// Find Min - O(1)
// Delete Min - O(log n)
// Insert - O(1)
// Decrease Key - O(1)
// Merge - O(1)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int key;
  node *parent, *child;
  node *left, *right;
  int degree;
  bool mark;
  char c;
};

node *Min = NULL;
int no_of_nodes = 0;

void Insert(int key) {
  node *temp = new node();
  temp->key = key;
  temp->left = temp->right = temp;
  temp->parent = temp->child = NULL;
  temp->mark = false;
  temp->c = 'N';
  temp->degree = 0;
  if (Min != NULL) {
    Min->left->right = temp;
    temp->right = Min;
    temp->left = Min->left;
    Min->left = temp;
    if (temp->key < Min->key)
      Min = temp;
  } else {
    Min = temp;
  }
  no_of_nodes++;
}

void Fibonacci_link(node *y, node *x) {
  y->left->right = y->right;
  y->right->left = y->left;
  if (x->right == x)
    Min = x;
  y->left = y;
  y->right = y;
  y->parent = x;
  if (x->child == NULL)
    x->child = y;
  y->right = x->child;
  y->left = x->child->left;
  x->child->left->right = y;
  x->child->left = y;
  if (y->key < x->child->key)
    x->child = y;
  x->degree++;
}

void Consolidate() {
  int temp1;
//  int temp2 = log2(no_of_nodes);
  float temp2 = (log(no_of_nodes)) / (log(2));
  int temp3 = temp2;
  node *arr[temp3];
  for (int i = 0; i <= temp3; i++)
    arr[i] = NULL;
  node *ptr1 = Min;
  node *ptr2, *ptr3;
  node *ptr4 = ptr1;
  do {
    ptr4 = ptr4->right;
    temp1 = ptr1->degree;
    while (arr[temp1] != NULL) {
      ptr2 = arr[temp1];
      if (ptr1->key > ptr2->key) {
        ptr3 = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
      }
      if (ptr2 == Min)
        Min = ptr1;
      Fibonacci_link(ptr2, ptr1);
      if (ptr1->right == ptr1)
        Min = ptr1;
      arr[temp1] = NULL;
      temp1++;
    }
    arr[temp1] = ptr1;
    ptr1 = ptr1->right;
  } while (ptr1 != Min);
  Min = NULL;
  for (int j = 0; j <= temp3; j++) {
    if (arr[j] != NULL) {
      arr[j]->left = arr[j];
      arr[j]->right = arr[j];
      if (Min != NULL) {
        Min->left->right = arr[j];
        arr[j]->right = Min;
        arr[j]->left = Min->left;
        Min->left = arr[j];
        if (arr[j]->key < Min->key)
          Min = arr[j];
      } else {
        Min = arr[j];
      }
      if (Min == NULL)
        Min = arr[j];
      else if (arr[j]->key < Min->key)
        Min = arr[j];
    }
  }
}

void Extract_Min() {
  if (Min == NULL)
    return;
  else {
    node *temp = Min;
    node *pntr;
    pntr = temp;
    node *x = NULL;
    if (temp->child != NULL) {
      x = temp->child;
      do {
        pntr = x->right;
        Min->left->right = x;
        x->right = Min;
        x->left = Min->left;
        Min->left = x;
        if (x->key < Min->key)
          Min = x;
        x->parent = NULL;
        x = pntr;
      } while (pntr != temp->child);
    }
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    Min = temp->right;
    if (temp == temp->right && temp->child == NULL)
      Min = NULL;
    else {
      Min = temp->right;
      Consolidate();
    }
    no_of_nodes--;
  }
}

void Cut(node *found, node *temp) {
  if (found == found->right)
    temp->child = NULL;
  found->left->right = found->right;
  found->right->left = found->left;
  if (found == temp->child)
    temp->child = found->right;
  temp->degree = temp->degree - 1;
  found->right = found;
  found->left = found;
  Min->left->right = found;
  found->right = Min;
  found->left = Min->left;
  Min->left = found;
  found->parent = NULL;
  found->mark = true;
}

void Cascase_cut(node *temp) {
  node *ptr = temp->parent;
  if (ptr != NULL) {
    if (!temp->mark)
      temp->mark = true;
    else {
      Cut(temp, ptr);
      Cascase_cut(ptr);
    }
  }
}

void Decrease_key(node *found, int key) {
  if (Min == NULL)
    return;
  if (found == NULL)
    return;
  found->key = key;
  node *temp = found->parent;
  if (temp != NULL && found->key < temp->key) {
    Cut(found, temp);
    Cascase_cut(temp);
  }
  if (found->key < Min->key)
    Min = found;
}

void Find(node *Min, int old_key, int key) {
  node *found = NULL;
  node *temp = Min;
  temp->c = 'Y';
  node *found_ptr = NULL;
  if (temp->key == old_key) {
    found_ptr = temp;
    temp->c = 'N';
    found = found_ptr;
    Decrease_key(found, key);
  }
  if (found_ptr == NULL) {
    if (temp->child != NULL)
      Find(temp->child, old_key, key);
    if (temp->right->c != 'Y')
      Find(temp->right, old_key, key);
  }
  temp->c = 'N';
  found = found_ptr;
}

void Delete(int key) {
  if (Min == NULL)
    return;
  Find(Min, key, 0);
  Extract_Min();
}

void display() {
  node *ptr = Min;
  if (ptr == NULL)
    return;
  do {
    cout << ptr->key;
    ptr = ptr->right;
    if (ptr != Min)
      cout << "-->";
  } while (ptr != Min && ptr->right != NULL);
  cout << endl;
}

int main(void) {
  Insert(5);
  Insert(2);
  Insert(8);

  display();

  Extract_Min();
  display();
  cout << "Heap has " << no_of_nodes << " nodes.\n";

  Find(Min, 8, 7);
  display();
  cout << "Heap has " << no_of_nodes << " nodes.\n";

  Delete(7);
  display();
  cout << "Heap has " << no_of_nodes << " nodes.\n";
}
