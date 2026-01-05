// https://www.acmicpc.net/problem/15972
#include <bits/stdc++.h>
using namespace std;

enum Direction {
  TOP = 0,
  RIGHT,
  BOTTOM,
  LEFT,
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N, M, H;
int temp;
int walls[1002][1002][4]; // ⚠️ walls[1001][1001] memory overflow
int wh[1001][1001]; // heights of water
vector<pair<pair<int, int>, int>> drains;

struct comp{
    bool operator()(pair<pair<int, int>, int> & a, pair<pair<int, int>, int> & b){
      if (a.second > b.second) return true;
      return false;
    }
};

int main () {
  cin >> N >> M >> H;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      wh[i][j] = H;
    }
  }

  for (int i = 1; i <= N + 1; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> temp;
      walls[i - 1][j][BOTTOM] = temp;
      walls[i][j][TOP] = temp;
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M + 1; ++j) {
      cin >> temp;
      walls[i][j - 1][RIGHT] = temp;
      walls[i][j][LEFT] = temp;
    }
  }

  // upper drains
  for (int i = 1; i <= M; ++i) {
    int h = walls[1][i][TOP];
    if (h == -1) continue;
    drains.push_back({ { 1, i }, walls[1][i][TOP] });
    // cout << "upper: " << i << ", height: " << walls[1][i][TOP] << "\n";
  }

  // right drains
  for (int i = 1; i <= N; ++i) {
    int h = walls[i][M][RIGHT];
    if (h == -1) continue;
    drains.push_back({ { i, M }, h });
    // cout << "right: " << i << ", height: " << walls[i][M][RIGHT] << "\n";
  }

  // bottom drains
  for (int i = 1; i <= M; ++i) {
    int h = walls[N][i][BOTTOM];
    if (h == -1) continue;
    drains.push_back({ { N, i }, h });
    // cout << "bottom: " << i << ", height: " << walls[N][i][BOTTOM] << "\n";
  }

  // left drains
  for (int i = 1; i <= N; ++i) {
    int h = walls[i][1][LEFT];
    if (h == -1) continue;
    drains.push_back({ { i, 1 }, h });
    // cout << "left: " << i << ", height: " << walls[i][1][LEFT] << "\n";
  }


  while (!drains.empty()) {
    auto drain = drains.back();
    drains.pop_back();

    priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> q;
    if (drain.second >= wh[drain.first.first][drain.first.second]) continue;
    wh[drain.first.first][drain.first.second] = drain.second;
    q.push(drain);

    while (!q.empty()) {
      int y = q.top().first.first;
      int x = q.top().first.second;
      int h = q.top().second;
      q.pop();

      for (int i = 0; i < 4; ++i) {
        if (walls[y][x][i] == -1) continue;

        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
        int height_hall = walls[y][x][i];
        int height_next = wh[ny][nx];

        if (height_hall <= h && height_next > h) {
          wh[ny][nx] = h;
          q.push({ { ny, nx }, wh[ny][nx] });
          continue;
        }

        if (height_hall > h && height_hall <= height_next) {
          wh[ny][nx] = height_hall;
          q.push({ { ny, nx }, wh[ny][nx] });
          continue;
        }
      }
    }
  }

  int res = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      res += wh[i][j];
      // if (wh[i][j] != 1) {
      //   cout << i << " " << j << " " << " - H: " << wh[i][j] << "\n";
      // }
    }
    // cout << "\n";
  }
  cout << res;
  return 0;
}
