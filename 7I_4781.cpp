// https://www.acmicpc.net/problem/4781
#include <bits/stdc++.h>
using namespace std;

int n;
double m;
int dp[10'001];

int main () {
  while (true) {
    cin >> n >> m;
    fill(dp, dp + 10'001, 0);
    if (n == 0 && m == 0) break;

    int cost = (int)(m * 100);
    for (int i = 0; i < n; ++i) {
      int cal; // calorie
      double price; // price
      cin >> cal >> price;
      int p = (int)(price * 100);
      for (int j = p; j <= cost; ++j) {
        dp[j] = max(dp[j], dp[j - p] + cal);
      }
    }

    cout << dp[cost] << "\n";
  }

  return 0;
}

// 1st try: timeout (12%)
// 2nd try: 87% -> rounding error
