#include <bits/stdc++.h>
using namespace std;

int Extract_Min(vector< vector<int> > &v) {
  int min(v[0][0]);
  int i(0), j(0);
  while(i < v.size() && j < v[0].size()) {
    int ori(i), orj(j);
    int right(INT_MAX), down(INT_MAX);
    int cur(v[i][j]);
    if(i < v.size()-1)  down = v[i+1][j];
    if(j < v[0].size()-1)  right = v[i][j+1];
    if(right == INT_MAX && down == INT_MAX) {
      v[i][j] = INT_MAX;
      break;
    }
    down <= right ? i++ : j++;
    swap(v[i][j], v[ori][orj]);
  }
  return min;
}

void Insert(vector< vector<int> > &v, int key) {
  int i(v.size()-1), j(v[0].size()-1);
  v[i][j] = key;
  while(i >= 0 && j >= 0) {
    int up(INT_MIN), left(INT_MIN);
    int ori(i), orj(j);
    if(i > 0)  up = v[i-1][j];
    if(j > 0)  left = v[i][j-1];
    if(key >= up && key >= left)
      break;
    key < up ? i-- : j--;
    swap(v[ori][orj], v[i][j]);
  }
}

bool Exits(vector< vector<int> > &v, int key) {
  int i(v.size()-1), j(0);
  while(i >= 0  && j < v.size()) {
    if(v[i][j] == key)
      return true;
    v[i][j] < key ? j++ : i--;
  }
  return false;
}

void Print(vector< vector<int> > &v) {
  for(int i(0); i < v.size(); i++) {
    for(int j(0); j < v[0].size(); j++)
      cout << v[i][j] << " ";
    cout << endl;
  }
}

int main(void) {
  int Arr1[] = {2, 3, 12, INT_MAX};
  int Arr2[] = {4, 8, 16, INT_MAX};
  int Arr3[] = {5, 9, INT_MAX, INT_MAX};
  int Arr4[] = {14, INT_MAX, INT_MAX, INT_MAX};

  vector<int> v1(Arr1, Arr1+4);
  vector<int> v2(Arr2, Arr2+4);
  vector<int> v3(Arr3, Arr3+4);
  vector<int> v4(Arr4, Arr4+4);

  vector<vector<int>> v;
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);

  for(int i(0); i < 9; i++)
    cout << Extract_Min(v) << " ";
  cout << endl;

  for(int i(0); i < 9; i++)
    Insert(v, i);
  Print(v);

  cout << Exits(v, 8) << endl;
  cout << Exits(v, 32) << endl;
}
