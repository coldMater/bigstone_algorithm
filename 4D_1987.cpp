// https://www.acmicpc.net/problem/1987
#include <bits/stdc++.h>
using namespace std;

int R, C; // row, col
char m[21][21];
int visited[21][21];
int cc;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int a; // alphabet
int md; // max depth

void print () {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << m[i][j];
    }
    cout << "\n";
  }
}

bool checkAlphabet (char n) {
  // if (a & (1 << n - 'A')) return true;
  if (a & (1 << n)) return true;
  return false;
}

void go (int y, int x, int d) {
  // cout << d << " " << m[y][x] << "\n";
  visited[y][x] = 1;
  // a |= 1 << (m[y][x] - 'A');
  a |= 1 << (m[y][x]);
  md = max(md, d);
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
    if (visited[ny][nx]) continue;
    if (checkAlphabet(m[ny][nx])) continue;
    go (ny, nx, d + 1);
  }
  // a &= ~(1 << (m[y][x] - 'A'));
  a &= ~(1 << (m[y][x]));
  visited[y][x] = 0;
}

int main () {
  cin >> R >> C;
  for (int i = 0; i < R; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < C; ++j) {
      m[i][j] = s[j];
    }
  }

  go (0, 0, 1);

  cout << md;

  return 0;
}
