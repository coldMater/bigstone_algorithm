// https://www.acmicpc.net/problem/2618
#include <bits/stdc++.h>
using namespace std;
// p1: police car #1, p2: police car #2

int N, W, y, x;
pair<int, int> cases[1005]; // index: position number, [1]: p1's initial position, [2]: p2's initial position
int dp[1005][1005]; // dp[p1's Case Number][p2's Case Number]
int d (int hereCaseNum, int nextCaseNum) {
  pair<int, int> here = cases[hereCaseNum];
  pair<int, int> next = cases[nextCaseNum];
  return abs(here.first - next.first) + abs(here.second - next.second);
}

int go (int p1, int p2) { // p1: p1's position number, p2: p2's position number
  if (p1 == W + 2 || p2 == W + 2) return 0;

  if (dp[p1][p2]) return dp[p1][p2];
  int nextCaseNum = max(p1, p2) + 1;
  int left = go(nextCaseNum, p2) + d(p1, nextCaseNum); // when p1 process next case (number of nextCaseNum)
  int right = go(p1, nextCaseNum) + d(p2, nextCaseNum); // when p2 process next case (number of nextCaseNum)
  // cout << "p1, p2: " << p1 << ", " << p2 << "\n";
  // cout << "left: " << nextCaseNum << ", " << p2 << " - " << left << "\n";
  // cout << "right: " << p1 << ", " << nextCaseNum << " - " << right << "\n";

  return dp[p1][p2] = min(left, right);
}

int main () {
  cin >> N >> W;
  for (int i = 0; i < W; ++i) {
    cin >> y >> x;
    cases[i + 3] = { y, x };
  }

  cases[1] = { 1, 1 }; // p1's initial position
  cases[2] = { N, N }; // p2's initial position // ⚠️ wrong point: `cases[2] = { 6, 6 }`

  cout << go(1, 2) << "\n";

  int p1 = 1;
  int p2 = 2;
  int next = 3;
  while (next <= W + 2) {
    int p1Case = dp[next][p2] + d(p1, next);
    int p2Case = dp[p1][next] + d(p2, next);
    if (p1Case < p2Case) {
      cout << "1" << "\n";
      p1 = next;
    } else {
      cout << "2" << "\n";
      p2 = next;
    }
    next++;
  }
  return 0;
}