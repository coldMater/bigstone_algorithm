// https://www.acmicpc.net/problem/1932
#include <bits/stdc++.h>
using namespace std;

int n, t;
int dp[501][501];
int main () {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> t;
      dp[i][j] = t + max(dp[i - 1][j], dp[i - 1][j - 1]);
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, dp[n][i]);
  }

  cout << mx;

  return 0;
}