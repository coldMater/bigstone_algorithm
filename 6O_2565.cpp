// https://www.acmicpc.net/problem/2565
#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> ls[500]; // lines
int dp[500]; // memoize ith line's count of LIS
int lis_len;
int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> ls[i].first;
    cin >> ls[i].second;
  }

  sort(ls, ls + n);
  // cout << "sort: \n";
  // for (int i = 0; i < n; ++i) {
  //   cout << ls[i].first << ", " << ls[i].second << "\n";
  // }

  // cout << "\n";
  for (int i = 1; i < n; ++i) {
    for (int j = 0 ; j < i; ++j) {
      // cout << i << "," << j << ": "<< dp[i] << "," << dp[j] << "\n";
      if (ls[i].second > ls[j].second) {
        int len = dp[j] + 1;
        if (dp[i] < len) {
          dp[i] = len;
          lis_len = max(lis_len, dp[i]);
        }
        // cout << "dp[i]: " << dp[i] << "\n";
        // cout << "lis_len: " << lis_len << "\n";
      }
    }
  }

  cout << n - (lis_len + 1);

  return 0;
}