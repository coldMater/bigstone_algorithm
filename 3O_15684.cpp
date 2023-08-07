// https://www.acmicpc.net/problem/15684
#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int a, b;
int m[34][12];
int test[34][12];
int r = 987654321; // result - min

void print () {
  for (int i = 1 ; i <= H; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
}

void print2() {
  for (int i = 1 ; i <= H + 1; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << test[i][j] << " ";
    }
    cout << "\n";
  }
}

bool check() {
  for (int i = 1; i <= N; ++i) {
    int y = 1;
    int x = i;
    // cout << "=====\n";
    // print();
    // cout << "-----\n";
    // memcpy(test, m, sizeof(m));
    while (true) {
      // test[y][x] = 8;
      if (y > H && i == x) { 
        // cout << "O - (" << i << "-" << x << ")\n";
        break;
      }
      if (y > H && i != x) {
        // cout << "X - (" << i << "-" << x << ")\n\n";
        return false;
      }
      // cout << y << ":" << x << "\n";
      if (x < N && m[y][x] != 0) {
        x = x + 1;
      } else if (x > 1 && m[y][x - 1] != 0) {
        x = x - 1;
      }
      y++;
    }
  }
  // cout << "Perfect Match!\n\n";
  return true;
}

void go (int y, int x, int d) {
  if (d > 3) return;
  // cout << y << ":" << x << ":" << d << "\n";
  // print();
  // cout << "\n";
  if (check()) {
    // cout << "condition!" << d << "\n";
    r = min(r, d);
  }

  for (int ny = y; ny <= H; ++ny) {
    for (int nx = 1; nx < N; ++nx) {
      if (m[ny][nx] == 1 || (nx - 1 >= 1 && m[ny][nx - 1] == 1)) continue;
      m[ny][nx] = 1;
      go(ny, nx, d + 1);
      m[ny][nx] = 0;
    }
  }
}

int main () {
  cin >> N >> M >> H;

  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    m[a][b] = 1;
  }

  // if (check()) {
  //   cout << 0;
  //   return 0;
  // }
  // print();

  go (1, 1, 0);
  if (r > 3) {
    cout << -1;
    return 0;
  }
  cout << r;

  return 0;
}