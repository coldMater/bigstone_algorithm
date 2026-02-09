// https://www.acmicpc.net/problem/11054
#include<bits/stdc++.h>
using namespace std;

int N, temp;
int arr[1000];
int dp[1000]; // LIS
int dp2[1000]; // LIS backward
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  // Forward LIS
  for (int i = 1; i < N; ++i) {
    int mx = -1;
    for (int j = 0; j < i; ++j) {
      if (arr[j] < arr[i]) {
        if (dp[j] > mx) { // ⚠️ You must compare dp itself. (Wrong): `arr[j] > mx`
          mx = dp[j];
          dp[i] = dp[j] + 1;
        }
      }
    }
  }

  // Backward LIS (Longest Decreasing Subsequence)
  for (int i = N - 2; i >= 0; --i) {
    int mx = -1;
    for (int j = N - 1; j > i; --j) {
      if (arr[j] < arr[i]) {
        if (dp2[j] > mx) { // ⚠️ Mistake: used `dp[j]` instead of `dp2[j]` when switching from `arr`
          mx = dp2[j];
          dp2[i] = dp2[j] + 1;
        }
      }
    }
  }

  int mx = 0;
  for (int i = 0; i < N; ++i) {
    mx = max(mx, dp[i] + dp2[i]);
  }
  cout << mx + 2 - 1; // `2`: When counting the element itself as a sequence, `1`: The element at the peak is counted in both increasing and decreasing subsequences
  return 0;
}