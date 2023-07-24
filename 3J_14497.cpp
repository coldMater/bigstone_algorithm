// https://www.acmicpc.net/problem/14497
#include <bits/stdc++.h>
using namespace std;

int h, w;
string s;
int jy, jx, ty, tx; // junan's x & y, target's x & y
char m[301][301];
int visited[301][301];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int, int>> c; // A candidate who will pass out
bool f; // found

void dfs(int y, int x) {
  visited[y][x] = 1;
  if (m[y][x] == '#') {
    f = true;
    return;
  }
  if (f) return;
  if (m[y][x] == '1') {
    c.push_back({y, x});
    return;
  }

  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
    if (visited[ny][nx]) continue;
    dfs(ny, nx);
  }
}

int main () {
  cin >> h >> w;
  cin >> jy >> jx >> ty >> tx;
  for (int i = 0; i < h; ++i) {
    cin >> s;
    for (int j = 0; j < w; ++j) {
      m[i][j] = s[j];
    }
  }

  int count = 0;
  while (true) {
    count++;
    dfs(jy - 1, jx - 1);
    if (f) break;
    for (auto t : c) {
      m[t.first][t.second] = '0';
    }
    fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
  }

  cout << count;

  return 0;
}
