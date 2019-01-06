#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

enum Color {RED, BLACK};

class node {
public:
  int key;
  bool color;
  node *parent, *left, *right;

  node (int key) {
    this->key = key;
    left = right = parent = NULL;
  }
};

class RBT {
private:
  node *root;
protected:
  void Left_Rotate(node *&, node *&);
  void Right_Rotate(node *&, node *&);
  void Fixup(node *&, node *&);
  void fixDoubleBlack(node *&, node *&);
public:
  RBT() {
    root = NULL;
  }
  void Insert(const int &n);
  void Delete(const int &n);
  void Delete_Node(node *&, node *&);
  void inOrder();
  void levelOrder();
};

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

void inOrderHelper(node *root) {
  if (root != NULL) {
    inOrderHelper(root->left);
    cout << root->key << " ";
    inOrderHelper(root->right);
  }
}

void levelOrderHelper(node *root) {
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

void RBT::Left_Rotate(node *&root, node *&x) {
  node *y = x->right;
  x->right = y->left;
  if (x->right != NULL) {
    x->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {
    root = y;
  } else if (x->parent->left == x) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void RBT::Right_Rotate(node *&root, node *&x) {
  node *y = x->left;
  x->left = y->right;
  if (x->left != NULL) {
    x->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {
    root = y;
  } else if (x->parent->left == x) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->right = x;
  x->parent = y;
}

node *insert(node *root, node *pt) {
  if (root == NULL)
    return pt;
  if (root->key > pt->key) {
    root->left = insert(root->left,  pt);
    root->left->parent = root;
  } else if (root->key < pt->key) {
    root->right = insert(root->right, pt);
    root->right->parent = root;
  }
  return root;
}

void RBT::Fixup(node *&root, node *&pt) {
  node *parent_pt = NULL;
  node *grand_parent_pt = NULL;
  while (pt != root && pt->color == RED && pt->parent->color == RED) {
    parent_pt = pt->parent;
    grand_parent_pt = parent_pt->parent;
    if (parent_pt == grand_parent_pt->left) {
      node *uncle_pt = grand_parent_pt->right;
      if (uncle_pt != NULL && uncle_pt->color == RED) {
        grand_parent_pt->color = RED;
        parent_pt->color = uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      } else {
        if (pt == parent_pt->right) {
          Left_Rotate(root, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        Right_Rotate(root, grand_parent_pt);
        swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    } else {
      node *uncle_pt = grand_parent_pt->left;
      if (uncle_pt != NULL && uncle_pt->color == RED) {
        grand_parent_pt->color = RED;
        parent_pt->color = uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      } else {
        if (pt == parent_pt->left) {
          Right_Rotate(root, parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        Left_Rotate(root, grand_parent_pt);
        swap(parent_pt->color, grand_parent_pt->color);
        pt = parent_pt;
      }
    }
  }
  root->color = BLACK;
}

void RBT::Insert(const int &key) {
  node *temp = new node(key);
  root = insert(root, temp);
  Fixup(root, temp);
}

node *replace(node *x) {
  if (x->left != NULL && x->right != NULL)
    return Tree_Min(x->right);
  if (x->left == NULL && x->right == NULL)
    return NULL;
  if (x->left != NULL)
    return x->left;
  return x->right;
}

node *sibling(node *x) {
  if (x->parent == NULL)
    return NULL;
  if (x->parent->left == x)
    return x->parent->right;
  return x->parent->left;
}

bool hasRedChild(node *root) {
  return ((root->left != NULL && root->left->color == RED) || (root->right != NULL && root->right->color == RED));
}

void RBT::fixDoubleBlack(node *&root, node *&x) {
  if (x == root)
    return;
  node *S = sibling(x);
  node *parent_pt = x->parent;
  if (S == NULL) {
    fixDoubleBlack(root, parent_pt);
  } else {
    if (S->color == RED) {
      parent_pt->color = RED;
      S->color = BLACK;
      if (S == S->parent->left) {
        Right_Rotate(root, parent_pt);
      } else {
        Left_Rotate(root, parent_pt);
      }
      fixDoubleBlack(root, x);
    } else {
      if (hasRedChild(S)) {
        if (S->left != NULL &&  S->left->color == RED) {
          if (S == parent_pt->left) {
            S->left->color = S->color;
            S->color = parent_pt->color;
            Right_Rotate(root, parent_pt);
          } else {
            S->left->color = parent_pt->color;
            Right_Rotate(root, S);
            Left_Rotate(root, parent_pt);
          }
        } else {
          if (S == parent_pt->left) {
            S->right->color = parent_pt->color;
            Left_Rotate(root, S);
            Right_Rotate(root, parent_pt);
          } else {
            S->right->color = S->color;
            S->color = parent_pt->color;
            Left_Rotate(root, parent_pt);
          }
        }
        parent_pt->color = BLACK;
      } else {
        S->color = RED;
        if (parent_pt->color == BLACK)
          fixDoubleBlack(root, parent_pt);
        else
          parent_pt->color = BLACK;
      }
    }
  }
}

void RBT::Delete_Node(node *&root, node *&x) {
  node *y = replace(x);
  bool xyBlack = ((y == NULL || y->color == BLACK) && (x->color == BLACK));
  node *parent_pt = x->parent;
  if (y == NULL) {
    if (x == root) {
      root = NULL;
    } else {
      if (xyBlack) {
        fixDoubleBlack(root, x);
      } else {
        node *S = sibling(x);
        if (S != NULL)
          S->color = RED;
      }
      if (x == parent_pt->left) {
        parent_pt->left = NULL;
      } else {
        parent_pt->right = NULL;
      }
    }
    free(x);
    return;
  }
  if (x->left == NULL || x->right == NULL) {
    if (x == root) {
      x->key = y->key;
      x->left = x->right = NULL;
      delete y;
    } else {
      if (x == parent_pt->left) {
        parent_pt->left = y;
      } else {
        parent_pt->right = y;
      }
      free(x);
      y->parent = parent_pt;
      if (xyBlack) {
        fixDoubleBlack(root, y);
      } else {
        y->color = BLACK;
      }
    }
    return;
  }
  swap(x->key, y->key);
  Delete_Node(root, y);
}

node *Search(node *root, int key) {
  if (root == NULL || root->key == key)
    return root;
  if (root->key > key)
    return Search(root->left, key);
  return Search(root->right, key);
}

void RBT::Delete(const int &n) {
  if (root == NULL)
    return;
  node *temp = Search(root, n);
  if (temp != NULL && temp->key != n)
    return;
  Delete_Node(root, temp);
}

void RBT::inOrder() {
  inOrderHelper(root);
}

void RBT::levelOrder() {
  levelOrderHelper(root);
}

int main(void) {
  RBT tree;
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(18);
  tree.Insert(10);
  tree.Insert(22);
  tree.Insert(8);
  tree.Insert(11);
  tree.Insert(26);
  tree.Insert(2);
  tree.Insert(6);
  tree.Insert(13);

  tree.inOrder();
  cout << endl;

  tree.levelOrder();
  cout << endl;

  tree.Delete(18);
  tree.Delete(11);
  tree.Delete(3);
  tree.Delete(10);
  tree.Delete(22);

  tree.inOrder();
  cout << endl;

  tree.levelOrder();
  cout << endl;
}
