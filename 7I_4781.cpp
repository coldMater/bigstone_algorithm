// https://www.acmicpc.net/problem/4781
#include <bits/stdc++.h>
using namespace std;

int n;
double m;
int dp[10'001];
int go(vector<pair<int, int>> cs, int rm) { // remained money
  if (rm < 0) return 0;

  int& dpv = dp[rm];
  if (dpv != -1) return dpv;
  dpv = 0;
  for (int i = 0; i < cs.size(); ++i) {
    int cal = cs[i].first;
    double price = cs[i].second;
    if (price <= rm) {
      int r = go(cs, rm - price) + cal;
      dpv = max(dpv, r);
    }
  }
  return dpv;
}

int main () {
  while (true) {
    cin >> n >> m;
    fill(dp, dp + 10'001, -1);
    if (n == 0 && m == 0) break;
    vector<pair<int, int>> candies;
    for (int i = 0; i < n; ++i) {
      int cal; // calorie
      double price; // price
      cin >> cal >> price;
      candies.push_back({ cal, (int)(price * 100) });
    }

    int totalCals = go(candies, (int)(m * 100));
    cout << totalCals << "\n";
  }

  return 0;
}

// 1st try: timeout (12%)