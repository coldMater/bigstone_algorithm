// https://www.acmicpc.net/problem/9461
#include <bits/stdc++.h>
using namespace std;

int T, N;

int dp[101];
int main () {
  cin >> T;

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  for (int n = 4; n <= 100; ++n) {
    dp[n] = dp[n - 2] + dp [n - 3];
  }

  while (T--) {
    cin >> N;
    cout << dp[N] << "\n";
  }

  return 0;
}