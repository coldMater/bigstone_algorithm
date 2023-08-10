// https://www.acmicpc.net/problem/1189
#include <bits/stdc++.h>
using namespace std;

int R, C, K;
char m[6][6];
int dy[4] = { -1 , 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int rc = 0; // result count

void print () {
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      cout << m[i][j] << "";
    }
    cout << "\n";
  }
  cout << "\n";
}

void go (int y, int x, char d) {
  if (y == 1 && x == C) {
    // print ();
    if (d - 'a' + 1 == K) {
      rc++;
    }
  }
  m[y][x] = d;

  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
    if (m[ny][nx] != '.') continue;
    go(ny, nx, d + 1);
    m[ny][nx] = '.';
  }
}

int main () {
  cin >> R >> C >> K;
  // cout << "\n";
  for (int i = 1; i <= R; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= C; ++j) {
      m[i][j] = s[j - 1];
    }
  }

  go(R, 1, 'a');
  cout << rc;
  return 0;
}
