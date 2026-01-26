#include <bits/stdc++.h>
using namespace std;

int N;
int L = 1'000'000'000;
long long dp[10][101];
int go (int s, int n) {
  if (n == N) return 1;

  long long &dpv = dp[s][n];
  if (dpv) return dpv;

  long long ret = 0;
  if (s != 0) {
    ret += go (s - 1, n + 1);
    ret %= L;
  }
  if (s != 9) {
    ret += go (s + 1, n + 1);
    ret %= L;
  }
  return dpv = ret;
}
int main () {
  cin >> N;

  long long res = 0;
  for (int i = 1; i <= 9; ++i) {
    res += go (i, 1);
    res %= L;
  }

  cout << res;
  return 0;
}