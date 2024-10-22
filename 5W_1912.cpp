// https://www.acmicpc.net/problem/1912
#include <bits/stdc++.h>
using namespace std;

int n;
int ps[100'001]; // prefix sum
int main () {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int t; // temp
    cin >> t;
    ps[i] += ps[i - 1] + t;
  }

  int M = -1'987'654'321; //Max
  for (int interval = 1; interval <= n; ++interval) {
    for (int i = 1; i <= n; ++i) {
      int sum = ps[i] - ps[i - interval];
      M = max(M, sum);
    }
  }
  cout << M;
  return 0;
}
