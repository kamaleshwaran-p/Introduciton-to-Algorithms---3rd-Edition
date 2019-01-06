#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int key, priority;
  node *left, *right;

  node(int key, int priority) {
    this->key = key;
    this->priority = priority;
    left = right = NULL;
  }
};

node *Left_Rotate(node *x) {
  node *y = x->right;
  node *temp = y->left;
  y->left = x;
  x->right = temp;
  return y;
}

node *Right_Rotate(node *x) {
  node *y = x->left;
  node *temp = y->right;
  y->right = x;
  x->left = temp;
  return y;
}

node *Insert(node *root, int key, int priority) {
  if (root == NULL)
    return new node(key, priority);
  if (key < root->key) {
    root->left = Insert(root->left, key, priority);
    if (root->left->priority > root->priority)
      root = Right_Rotate(root);
  } else {
    root->right = Insert(root->right, key, priority);
    if (root->right->priority > root->priority)
      root = Left_Rotate(root);
  }
  return root;
}

node *Delete(node *root, int key) {
  if (root == NULL)
    return root;
  if (root->key > key)
    root->left = Delete(root->left, key);
  else if (root->key < key)
    root->right = Delete(root->right, key);
  else {
    if (root->left == NULL) {
      node *temp = root->right;
      delete root;
      root = temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      delete root;
      root = temp;
    } else if (root->left->priority < root->right->priority) {
      root = Left_Rotate(root);
      root->left = Delete(root->left, key);
    } else {
      root = Right_Rotate(root);
      root->right = Delete(root->right, key);
    }
  }
  return root;
}

node *Search(node *root, int key) {
  if (root == NULL || root->key == key)
    return root;
  if (root->key > key)
    return Search(root->left, key);
  return Search(root->right, key);
}

void inOrder(node *root) {
  if (root != NULL) {
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
  }
}

void levelOrder(node *root) {
  if (root != NULL) {
    queue<node *>q;
    q.push(root);
    while (!q.empty()) {
      node *temp = q.front();
      cout << temp->key << "->" << temp->priority << " ";
      q.pop();
      if (temp->left != NULL)
        q.push(temp->left);
      if (temp->right != NULL)
        q.push(temp->right);
    }
  }
}

int main(void) {
  node *root = NULL;
  root = Insert(root, 50, rand()%100);
  root = Insert(root, 30, rand()%100);
  root = Insert(root, 20, rand()%100);
  root = Insert(root, 40, rand()%100);
  root = Insert(root, 70, rand()%100);
  root = Insert(root, 60, rand()%100);
  root = Insert(root, 80, rand()%100);

  inOrder(root);
  cout << endl;

  levelOrder(root);
  cout << endl;
  root = Delete(root, 70);
  root = Delete(root, 20);
  root = Delete(root, 30);

  inOrder(root);
  cout << endl;

  levelOrder(root);
  cout << endl;
}
