// https://www.acmicpc.net/problem/1315
#include <bits/stdc++.h>
using namespace std;

int N;
int STR[50], INT[50], PNT[50];
int dp[1001][1001];
int go (int st, int in, long long f) {
  if (dp[st][in] != -1) return dp[st][in];
  int cnt = 0;
  int pn = 0;
  for (int i = 0; i < N; ++i) {
    if (st < STR[i] && in < INT[i]) continue;
    cnt++; // ❓ Why cnt++ before check visited? To count every quest that meets the condition.
    if (f & (1LL << i)) continue; // ⚠️ 64-bit long long literal: `ll` or `LL`
    f = f | (1LL << i);
    pn += PNT[i];
  }

  int mx = cnt;
  for (int pt_st = 0; pt_st <= pn && pn != 0; ++pt_st) {
    int pt_in = pn - pt_st;
    mx = max(mx, go(min(1000, st + pt_st), min(1000, in + pt_in), f));
  }

  dp[st][in] = mx;
  return mx;
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> STR[i];
    cin >> INT[i];
    cin >> PNT[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << go (1, 1, 0);

  return 0;
}

