#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int key;
  node *left, *right;
  int height;

  node(int key) {
    this->key = key;
    this->height = 1;
    left = right = NULL;
  }
};

int Height(node *root) {
  if (root == NULL)
    return 0;
  return root->height;
}

int Balance(node *root) {
  if (root == NULL)
    return 0;
  return (Height(root->left) - Height(root->right));
}

node *Tree_Min(node *root) {
  while (root->left != NULL)
    root = root->left;
  return root;
}

node *Left_Rotate(node *x) {
  node *y = x->right;
  node *temp = y->left;
  y->left = x;
  x->right = temp;
  x->height = max(Height(x->left), Height(x->right)) + 1;
  y->height = max(Height(y->left), Height(y->right)) + 1;
  return y;
}

node *Right_Rotate(node *x) {
  node *y = x->left;
  node *temp = y->right;
  y->right = x;
  x->left = temp;
  x->height = max(Height(x->left), Height(x->right)) + 1;
  y->height = max(Height(y->left), Height(y->right)) + 1;
  return y;
}

node *Insert(node *root, int key) {
  if (root == NULL)
    return new node(key);
  if (root->key > key)
    root->left = Insert(root->left, key);
  else if (root->key < key)
    root->right = Insert(root->right, key);
  else
    return root;
  root->height = max(Height(root->left), Height(root->right)) + 1;
  int balance = Balance(root);
  if (balance > 1 && key < root->left->key) {
    return Right_Rotate(root);
  }
  if (balance < -1 && key > root->right->key) {
    return Left_Rotate(root);
  }
  if (balance > 1 && key > root->left->key) {
    root->left = Left_Rotate(root->left);
    return Right_Rotate(root);
  }
  if (balance < -1 && key < root->right->key) {
    root->right = Right_Rotate(root->right);
    return Left_Rotate(root);
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
    if (root->left == NULL || root->right == NULL) {
      node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }
      delete temp;
    } else {
      node *temp = Tree_Min(root->right);
      root->key = temp->key;
      root->right = Delete(root->right, temp->key);
    }
  }
  if (root == NULL)
    return root;
  root->height = max(Height(root->left), Height(root->right)) + 1;
  int balance = Balance(root);
  if (balance > 1 && Balance(root->left) >= 0) {
    return Right_Rotate(root);
  }
  if (balance > 1 && Balance(root->left) < 0) {
    root->left = Left_Rotate(root->left);
    return Right_Rotate(root);
  }
  if (balance < -1 && Balance(root->right) <= 0) {
    return Left_Rotate(root);
  }
  if (balance < -1 && Balance(root->right) > 0) {
    root->right = Right_Rotate(root->right);
    return Left_Rotate(root);
  }
  return root;
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
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
      node *temp = q.front();
      cout << temp->key << " ";
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
  root = Insert(root, 10);
  root = Insert(root, 20);
  root = Insert(root, 30);
  root = Insert(root, 40);
  root = Insert(root, 50);
  root = Insert(root, 25);

  inOrder(root);
  cout << endl;

  levelOrder(root);
  cout << endl;

  root = Delete(root, 10);
  root = Delete(root, 40);
  root = Delete(root, 25);

  inOrder(root);
  cout << endl;

  levelOrder(root);
  cout << endl;
}
