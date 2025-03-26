// https://www.acmicpc.net/problem/5557
#include <bits/stdc++.h>
using namespace std;

int N;
int n[100];
long long dp[100][21];
long long go (int p, int d) { // p: prev, d: depth // ⚠️ Be aware that the sub-sum must not exceed the range of 0 to 20!
  if (!(p >= 0 && p <= 20)) return 0;

  if (d == N - 1) {
    return p == n[N - 1];
  }

  if (dp[d][p] != -1) return dp[d][p];

  dp[d][p] = go(p + n[d], d + 1) + go(p - n[d], d + 1);
  return dp[d][p];
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }

  memset(dp, -1, sizeof(dp));

  cout << go (0, 0);
  return 0;
}