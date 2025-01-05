// https://www.acmicpc.net/problem/11053
#include <bits/stdc++.h>
using namespace std;

int N;
int n[1'000];
int c[1'000];
int res;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (n[j] < n[i] && c[i] < c[j] + 1) {
        c[i] = c[j] + 1;
        res = max(res, c[i]);
      }
    }
  }
  // for (int i = 0; i < N; ++i) {
  //   cout << c[i] << " ";
  // }
  // cout << "\n";
  cout << res + 1;
  return 0;
}
