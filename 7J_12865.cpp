// https://www.acmicpc.net/problem/12865
#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
int dp[100'001];
int main () {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> W >> V;
    for (int j = K; j >= W; --j) { // 🤔 Why iterate backward (K to W) instead of forward (W to K)?  
      dp[j] = max(dp[j - W] + V, dp[j]);
      // cout << dp[j] << " ";
    }
    // for (int j = 0; j <= K; ++j) {
    //   cout << dp[j] << " ";
    // }
    // cout << "\n";
  }
  cout << dp[K];
  return 0;
}
