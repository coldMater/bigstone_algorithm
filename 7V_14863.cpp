// https://www.acmicpc.net/problem/14863
#include <bits/stdc++.h>
using namespace std;

int N, K;
int tw[100]; // time by walk
int mw[100]; // money by walk
int tb[100]; // time by bike
int mb[100]; // money by bike
int NINF = -1'234'567'890;
int dp[100][100'000];
int go(int i, int t) { // i: index, t: time
  if (i == N) {
    return 0;
  }

  if (dp[i][t]) return dp[i][t];

  int m = NINF;
  if (t - tw[i] >= 0) m = max(m, go (i + 1, t - tw[i]) + mw[i]); // walk
  if (t - tb[i] >= 0) m = max(m, go (i + 1, t - tb[i]) + mb[i]); // bike

  dp[i][t] = m;
  return m;
}

int main () {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> tw[i] >> mw[i] >> tb[i] >> mb[i];
  }

  cout << go(0, K);
  return 0;
}
