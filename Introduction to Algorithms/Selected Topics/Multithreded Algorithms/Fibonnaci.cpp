#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int Fib(int n) {
  if (n <= 1)
    return n;
  else {
    long long x = Fib(n-1);
    long long y = Fib(n-2);
    return x+y;
  }
}

/*long long Fb[101];
void Fib(int n) {
  if (n <= 1)
    Fb[n] = n;
  else {
    if (Fb[n-1] == -1)
      Fib(n-1);
    if (Fb[n-2] == -1)
      Fib(n-2);
    Fb[n] = Fb[n-1] + Fb[n-2];
  }
}*/

int main(void) {
  int n;
  cin >> n;

  /*if (n <= 0)
    cout << 0 << endl;
  else {
    n--;
    long long a = 0, b = 1;
    while (n--) {
      long long temp = b;
      b = a + b;
      a = temp;
    }
    cout << b << endl;
  }*/

  /*if (n < 0)
    cout << n << endl;
  else {
    for (int i = 0; i <= n; i++)
      Fb[i] = -1;
    Fib(n);
    cout << Fb[n] << endl;
  }*/

  cout << Fib(n) << endl;
}
