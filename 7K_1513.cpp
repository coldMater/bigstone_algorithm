// https://www.acmicpc.net/problem/1513
#include <bits/stdc++.h>
using namespace std;

int N, M, C;
int arcades[51][51];
int dp[51][51][51][51];
int go (int y, int x, int ac, int pa) { // ac: arcade (remained) count, pa: previous arcade (number)
  // cout << "x, y, ac: " << x << " " << y << " " << ac << "\n";
  if (y > N || x > M) return 0;
  if (ac < 0) return 0; // Impossible path: Exceeds the number of accessible arcades.
  if (y == N && x == M) { // Reach the bottom-right corner.
    if (arcades[y][x] == 0 && ac == 0) return 1; // Case 1: This position is not an arcade.  
    if (arcades[y][x] != 0) { // Case 2: This position is an arcade.  
      if (arcades[y][x] < pa) return 0;
      if (ac == 1) return 1;
    }
    return 0; // Case 3: This position is an arcade, but the visit count does not meet the required number of arcades to visit.
  }

  int &dpv = dp[y][x][ac][pa];
  if (dpv != -1) return dpv;

  if (arcades[y][x] == 0) { // (y, x) is not an arcade.
    int down = go(y + 1, x, ac, pa);
    int right = go(y, x + 1, ac, pa);
    return dpv = (down + right) % 1'000'007;
  } else { // (y, x) is an arcade
    if (arcades[y][x] < pa) return 0; // The arcade's number is smaller than the previously visited arcade's number.
    int down = go(y + 1, x, ac - 1, arcades[y][x]);
    int right = go(y, x + 1, ac - 1, arcades[y][x]);
    return dpv = (down + right) % 1'000'007;
  }


}
int main () {
  cin >> N >> M >> C;

  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < C; ++i) {
    int tempY, tempX;
    cin >> tempY;
    cin >> tempX;
    arcades[tempY][tempX] = i + 1;
  }

  for (int i = 0; i <= C; ++i) { // i: arcade count
    cout << go(1, 1, i, 0) % 1'000'007 << " ";
    // go(1, 1, i, 0);
  }
  return 0;
}