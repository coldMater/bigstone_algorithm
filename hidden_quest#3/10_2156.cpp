#include <bits/stdc++.h>
using namespace std;

int n, t;
int dp[10'001];
int arr[10'001];
int main () {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  dp[1] = arr[1];
  dp[2] = arr[1] + arr[2];
  dp[3] = max({arr[1] + arr[2], arr[1] + arr[3], arr[2] + arr[3]});

  for (int i = 4; i <= n; ++i) {
    dp[i] = max({ dp[i - 1], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i] });
  }

  cout << dp[n];

  return 0;
}