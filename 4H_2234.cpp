// https://www.acmicpc.net/problem/2234
#include <bits/stdc++.h>
using namespace std;

int N, M;
int m[50][50];
int visited[50][50];
int dy[4] = { 0, -1, 0, 1 }; // 1, 2, 4, 8
int dx[4] = { -1, 0, 1, 0 };
int rc; // room count
int mrs; // max room size
void print () {
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << visited[i][j] << "\t";
    }
    cout << "\n";
  }
}

int dfs(int y, int x) { // x, y, room size
  visited[y][x] = 1;
  // cout << m[y][x] << " " << y << " " << x << ": visited" << "\n";

  int count = 1;
  for (int i = 0; i < 4; ++i) {
    if ((m[y][x] & (1 << i)) != 0) continue;
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
    if (visited[ny][nx]) continue;
    count += dfs(ny, nx);
  }
  // cout << y << ":" << x <<  " - " << count << "\n";
  return count;
}

int main () {
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      int wall;
      cin >> wall;
      m[i][j] = wall;
    }
  }

  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x) {
      if (visited[y][x]) continue;
      mrs = max(mrs, dfs(y, x));
      rc++;
    }
  }

  cout << rc << "\n";
  cout << mrs << "\n";

  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x) {
      for (int i = 0; i < 4; ++i) {
        memset(visited, 0, sizeof(visited));
        int temp = m[y][x] ;
        m[y][x] = (m[y][x] & ~(1 << i));
        for (int yy = 0; yy < M; ++yy) {
          for (int xx = 0; xx < N; ++xx) {
            if (visited[yy][xx]) continue;
            mrs = max(mrs, dfs(yy, xx));
          }
        }
        m[y][x] = temp;
      }
    }
  }
  cout << mrs << "\n";

  return 0;
}