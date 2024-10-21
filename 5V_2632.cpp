// https://www.acmicpc.net/problem/2632
#include <bits/stdc++.h>
using namespace std;

int ans; // asnwer
int t; // target
int m, n;
int ps1[1000], ps2[1000]; // pieces1, pieces2
vector<int> c1; // combination of pieces1
vector<int> c2; // combination of pieces2
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
  c1.push_back(0);

  for (int i = 0; i < m; ++i) { // index of piece
    for (int j = 1; j < m; ++j) { // number of consecutive pieces
      int s = 0;
      for (int k = i; k < i + j; ++k) { // i: index, i + j: until this index
        s += ps1[k % m];
      }
      if (s > t) continue; // skip condition #1. if `s` is larger than the target.
      if (s == t) { // skip condition #2. if `s` is equal to the target (and add +1 to the answer).
        ans++;
        continue;
      }
      c1.push_back(s);
    }
  }

  // all pieces selected
  int s1 = 0;
  for (int i = 0; i < m; ++i) {
    s1 += ps1[i];
  }
  c1.push_back(s1);

  // for (int n : c1) {
  //   cout << n << " ";
  // }
  // cout << "\n";

  // COMBINATION OF PS2

  // no pieces selected
  c2.push_back(0);

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      int s = 0;
      for (int k = i; k < i + j; ++k) {
        s += ps2[k % n];
      }
      if (s > t) continue; // skip condition #1. if `s` is larger than the target.
      if (s == t) { // skip condition #2. if `s` is equal to the target (and add +1 to the answer).
        ans++;
        continue;
      }
      c2.push_back(s);
    }
  }


  // all pieces selected
  int s2 = 0;
  for (int i = 0; i < n; ++i) {
    s2 += ps2[i];
  }
  c2.push_back(s2);

  // for (int n : c2) {
  //   cout << n << " ";
  // }

  // cout << "\n";

  for (int l : c1) {
    for (int r : c2) {
      if (l + r == t) {
        ans += 1;
        // cout << "l: " << l << ", r: " << r << "\n";
      }
    }
  }

  cout << ans;

  return 0;
}