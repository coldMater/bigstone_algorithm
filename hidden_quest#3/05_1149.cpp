// https://www.acmicpc.net/problem/1149
#include <bits/stdc++.h>
using namespace std;

int N;
int r, g, b;
vector<vector<int>> cs;
int dp[1001][3];
int MAX = 987'654'321;
int go(int depth, int color) {
    if (depth == N) return 0;

    int &ret = dp[depth][color];
    if (ret != -1) return ret;

    ret = MAX;
    for (int nc = 0; nc < 3; nc++) {
        if (nc == color) continue;
        ret = min(ret, cs[depth][nc] + go(depth + 1, nc));
    }
    return ret;
}

int main () {
  cin >> N;

  fill(&dp[0][0], &dp[0][0] + 3 * 1001, -1);

  for (int i = 0; i < N; ++i) {
    cin >> r >> g >> b;
    cs.push_back({ r, g, b });
  }
  int mn = min(min(cs[0][0] + go(1, 0), cs[0][1] + go(1, 1)), cs[0][2] + go(1, 2));
  // min({})
  cout << mn << "\n";
  return 0;
}