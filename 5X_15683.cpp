// https://www.acmicpc.net/problem/15683
#include <bits/stdc++.h>
using namespace std;

struct camera {
  int r;
  int c;
  int t; // type
};

int N, M;
int b[8][8];
vector<camera> cs; // cameras

void printDirs(vector<int> dirs) {
  for (int d : dirs) {
    cout << d;
  }
  cout << "\n";
} 

int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

void watch (int y, int x, int d, int b[8][8]) { // row, col, direction
  while (true) {
    y += dy[d]; // propagate vertically
    x += dx[d]; // propagate horizontally
    if (y < 0 || x < 0 || y >= N || x >= M || b[y][x] == 6) break; // met wall or outside the border, terminate propagation.
    b[y][x] = 7; // fill as watched area
  }
}

void printBoard(int b[8][8]) {
  cout << "\n";
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      cout << b[r][c] << " ";
    }
    cout << "\n";
  }
}

int go (int d, vector<int> dirs) { // depth, direction
  if (d == cs.size()) {
    // printDirs(dirs);
    int brd[8][8];
    memcpy(brd, b, sizeof(b));
    for (int i = 0; i < dirs.size(); ++i) {
      camera c = cs[i];
      if (c.t == 5) { // #5 cemera
        watch(c.r, c.c, 0, brd);
        watch(c.r, c.c, 1, brd);
        watch(c.r, c.c, 2, brd);
        watch(c.r, c.c, 3, brd);
      } else if (c.t == 1) { // #1 camera
        watch(c.r, c.c, dirs[i], brd);
      } else if (c.t == 2) { // #2 camera
        watch(c.r, c.c, dirs[i], brd);
        watch(c.r, c.c, (dirs[i] + 2) % 4, brd);
      } else if (c.t == 3) { // #3 cemera
        watch(c.r, c.c, dirs[i], brd);
        watch(c.r, c.c, (dirs[i] + 1) % 4, brd);
      } else if (c.t == 4) { // #4 camera
        watch(c.r, c.c, dirs[i], brd);
        watch(c.r, c.c, (dirs[i] + 1) % 4, brd);
        watch(c.r, c.c, (dirs[i] + 3) % 4, brd);
      }
    }
    // printBoard(brd);
    int blindSpotCnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (brd[i][j] == 0) blindSpotCnt++;
      }
    }

    // cout << "blind spot count: " << blindSpotCnt;
    // cout << "\n";
    return blindSpotCnt;
  }

  int minimum = 987'654'321;
  for (int i = 0; i < 4; ++i) {
    dirs.push_back(i);
    minimum = min(go(d + 1, dirs), minimum);
    dirs.pop_back();
  }

  return minimum;
}

int main () {
  cin >> N >> M;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      int temp;
      cin >> temp;
      b[r][c] = temp; // wall or empty
      if (temp >= 1 && temp <= 5) cs.push_back({ r, c, temp }); // camera
    }
  }

  // cout << "\n";
  vector<int> dirs; // directions
  // cout << "\n";
  cout << go(0, dirs);

  return 0;
}
