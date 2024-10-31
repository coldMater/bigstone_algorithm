// https://www.acmicpc.net/problem/17822
#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int m[50][50];
int r[50][3]; // rotate method
void printDisks () {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void printV(int v[50][50]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void rotate(int n, int d, int k) { // nth disk, rotation count, direction(0: clockwise, 1: anti-)
  if (d == 0) {
    while(k--) {
      int tail = m[n][M - 1];
      // cout << "tail: " << tail << "\n";
      for (int i = M - 1; i > 0; --i) {
        m[n][i] = m[n][i - 1];
      }
      m[n][0] = tail;
    }
  }
  if (d == 1) {
    while(k--) {
      int head = m[n][0];
      for (int i = 1; i < M; ++i) {
        m[n][i - 1] = m[n][i];
      }
      m[n][M - 1] = head;
    }
  }
}

int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1 };
int go (int n, int mm, int v[50][50], int d) { // n: index of disk, mm: mth number of disk, b: before number, v: visited
  v[n][mm] = d;
  for (int i = 0; i < 4; ++i) {
    int ny = n + dy[i];
    if (ny >= N) continue;
    if (ny < 0) continue;
    int nx = mm + dx[i];
    if (nx >= M) nx = 0;
    if (nx < 0) nx = M - 1;

    if (v[ny][nx] || m[ny][nx] == 0) continue;
    if (m[ny][nx] == m[n][mm]) {
      v[n][mm] = go(ny, nx, v, d + 1);
    }
  }
  return d;
}

int erase() { // nth disk
  int v[50][50];
  memset(v, 0, sizeof(v));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (v[i][j] || m[i][j] == 0) continue;
      go (i, j, v, 0);
    }
  }
  // cout << "v:\n";
  // printV(v);
  int erasedCnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (v[i][j] == 0) continue;
      else {
        m[i][j] = 0;
        erasedCnt++;
      }
    }
  }
  return erasedCnt;
}

void rumble() {
  int sum = 0;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (m[i][j]) {
        sum += m[i][j];
        cnt++;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int smaller = sum - (m[i][j] * cnt) > 0;
      int larger = sum - (m[i][j] * cnt) < 0;
      if (m[i][j] == 0) continue;
      if (larger) m[i][j]--;
      if (smaller) m[i][j]++;
    }
  }
}

int total() {
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      sum += m[i][j];
    }
  }
  return sum;
}

int main () {
  cin >> N >> M >> T;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < T; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> r[i][j];
    }
  }

  for (int i = 0; i < T; ++i) {
    int x = r[i][0];
    int d = r[i][1];
    int k = r[i][2];
    for (int j = 0; j < N; ++j) {
      if ((j + 1) % x != 0) continue;
      rotate(j, d, k);
    }
    // cout << "rotated:" << "\n";
    // printDisks();
    int erasedCnt = erase();
    // cout << "erased:" << "\n";
    // printDisks();
    if (erasedCnt == 0) {
      rumble();
      // cout << "rumbled:" << "\n";
      // printDisks();
    }
  }

  // printDisks();

  cout << total();

  return 0;
}