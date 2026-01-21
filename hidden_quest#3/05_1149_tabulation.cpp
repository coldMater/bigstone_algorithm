// https://www.acmicpc.net/problem/1149
#include <bits/stdc++.h>
using namespace std;

int N;
int r, g, b;
vector<vector<int>> cs;
int dp[1001][3]; // 🚩 TODO: Reduce space complexity to O(1)
int main () {
  cin >> N;

  cin >> r >> g >> b;
  dp[0][0] = r;
  dp[0][1] = g;
  dp[0][2] = b;
  for (int i = 1; i < N; ++i) {
    cin >> r >> g >> b;
    dp[i][0] = r + min(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = g + min(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = b + min(dp[i - 1][0], dp[i - 1][1]);
  }

  cout << min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] }) << "\n";
  return 0;
}