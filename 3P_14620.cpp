// https://www.acmicpc.net/problem/14620
#include <bits/stdc++.h>
using namespace std;

int N;
int m[11][11];
int v[11][11];
int c = 987654321; // cost
vector<pair<int,int>> s; // seeds

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ddy[4] = { -2, 0, 2, 0 }; // double -
int ddx[4] = { 0, 2, 0, -2 }; // double -
int diy[4] = { -1, 1, 1, -1 }; // diagonal -
int dix[4] = { 1, 1, -1, -1 }; // diagonal - 

void bloom() {

}

void print () {
  fill(&v[0][0], &v[10][10], 0);
  for (auto as : s) {
    v[as.first][as.second] = 1;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
}

bool canSeedOn(int y, int x) {
  // edge of garden - cannot seed
  if (y == 1 || x == 1 || y == N || x == N) return false;

  // overlaps with seeds already planted
  for (pair<int, int> as : s) { // already seeded
    int sy = as.first; // seed X
    int sx = as.second; // seed X

    if (sy == y && sx == x) return false;

    // distance 1
    for (int i = 0; i < 4; ++i) {
      int by = sy + dy[i]; // branch Y
      int bx = sx + dx[i]; // branch X
      if (by == y && bx == x) return false;
    }

    // distance 2
    for (int i = 0; i < 4; ++i) {
      int by2 = sy + ddy[i]; // doubled branch Y
      int bx2 = sx + ddx[i]; // doubled branch X
      if (by2 == y && bx2 == x) return false;
    }

    // diagonal direction
    for (int i = 0; i < 4; ++i) {
      int diy2 = sy + diy[i];
      int dix2 = sx + dix[i];
      if (diy2 == y && dix2 == x) return false;
    }
  }

  return true;
}

int calc() {
  int cost = 0;
  for (pair<int, int> as : s) {
    int y = as.first;
    int x = as.second;
    cost += m[y][x];
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      cost += m[ny][nx];
    }
  }
  return cost;
}

void go (int y, int x, int d) {
  if (s.size() >= 3) {
    // print();
    // if (calc() <= c) {
      // print();
      // cout << calc() << "\n\n";
    // }
    c = min(c, calc());
    return;
  }
  for (int ny = 1; ny <= N; ++ny) {
    for (int nx = 1; nx <= N; ++nx) {
      if (!canSeedOn(ny, nx)) continue;
      s.push_back({ ny, nx });
      go(ny, nx, d + 1);
      s.pop_back();
    }
  }
}

int main () {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> m[i][j];
    }
  }

  go(1, 1, 0);

  cout << c;
  return 0;
}