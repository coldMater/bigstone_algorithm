// https://www.acmicpc.net/problem/17258
#include <bits/stdc++.h>
using namespace std;

int N, M, K, T;
int pp[301]; // people cnt at party
int dp[301][301];
vector<pair<int, int>> duration_cnt; // first: duration, second: count (number of people at the party for each duration)

int go (int n, int wf, int pf) { // wf: waiting friends, pf: Friends at the party
  if (n == duration_cnt.size()) return 0;

  // cout << "n: " << n << "\n";
  int & dpv = dp[n][wf];
  if (dpv) return dpv;

  int d = T - duration_cnt[n].second;  

  // All of youngsun's friends leave the party. However, the world-class remains at the party.
  if (d == 0) return dpv = go(n + 1, wf, 0) + duration_cnt[n].first;
  if (d <= pf) return dpv = go(n + 1, wf, pf) + duration_cnt[n].first;

  int as = d - pf; // as: available spot
  // Two options: 1. Invite friends to the party & 2. Do nothing

  int doNothing = go(n + 1, wf, pf);
  dpv = doNothing;
  if (wf - as >= 0) {
    int fill = go(n + 1, wf - as, pf + as) + duration_cnt[n].first;
    dpv = max(fill, dpv);
  }
  // else { // 🚩 This code does not need to be included. Explain why.
  //   dpv = max(go(n + 1, 0, pf + wf), dpv);
  //   // dpv = go(n + 1, 0, pf + wf); // Including this code will result in failure.
  // }

  return dpv;
}

int main () {
  cin >> N >> M >> K >> T;

  for (int i = 0; i < M; ++i) {
    int s, e;
    cin >> s >> e;
    for (int t = s; t < e; ++t) {
      pp[t] = min(pp[t] + 1, T); // optimization
      // pp[t]++;
    }
  }

  int duration = 1;
  int cnt = pp[1];
  for (int i = 2; i <= N; ++i) {
    if (cnt == pp[i]) {
      duration++;
    } else {
      duration_cnt.push_back({ duration, cnt });
      duration = 1;
      cnt = pp[i];
    }
  }
  duration_cnt.push_back({ duration, cnt });

  // for (auto dc : duration_cnt) {
  //   cout << dc.first << "," << dc.second << "\n";
  // }

  cout << go (0, K, 0);
  return 0;
}
