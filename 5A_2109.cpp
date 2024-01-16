// https://www.acmicpc.net/problem/2109
#include <bits/stdc++.h>
using namespace std;

int n;
int ret;
int main () {
  cin >> n;
  vector<pair<int, int>> dp(n); // day & price
  for (int i = 0; i < n; ++i) {
    cin >> dp[i].second >> dp[i].first;
  }

  sort(dp.begin(), dp.end()); // order by day

  int i = 0;
  priority_queue<int, vector<int>, greater<int>> prices;
  for (int d = 1; d <= 10'000; ++d) {
    while (i < n && dp[i].first == d) {
      prices.push(dp[i++].second);
    }
    while (prices.size() > d) {
      prices.pop();
    }
  }

  while (prices.size()) {
    // cout << prices.top() << "\n";
    ret += prices.top();
    prices.pop();
  }

  // // int sum = 0;
  // // for (int i = 1; i <= md; ++i) {
  //   // cout << "i: " << i << ", sum: " << sum << ", p: " << p[i] << "\n";
  //   // sum += p[i];
  // // }

  cout << ret;

  return 0;
}
