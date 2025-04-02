// https://www.acmicpc.net/problem/2342
#include <bits/stdc++.h>
using namespace std;

int a[100'000];
int U = 1, L = 2, D = 3, R = 4;
int dp[100'000][5][5];

int cs(int o, int n) { // calculate strength, o: origin, n: next
  if (o == 0) return 2;
  int d = abs(o - n); // distance
  if (d == 0) return 1;
  if (d == 1 || d == 3) return 3;
  if (d == 2) return 4;
  throw "Error";
}

int INF = 1'234'567'890;
int go(int i, int l, int r) { // s: stamina? strength? anyway
  if (a[i] == 0) {
    return 0;
  }

  int & dpv = dp[i][l][r];
  if (dpv) return dpv;

  // move left foot
  int mn = INF;
  if (a[i] != r) {
    // cout << "i: " << i << ", move LEFT foot! " << l << "->" << a[i] << ", " << cs(l, a[i]) <<"\n";
    mn = min(mn, go (i + 1, a[i], r) + cs(l, a[i]));
  } else {
    // cout << "i: " << i << ", move LEFT XXX!\n";
  }

  // move right foot
  if (a[i] != l) {
    // cout << "i: " << i << ", move RIGHT foot! " << r << "->" << a[i] << ", " << cs(l, a[i]) << "\n";
    mn = min(mn, go (i + 1, l, a[i]) + cs(r, a[i]));
  } else {
    // cout << "i: " << i << ", move RIGHT XXX!\n";
  }

  dpv = mn;
  return mn;
}

int main () {
  int i = 0;
  while (true) {
    cin >> a[i];
    if (a[i] == 0) break;
    i++;
  }

  cout << go (0, 0, 0);

  return 0;
}
