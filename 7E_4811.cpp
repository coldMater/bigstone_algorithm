// https://www.acmicpc.net/problem/4811
#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[31][31];
long long go (int w, int h, int d) {
  if (w == 0) {
    return 1;
  }

  long long& mem = dp[w][h];

  if (mem != -1) return mem;
  long long a = go(w - 1, h + 1, d + 1);
  long long b = h > 0 ? go(w, h - 1, d + 1) : 0;
  mem = a + b;

  // cout << "w,h: " << w << ", " << h << "(" << a << "," << b << ")\n";
  return mem;
}

int main () {
  memset(dp, -1, sizeof(dp));
  while (true) {
    cin >> N;
    if (N == 0) break;
    cout << go (N, 0, 0) << "\n";
  }

  return 0;
}