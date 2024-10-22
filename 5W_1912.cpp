// https://www.acmicpc.net/problem/1912
#include <bits/stdc++.h>
using namespace std;

int n;
int ss; // serial sum
int M = -987654321; // max
int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t; // temp
    cin >> t;
    ss = max(ss + t, t);
    M = max(M, ss);
  }
  cout << M;

  return 0;
}
