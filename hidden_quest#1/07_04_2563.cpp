#include <bits/stdc++.h>
using namespace std;

int c[100][100];
int n;
int a, b;
int res;
void f(int w, int h) {
  for (int y = h; y < h + 10; ++y) {
    for (int x = w; x < w + 10; ++x) {
      c[y][x] = 1;
    }
  }
}

int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    f(a, b);
  }
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (c[i][j]) res++;
    }
  }
  cout << res;
  return 0; 
}