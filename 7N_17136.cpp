// https://www.acmicpc.net/problem/17136
#include<bits/stdc++.h>
using namespace std;

int b[10][10];
int pc[6]; // paper count
int res = 1'234'567'890;
bool check(int n, int y, int x) {
  if (y + n >= 11 || x + n >= 11) return false;
  for (int i = y; i < y + n; ++i) {
    for (int j = x; j < x + n; ++j) {
      if (b[i][j] != 1) return false;
    }
  }
  return true;
}

void mark(int n, int y, int x) {
  for (int i = y; i < y + n; ++i) {
    for (int j = x; j < x + n; ++j) {
      b[i][j] = 0;
    }
  }
}

void unmark(int n, int y, int x) {
  for (int i = y; i < y + n; ++i) {
    for (int j = x; j < x + n; ++j) {
      b[i][j] = 1;
    }
  }
}

void pb() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << b[i][j] << " ";
    }
    cout << "\n";
  }
}

void go(int y, int x, int c) {
  if (x >= 10) { // ->
    go(y + 1, 0, c);
    return;
  }
  if (y >= 10) { // end
    res = min(c, res);
    return;
  }
  
  if (b[y][x] == 0) {
    go(y, x + 1, c);
    return;
  }

  for (int s = 1; s <= 5; ++s) {
    if (check(s, y, x) && pc[s] < 5) { // 🚩 caution: counting limit 
      // cout << "s,y,x: " << s << "," << y << ", " << x << "\n";
      pc[s]++;
      mark(s, y, x);
      // pb();
      // cout << "\n";
      go(y, x + s, c + 1);
      unmark(s, y, x);
      pc[s]--;
      // pb();
      // cout << "\n";
    }
  }
}

int main () {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> b[i][j];
    }
  }

  go(0, 0, 0);
  if (res == 1'234'567'890) cout << -1;
  else cout << res;
  return 0;
}
