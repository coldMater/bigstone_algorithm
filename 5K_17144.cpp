// https://www.acmicpc.net/problem/17144
#include <bits/stdc++.h>
using namespace std;

int R, C, T;
int m[50][50];
int nm[50][50]; // next map

int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

int u, d; // location of air cleaner Up & Down

void printM () {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << m[i][j] << "\t";
    }
    cout << "\n";
  }
}

void printNm () {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << nm[i][j] << "\t";
    }
    cout << "\n";
  }
}

int main () {
  cin >> R >> C >> T;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < R; ++i) {
    if (m[i][0] == -1) {
      u = i;
      d = i + 1;
      break;
    }
  }

  // cout << "u: " << u << " d: " << d << "\n";

  for (int i = 0; i < T; ++i) {
    // spread phase
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (m[r][c] == -1 || m[r][c] == 0) continue; // location of air cleaner
        int spread = m[r][c] / 5;
        for (int n = 0; n < 4; ++n) {
          int ny = r + dy[n];
          int nx = c + dx[n];
          if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue; // ⚠️ caution: ny with R(row), nx with C(col)
          if (m[ny][nx] == -1) continue;
          nm[ny][nx] += spread;
          m[r][c] -= spread;
        }
      }
    }

    // add phase
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        m[i][j] += nm[i][j];
      }
    }
    
    // reset nm
    memset(nm, 0, sizeof(nm));

    // wind phase A - top circle
    // left side
    for (int y = u - 1; y > 0; --y) {
      m[y][0] = m[y - 1][0];
    }
    // top side
    for (int x = 0; x + 1 < C; ++x) {
      m[0][x] = m[0][x + 1];
    }
    // right side
    for (int y = 1; y <= u; ++y) {
      m[y - 1][C - 1] = m[y][C - 1];
    }
    // bottom side
    for (int x = C - 1; x > 1; --x) {
      m[u][x] = m[u][x - 1];
    }
    m[u][1] = 0;


    // wind phase A - top circle
    // left side
    for (int y = d + 1; y + 1 < R; ++y) {
      m[y][0] = m[y + 1][0];
    }
    // bottom side
    for (int x = 0; x + 1 < C; ++x) {
      m[R - 1][x] = m[R - 1][x + 1];
    }
    // right side
    for (int y = C - 1; y - 1 >= d; --y) {
      m[y][C - 1] = m[y - 1][C - 1];
    }
    // top side
    for (int x = C - 1; x - 1 >= 1; --x) {
      m[d][x] = m[d][x - 1];
    }
    m[d][1] = 0;
  }

  int res = 0;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (m[i][j] != -1) res += m[i][j];
    }
  }

  cout << res;

  return 0;
}