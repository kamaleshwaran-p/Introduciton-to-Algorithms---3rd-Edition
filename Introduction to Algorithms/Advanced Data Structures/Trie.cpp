#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
public:
  node *child[26];
  bool isEnd;
};

node *getNode(void) {
  node *temp = new node;
  for (int i = 0; i < 26; i++)
    temp->child[i] = NULL;
  temp->isEnd = false;
  return temp;
}

void insert(node *root, string str) {
  node *temp = root;
  for (int i = 0; i < str.length(); i++) {
    int index = str[i] - 'a';
    if(!temp->child[index])
      temp->child[index] = getNode();
    temp = temp->child[index];
  }
  temp->isEnd = true;
}

bool leafNode(node *root) {
  return (root->isEnd);
}

bool isItFreeNode(node *root) {
  for (int i = 0; i < 26; i++)
    if (root->child[i])
      return false;
  return true;
}

bool DeleteHelper(node *root, string key, int level, int len) {
  if (root) {
    if (level == len) {
      if (root->isEnd) {
        root->isEnd = false;
        return isItFreeNode(root);
      }
    } else {
      int index = key[level] - 'a';
      if (DeleteHelper(root->child[index], key, level+1, len)) {
        free(root->child[index]);
        root->child[index] = NULL;
        return (!leafNode(root) && isItFreeNode(root));
      }
    }
  }
  return false;
}

bool Delete(node *root, string key) {
  int len = key.length();
  if (len > 0)
    DeleteHelper(root, key, 0, len);
}

bool search(node *root, string str) {
  node *temp = root;
  for (int i = 0; i < str.length(); i++) {
    int index = str[i] - 'a';
    if (!temp->child[index])
      return false;
    temp = temp->child[index];
  }
  return (temp != NULL && temp->isEnd);
}

void display(node *root, char key[], int level) {
  if (leafNode(root)) {
    key[level] = '\0';
    cout << key << endl;
  }
  for (int i = 0; i < 26; i++) {
    if (root->child[i]) {
      key[level] = i + 'a';
      display(root->child[i], key, level+1);
    }
  }
}

int main(void) {
  string key[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  int n = sizeof(key) / sizeof(key[0]);
  char str[20];
  node *root = getNode();

  for (int i = 0; i < n; i++)
    insert(root, key[i]);
  display(root, str, 0);
  cout << endl;
  search(root, "the") ? cout << "Yes\n" : cout << "No\n";
  search(root, "yes") ? cout << "Yes\n" : cout << "No\n";
  cout << endl;

  Delete(root, key[0]);
  Delete(root, key[1]);
  search(root, "the") ? cout << "Yes\n" : cout << "No\n";
  search(root, "there") ? cout << "Yes\n" : cout << "No\n";
  cout << endl;
  display(root, str, 0);
}
