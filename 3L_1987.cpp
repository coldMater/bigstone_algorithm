// https://www.acmicpc.net/problem/1987
#include <bits/stdc++.h>
using namespace std;

int R, C, ny, nx;
const int M = 21;
char m[M][M];
int visited[M][M];
int md; // max depth
map<char, bool> h; // history
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void print () {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << m[i][j];
    }
    cout << "\n";
  }
}

void dfs(int y, int x, int d) { // x, y, depth
  // cout << y << ":" << x << "(" << d << ")" << "\n";
  visited[y][x] = 1;
  h[m[y][x]] = true;
  md = max(md, d);

  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
    if (h[m[ny][nx]]) continue;
    dfs(ny, nx, d + 1);
  }

  h[m[y][x]] = false;
  visited[y][x] = 0;
}

int main () {
  for (char c = 'A'; c <= 'Z'; ++c) {
    h[c] = false;
  }
  cin >> R >> C;
  for (int i = 0; i < R; ++i) {
    string s; 
    cin >> s;
    for (int j = 0; j < C; ++j) {
      m[i][j] = s[j];
    }
  }

  dfs(0, 0, 1);
  cout << md;

  return 0;
}