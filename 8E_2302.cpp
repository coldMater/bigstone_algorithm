// https://www.acmicpc.net/problem/2302
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> vips;
int dp[41];
int go (int s) {
  if (s == 0) return 1; // ⚠️ Without this line, it may cause an out-of-bounds error.
  if (s == 1) return 1;
  if (s == 2) return 2;

  if (dp[s]) return dp[s];
  return dp[s] = go (s - 1) + go (s - 2);
}

int main () {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int temp;
    cin >> temp;
    vips.push_back(temp);
  }

  int ans = 1; // 1: Initial value of the product
  int start = 0;
  int end = 0;
  for (int vip : vips) {
    start = end;
    end = vip;
    // cout << "s, e: " << start << " " << end << "\n";
    int seatsCnt = end - start - 1; // number of seats arranged in a row (excluding VIP seats)
    ans *= go(seatsCnt);
    // cout << "ans: " << ans << "\n";
  }
  if (end != N + 1) {
    start = end;
    end = N + 1;
    // cout << "s, e: " << start << " " << end << "\n";
    int seatsCnt = end - start - 1;
    ans *= go(seatsCnt);
    // cout << "ans: " << ans << "\n";
  }

  cout << ans;
}