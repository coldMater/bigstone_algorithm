// https://www.acmicpc.net/problem/3197
#include <bits/stdc++.h>
using namespace std;

int r, c;
const int M = 1501;
char m[M][M];
int visited[M][M];
int sVisited[M][M]; // swan visited
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> ss; // swans
vector<pair<int, int>> ims; // ice list to be melted

void dfs(int y, int x) {
  visited[y][x] = 1;
  if (m[y][x] == 'X') {
    ims.push_back({ y, x });
    return;
  }
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
    if (visited[ny][nx] != 0) continue;
    dfs(ny, nx);
  }
}

bool check () {
  fill(&sVisited[0][0], &sVisited[0][0] + M * M, 0);
  queue<pair<int, int>> q;
  q.push({ ss[0].first, ss[0].second });
  sVisited[ss[0].first][ss[0].second] = 1;
  while (!q.empty()) {
    pair<int, int> prev = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = prev.first + dy[i];
      int nx = prev.second + dx[i];
      if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
      if (sVisited[ny][nx] != 0) continue;
      if (m[ny][nx] == 'X') continue;
      sVisited[ny][nx] = 1;
      if (ny == ss[1].first && nx == ss[1].second) { 
        return true;
      }
      q.push({ ny, nx });
    }
  }
  return false;
}

int main () {
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < c; ++j) {
      m[i][j] = s[j];
      if (m[i][j] == 'L') {
        ss.push_back({ i, j });
      }
    }
  }

  int d = 0;
  while (true) {

    d++;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (m[i][j] == 'X' || visited[i][j] != 0) continue;
        dfs(i, j);
      }
    }
    for (pair<int, int> i : ims) {
      m[i.first][i.second] = '.';
    }
    ims.clear();
    fill(&visited[0][0], &visited[0][0] + M * M, 0);
    if (check()) {
      cout << d;
      break;
    }
  }

  return 0;
}
