// https://www.acmicpc.net/problem/12852
#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1'000'001];
int path[1'000'001];
int go (int x) {
  if (x == 1) {
    return 0;
  }
  if (dp[x] > 0) return dp[x];

  dp[x] = 1'234'567'890;
  if (x % 3 == 0) {
    int c3 = go(x / 3) + 1;
    if (dp[x] > c3) {
      dp[x] = c3;
      path[x] = x / 3;
    }
  }
  if (x % 2 == 0) {
    int c2 = go(x / 2) + 1;
    if (dp[x] > c2) {
      dp[x] = c2;
      path[x] = x / 2;
    }
  }
  int c1 = go(x - 1) + 1;
  if (dp[x] > c1) {
    dp[x] = c1;
    path[x] = x - 1;
  }

  return dp[x];
}

int main () {
  cin >> N;

  int v = go(N);
  cout << v << "\n";
  int here = N;
  while (here > 0) {
    cout << here << " ";
    here = path[here];
  }
  return 0;
}