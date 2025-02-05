// https://www.acmicpc.net/problem/2294
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> cs; // coins
int INF = 1'234'567'890;
int dp[10'001];
int go (int v) { // value
  // cout << "f: " << v << "\n";
  if (v < 0) {
    return INF;
  }

  if (v == 0) {
    return 0;
  }

  int& dpv = dp[v];
  if (dpv) return dpv;

  int mn = INF;
  for (int c : cs) {
    mn = min(mn, go(v - c));
  }

  dpv = mn + 1;
  return dpv;
}

int main () {
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    cs.push_back(temp);
    // cout << cs.back() << "\n";
  }

  // ❌1st try: fail
  // cout << go(k);

  // 2nd try
  int res = go(k);
  if (res >= INF) cout << -1;
  else cout << res;
  return 0;
}