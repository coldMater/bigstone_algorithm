// https://www.acmicpc.net/problem/1103
#include <bits/stdc++.h>
using namespace std;

int N, M, trash;
string s;
int m[50][50];
int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};
int INF = 1'234'567'890;
int dp[50][50][50*50]; // 🚩 Why is the third argument, depth, needed?
void printBoard() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
}

int go(int y, int x, int depth) {
  cout << "y,x: " << y << "," << x << "\n";
  if (depth > N * M) return INF;
  if (y < 0 || x < 0 || y >= N || x >= M) return 0;
  int X = m[y][x];
  if (X == 'H' - '0') return 0;

  int &mem = dp[y][x][depth];
  if (mem) return mem;
  int mx = 0; // max
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i] * X ;
    int nx = x + dx[i] * X;
    mx = max(go(ny, nx, depth + 1), mx);
  }
  dp[y][x][depth] = mem;
  return mx + 1;
}

int main () {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> s;
    for (int j = 0; j < M; ++j) {
      m[i][j] = s[j] - '0';
    }
  }

  int res = go(0, 0, 0);
  if (res >= INF) {
    cout << -1;
  } else {
    cout << res;
  }
  // printBoard();
}