// https://www.acmicpc.net/problem/12100
#include <bits/stdc++.h>
using namespace std;

int N;
int board[20][20]; // board
int org[20][20]; // original board

void printBoard (int b[20][20]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << b[i][j] << "\t";
    }
    cout << "\n";
  }
  cout << "\n";
}

void right(int b[20][20]) {
  // phase1 - move
  // cout << "phase1 - move" << "\n";

  for (int y = 0; y < N; ++y) {
    vector<int> temp;
    for (int x = 0; x < N; ++x) {
      if (b[y][x] != 0) {
        temp.push_back(b[y][x]);
      }
    }

    // fill cell from right side
    int rx = N - 1; // reverse X
    while (temp.size()) {
      b[y][rx--] = temp.back();
      temp.pop_back();
    }

    // initialize (already moved cell -> initialize to zero)
    while (rx >= 0) {
      b[y][rx--] = 0;
    }
  }
  // printBoard();

  // phase2 - merge and shift
  // cout << "phase2 - merge and shift" << "\n";
  for (int y = 0; y < N; ++y) {
    for (int x = N - 1; x >= 1; --x) {
      if (b[y][x] != b[y][x - 1]) continue;
      b[y][x] *= 2;
      b[y][x - 1] = 0;

      for (int i = x - 1; i - 1 >= 0; --i) { // shifting - fill zero
        b[y][i] = b[y][i - 1];
      }
      b[y][0] = 0;
    }
  }
  // printBoard();
}

void down(int b[20][20]) {
  // phase1 - move
  // cout << "phase1 - move" << "\n";

  for (int x = 0; x < N; ++x) {
    vector<int> temp;
    for (int y = 0; y < N; ++y) {
      if (b[y][x] != 0) {
        temp.push_back(b[y][x]);
      }
    }

    // fill cell from right side
    int ry = N - 1; // reverse X
    while (temp.size()) {
      b[ry--][x] = temp.back();
      temp.pop_back();
    }

    // initialize (already moved cell -> initialize to zero)
    while (ry >= 0) {
      b[ry--][x] = 0;
    }
  }
  // printBoard();

  // phase2 - merge and shift
  // cout << "phase2 - merge and shift" << "\n";
  for (int x = 0; x < N; ++x) {
    for (int y = N - 1; y >= 1; --y) {
      if (b[y][x] != b[y - 1][x]) continue;
      b[y][x] *= 2;
      b[y - 1][x] = 0;

      for (int i = y - 1; i - 1 >= 0; --i) { // shifting - fill zero
        b[i][x] = b[i - 1][x];
      }
      b[0][x] = 0;
    }
  }
  // printBoard();
}

void up(int b[20][20]) {
  // phase1 - move
  // cout << "phase1 - move" << "\n";

  for (int x = 0; x < N; ++x) {
    vector<int> temp;
    for (int y = N - 1; y >= 0; --y) {
      if (b[y][x] != 0) {
        temp.push_back(b[y][x]);
      }
    }

    // fill cell from top side
    int ry = 0; // reverse X
    while (temp.size()) {
      b[ry++][x] = temp.back();
      temp.pop_back();
    }

    // initialize (already moved cell -> initialize to zero)
    while (ry < N) {
      b[ry++][x] = 0;
    }
  }
  // printBoard();

  // phase2 - merge and shift
  // cout << "phase2 - merge and shift" << "\n";
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y + 1 < N; ++y) {
      if (b[y][x] != b[y + 1][x]) continue;
      b[y][x] *= 2;
      b[y + 1][x] = 0;

      for (int i = y + 1; i + 1 < N; ++i) { // shifting - fill zero
        b[i][x] = b[i + 1][x];
      }
      b[N - 1][x] = 0;
    }
  }
  // printBoard();
}

void left(int b[20][20]) {
  // phase1 - move
  // cout << "phase1 - move" << "\n";

  for (int y = 0; y < N; ++y) {
    vector<int> temp;
    for (int x = N - 1; x >= 0; --x) {
      if (b[y][x] != 0) {
        temp.push_back(b[y][x]);
      }
    }

    // fill cell from left side
    int rx = 0; // reverse X
    while (temp.size()) {
      b[y][rx++] = temp.back();
      temp.pop_back();
    }

    // initialize (already moved cell -> initialize to zero)
    while (rx < N) {
      b[y][rx++] = 0;
    }
  }
  // printBoard();

  // phase2 - merge and shift
  // cout << "phase2 - merge and shift" << "\n";
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x + 1 < N; ++x) {
      if (b[y][x] != b[y][x + 1]) continue;
      b[y][x] *= 2;
      b[y][x + 1] = 0;

      for (int i = x + 1; i + 1< N; ++i) { // shifting - fill zero
        b[y][i] = b[y][i + 1];
      }
      b[y][N - 1] = 0;
    }
  }
  // printBoard();
}

int go (int d, int t[20][20]) {
  if (d >= 5) {
    // printBoard(t);
    int m = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        m = max(m, t[i][j]);
      }
    }
    // cout << "max: " << m << "\n";
    return m;
  }

  int ut[20][20];
  memcpy(ut, t, sizeof(ut));
  up(ut);
  int up = go (d + 1, ut);

  int rt[20][20];
  memcpy(rt, t, sizeof(rt));
  right(rt);
  int right = go (d + 1, rt);

  int dt[20][20];
  memcpy(dt, t, sizeof(dt));
  down(dt);
  int down = go (d + 1, dt);

  int lt[20][20];
  memcpy(lt, t, sizeof(lt));
  left(lt);
  int left = go (d + 1, lt);

  return max(max(max(up, right), down), left);
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int temp;
      cin >> temp;
      org[i][j] = temp;
    }
  }

  // memcpy(board, org, sizeof(board));

  // printBoard(board);
  cout << go(0, org);
}
