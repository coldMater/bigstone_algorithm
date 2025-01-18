// https://www.acmicpc.net/problem/2098
#include <bits/stdc++.h>
using namespace std;

int N;
int cm[16][16]; // cost matrix
int visited[16];
int INF = 1'234'567'890;
int dp[16][1 << 16];
int go (int cn, int visited) { // city number
  // cout << bitset<16>(visited) << "\n";
  if (visited == (1 << N) - 1) {
    return cm[cn][0] == 0 ? INF : cm[cn][0];
  }


  if (dp[cn][visited] != -1) return dp[cn][visited];
  int m = 1'234'567'890;
  for (int i = 0; i < N; ++i) {
    // cout << i << "\n";
    if (visited & (1 << i)) continue;
    if (cm[cn][i] == 0) continue;
    m = min(m, cm[cn][i] + go(i, visited | (1 << i)));
  }
  dp[cn][visited] = m;
  return m;
}

int main () {
  // cout << (2 << 16);
  memset(dp, -1, sizeof(dp));
  cin >> N;
  for (int i = 0 ; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> cm[i][j];
    }
  }

  cout << go (0, 1);

  return 0;
}

// 10
// 0 1 1 1 1 1 1 1 1 1
// 1 0 1 1 1 1 1 1 1 1
// 1 1 0 1 1 1 1 1 1 1
// 1 1 1 0 1 1 1 1 1 1
// 1 1 1 1 0 1 1 1 1 1
// 1 1 1 1 1 0 1 1 1 1
// 1 1 1 1 1 1 0 1 1 1
// 1 1 1 1 1 1 1 0 1 1
// 1 1 1 1 1 1 1 1 0 1
// 1 1 1 1 1 1 1 1 1 0