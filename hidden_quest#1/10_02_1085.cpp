#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;
int main () {
  cin >> x >> y >> w >> h;

  int r = w - x;
  int l = x;
  int u = h - y;
  int d = y;

  cout << min(r, min(l, min(u, d)));
  return 0;
}