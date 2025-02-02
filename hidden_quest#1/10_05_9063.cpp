#include <bits/stdc++.h>
using namespace std;

int N;
int x, y;
int l = 10000, r = -10000, d = 10000, h = -10000; // <, >, v, ^
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    l = min(l, x);
    r = max(r, x);
    d = min(d, y);
    h = max(h, y);
  }
  cout << (r - l) * (h - d);
  return 0;
}