// https://www.acmicpc.net/problem/1904
#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000001];
int go (int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;

  int &dpv = dp[n];
  if (dpv != 0) return dpv;

  /**
   * go(n - 2): when rightmost two bits are `00`;
   * go(n - 1): when rightmost bit is `1`;
   */
  dpv = (go(n - 2) + go(n - 1)) % 15746;
  return dpv;
}
int main () {
  cin >> N;

  cout << go(N);
  return 0;
}