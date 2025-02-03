#include <bits/stdc++.h>
using namespace std;

int a1, a0, c, n0;

int f (int n) {
  return a1 * n + a0;
}

int g (int n) {
  return n;
}

int main () {
  cin >> a1 >> a0 >> c >> n0;
  for (int n = n0; n <= 100; ++n) {
    if (f(n) <= c * g(n)) {
      continue;
    }
    cout << 0;
    return 0;
  }
  cout << 1;
  return 0;
}