#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int key;
  node *left, *right;
};

node *new_node(int key) {
  node *temp = new node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

node *Tree_Min(node *root) {
  while (root->left != NULL)
    root = root->left;
  return root;
}
node *Tree_Max(node *root) {
  while (root->right != NULL)
    root = root->right;
  return root;
}

node *Search(node *root, int key) {
  if (root == NULL || root->key == key)
    return root;
  if (root->key > key)
    return Search(root->left, key);
  return Search(root->right, key);
}

node *Insert(node *root, int key) {
  if (root == NULL)
    return new_node(key);
  else if (root->key > key)
    root->left = Insert(root->left, key);
  else
    root->right = Insert(root->right, key);
  return root;
}

node *Delete(node *root, int key) {
  if (root == NULL)
    return root;
  else if (root->key > key)
    root->left = Delete(root->left, key);
  else if (root->key < key)
    root->right = Delete(root->right, key);
  else {
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }
    node *temp = Tree_Min(root->right);
    root->key = temp->key;
    root->right = Delete(root->right, temp->key);
  }
}

void inOrder(node *root) {
  if (root != NULL) {
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
  }
}

int main(void) {
  node *root = NULL;
  root = Insert(root, 50);
  Insert(root, 30);
  Insert(root, 20);
  Insert(root, 40);
  Insert(root, 70);
  Insert(root, 60);
  Insert(root, 80);

  inOrder(root);
  cout << endl;

  Delete(root, 30);
  Delete(root, 50);
  Delete(root, 70);
  Delete(root, 80);
  Delete(root, 40);
  inOrder(root);
  cout << endl;

  Insert(root, 32);
  Insert(root, 33);
  inOrder(root);
  cout << endl;
}










/*#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  int key;
  node *parent;
  node *left, *right;
};

node* newNode(int key) {
  node *temp = new node();
  temp->key = key;
  temp->parent = temp->left = temp->right = NULL;
  return temp;
}

node* Search(node* root, int key) {
  if(root == NULL || key == root->key)
    return root;
  if(root->key < key)
    return Search(root->right, key);
  return Search(root->left, key);
}

node* Tree_Max(node *root) {
  while (root->right != NULL)
    root = root->right;
  return root;
}

node* Tree_Min(node* root) {
  while (root->left != NULL)
    root = root->left;
  return root;
}

void Insert(node* root, int key) {
  node* y = NULL;
  node* x = root;
  node* z = newNode(key);
  while (x != NULL) {
    y = x;
    if (x->key < z->key)
      x = x->right;
    else
      x = x->left;
  }
  z->parent = y;
  if (y == NULL)
    root = z;
  else if (y->key < z->key)
    y->right = z;
  else
    y->left = z;
}

void Transplant(node* root, node*u, node* v) {
  if (u->parent == NULL)
    root = v;
  else if (u->parent->left == u)
    u->parent->left = v;
  else
    u->parent->right = v;
  if (v != NULL)
    v->parent = u->parent;
}

void Delete(node* root, int key) {
  node* z = Search(root, key);
  if (z->left == NULL)
    Transplant(root, z, z->right);
  else if (z->right == NULL)
    Transplant(root, z, z->left);
  else {
    node* y = Tree_Min(z->right);
    if (y->parent != z) {
      Transplant(root, y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    Transplant(root, z, y);
    y->left = z->left;
    y->left->parent = y;
  }
}

node* Successor(node *root, int key) {
  node* x= Search(root, key);
  if (x->right != NULL)
    return Tree_Min(x->right);
  node* y = x->parent;
  while (y != NULL && y->right == x) {
    x = y;
    y = y->parent;
  }
  return y;
}

node* Predecessor(node* root, int key) {
  node* x = Search(root, key);
  if (x->left != NULL)
    return Tree_Max(x->left);
  node* y = x->parent;
  while (y != NULL && y->left == x) {
    x = y;
    y = y->parent;
  }
  return y;
}

void inOrder(node* root) {
  if(root != NULL) {
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
  }
}

void preOrder(node* root) {
  if(root != NULL) {
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(node* root) {
  if(root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
  }
}

int main(void) {
  node *root = NULL, *temp;
  root = newNode(50);
  Insert(root, 30);
  Insert(root, 20);
  Insert(root, 40);
  Insert(root, 70);
  Insert(root, 60);
  Insert(root, 80);

  temp = Predecessor(root, 30);
  cout << temp->key << endl;
  temp = Successor(root, 70);
  cout << temp->key << endl;

  inOrder(root);
  cout << endl;

  Delete(root, 30);
  inOrder(root);
  cout << endl;
}*/
