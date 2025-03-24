// https://www.acmicpc.net/problem/1509
#include <bits/stdc++.h>
using namespace std;

string s;
int dp[2500][2500];
bool isPalindrome (int S, int E) {
  int l = S, r = E;
  while (l < r) {
    if (s[l++] != s[r--]) return false;
  }
  return true;
}

int go (int S, int E) {
  if (isPalindrome(S, E)) return 1;

  int &dpv = dp[S][E];

  if (dpv != 0) return dpv;

  dpv = 1'234'567'890;
  for (int i = S ; i < E; ++i) {
    dpv = min(dpv, go(S, i) + go(i + 1, E));
  }

  return dpv;
}

int main () {
  cin >> s;

  cout << go (0, s.length() - 1);
  return 0;
}
