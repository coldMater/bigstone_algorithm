// https://www.acmicpc.net/problem/17070
#include <bits/stdc++.h>
using namespace std;

int N;
int m[16][16];
int py = 0;
int px = 1;
int pd = 0; // 0: right, 1: down, 2: downRight(diagonal)
int dp[16][16][3]; // for dp (dp[y][x][d])

int go (int y, int x, int d) { // d: direction
  if (y >= N || x >= N) { // out of bounds of the given board
    return 0;
  }
  if (m[y][x] == 1 || (d == 2 && (m[y - 1][x] == 1 || m[y][x - 1]))) { // blocked by wall
    return 0;
  }

  if (y == N - 1 && x == N - 1) {
    // end condition
    return 1;
  }

  if (dp[y][x][d]) return dp[y][x][d]; // ⚠️ This line must not be placed at the beginning of the function.
  if (d == 0) { // previous direction: right
    int rc = go(y, x + 1, 0); // go right count
    int drc = go(y + 1, x + 1, 2); // go down right(diagonal) count
    dp[y][x][d] = rc + drc;
    return rc + drc;
  } else if (d == 1) { // previous direction: down
    int dc = go(y + 1, x, 1); // go down count
    int drc = go(y + 1, x + 1, 2); // go down right(diagonal) count
    dp[y][x][d] = dc + drc;
    return dc + drc;
  } else if (d == 2) { // downRight
    int rc = go(y, x + 1, 0); // go right count
    int drc = go(y + 1, x + 1, 2); // go down right(diagonal) count
    int dc = go(y + 1, x, 1); // go down count
    dp[y][x][d] = rc + drc + dc;
    return rc + drc + dc;
  } else {
    // exception
  }
  return 0;
}

void pb() {
  cout << "board: \n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> m[i][j];
    }
  }
  // pb();

  cout << go(py, px, pd);

  return 0;
}