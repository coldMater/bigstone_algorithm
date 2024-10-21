// https://www.acmicpc.net/problem/2632
#include <bits/stdc++.h>
using namespace std;

int ans; // asnwer
int t; // target
int m, n;
int ps1[1004], ps2[1004]; // pieces1, pieces2
vector<int> c1; // combination of pieces1
vector<int> c2; // combination of pieces2

map<int, int> mm;

int main () {
  cin >> t;
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    cin >> ps1[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> ps2[i];
  }

  // COMBINATION OF PS1

  // no pieces selected
  mm[0]++;

  // n pieces selected
  for (int i = 0; i < m; ++i) { // index of piece
    int s = 0;
    for (int j = 1; j < m; ++j) { // number of consecutive pieces
      s += ps1[(i + j) % m]; // prefix sum
      if (s > t) break;
      mm[s]++;
    }
  }

  // all pieces selected
  int s1 = 0;
  for (int i = 0; i < m; ++i) {
    s1 += ps1[i];
  }
  mm[s1]++;

  // COMBINATION OF PS2

  // no pieces selected
  ans += mm[t - 0];

  // n pieces selected
  for (int i = 0; i < n; ++i) {
    int s = 0;
    for (int j = 1; j < n; ++j) {
      s += ps2[(i + j) % n];
      if (s > t) break;
      ans += mm[t - s];
    }
  }

  // all pieces selected
  int s2 = 0;
  for (int i = 0; i < n; ++i) {
    s2 += ps2[i];
  }
  ans += mm[t - s2];

  cout << ans;

  return 0;
}