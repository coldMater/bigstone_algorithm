// https://www.acmicpc.net/problem/2240
#include <bits/stdc++.h>
using namespace std;

int T, W;
vector<int> fp; // fruit position
int dp[2][31][1000];
int go (int tn, int rmc, int t) { // tree number, remained move count, time
  if (dp[tn - 1][rmc][t] != -1) return dp[tn - 1][rmc][t];
  // cout << "t: " << t << "\n";
  // cout << "tn: " << t << "\n";
  if (t == T - 1) {
    return fp[t] == tn ? 1 : 0;
  }

  int changed = 0;
  if (rmc > 0) {
    changed = go(tn == 1 ? 2 : 1, rmc - 1, t + 1);
  }
  int unchanged = go(tn, rmc, t + 1);

  int result = (fp[t] == tn ? 1 : 0) + max(changed, unchanged);

  dp[tn - 1][rmc][t] = result;
  return result;
}

int main () {
  cin >> T >> W; // T: time, W: movable count

  memset(dp, -1, sizeof(dp));
  // cout << "last: " << dp[1][30][999] << "\n";

  for (int i = 0; i < T; ++i) {
    int temp;
    cin >> temp;
    fp.push_back(temp);
  }

  cout << max(go(1, W, 0), go(2, W - 1, 0)); // firstly, determine whether to change position or not.

  return 0;
}
