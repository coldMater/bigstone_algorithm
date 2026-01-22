// https://www.acmicpc.net/problem/2579
#include <bits/stdc++.h>
using namespace std;

int n;
int stairs[301];
int dp[301];
int go (int step) { // memoization (top - down)
  if (step < 1) return 0;
  if (dp[step] != 0) return dp[step];
  int a = go(step - 3) + stairs[step - 1] + stairs[step];
  int b = go(step - 2) + stairs[step];

  return dp[step] = max(a, b);
}

int main () {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> stairs[i];
  }

  cout << go(n);
}