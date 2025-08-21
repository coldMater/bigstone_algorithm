// https://www.acmicpc.net/problem/1514
#include <bits/stdc++.h>
using namespace std;

int N;
int s[103]; // source state lock
int t[103]; // target state of lock
int dp[103][10][10][10][2];
int rotate (int res) {
  if (res < 0) return res + 10;
  else return res % 10;
}

int go(int i, int x, int y, int z, int d) {
  // cout << i << ": " << x << " " << y << " " << z << "\n";
  if (i >= N) return 0;

  int &dpv = dp[i][x][y][z][d];
  if (dpv != -1) return dpv;
  if (x == t[i]) {
    // return go(i + 1, y, z, s[i + 3]);
    return dpv = min(go(i + 1, y, z, s[i + 3], 0), go(i + 1, y, z, s[i + 3], 1));
  }
  
  dpv = 1e9; // ⚠️ You might consider declaring a new variable like int mn = 1e9; and assigning its value to dpv at the end. However, doing so can lead to situations where the value of dpv is not finalized, causing the lock to keep rotating or resulting in an infinite loop.  
  int dd = d ? 1 : -1;
  for (int r = 1 ; r <= 3; ++r) {
    dpv = min(dpv, go(i, rotate(x + r * dd), y, z, d) + 1); // rotate 1st disk only
    dpv = min(dpv, go(i, rotate(x + r * dd), rotate(y + r * dd), z, d) + 1); // rotate both 1st and 2nd disks (backward)
    dpv = min(dpv, go(i, rotate(x + r * dd), rotate(y + r * dd), rotate(z + r * dd), d) + 1); // rotate all three disks (backward)
  }

  return dpv;
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) scanf("%1d", &s[i]);
  for (int i = 0; i < N; ++i) scanf("%1d", &t[i]);
  memset(dp, -1, sizeof(dp));

  cout << min(go(0, s[0], s[1], s[2], 0), go(0, s[0], s[1], s[2], 1));
  return 0;
}