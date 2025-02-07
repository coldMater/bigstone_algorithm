// https://www.acmicpc.net/problem/2293
#include <bits/stdc++.h>
using namespace std;

int n, k, in;
int dp[10001];
int main () {
  cin >> n >> k;
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> in;
    for (int j = in; j <= k; ++j) {
      dp[j] += dp[j - in];
      // cout << dp[j] << " ";
    }
    // cout << "\n";
  }
  cout << dp[k];
  return 0;
}