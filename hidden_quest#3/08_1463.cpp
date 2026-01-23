// https://www.acmicpc.net/problem/1463
#include <bits/stdc++.h>
using namespace std;

int N;
int INF = 987654321;
int dp[1'000'001];

int main () {
  cin >> N;

  fill(dp, dp + 1000001, INF);

  dp[N] = 0;
  for (int i = N; i > 1; --i) {
    if (i % 3 == 0) dp[i / 3] = min(dp[i / 3], dp[i] + 1);
    if (i % 2 == 0) dp[i / 2] = min(dp[i / 2], dp[i] + 1);
    dp[i - 1] = min(dp[i - 1], dp[i] + 1);
  }
  // for (int i = 0; i < 10; ++i) {
  //   cout << dp[i] << " ";
  // }
  cout << dp[1];
  return 0;
}