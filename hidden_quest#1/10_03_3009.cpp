#include <bits/stdc++.h>
using namespace std;

int xc[1001], yc[1001];
int main () {
  for (int i = 0; i < 3; ++i) {
    int x, y;
    cin >> x >> y;
    xc[x]++;
    yc[y]++;
  }
  for (int i = 0; i < 1001; ++i) {
    if (xc[i] == 1) cout << i;
  }
  cout << " ";
  for (int i = 0; i < 1001; ++i) {
    if (yc[i] == 1) cout << i;
  }
  return 0;
}