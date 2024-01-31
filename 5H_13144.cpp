// https://www.acmicpc.net/problem/13144
#include <bits/stdc++.h>
using namespace std;

int N, l, r; // given N, left, right
int c[100'001];
int n[100'001];
long long ret;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }

  int r = 0;
  int l = 0;
  while (r < N) {
    if (!c[n[r]]) { // Increase r until duplicate segments appear.
      c[n[r]]++;
      r++;
    } else { // If duplicate segments appear, add (r - l) to ret. In the segment [1(l), 2, 3, 1(r)], (r - l) represents the number of segments as follows: 1, 1-2, 1-2-3
      ret += r - l;
      c[n[l]]--;
      l++;
    }
  }
  while (l < N) {
    ret += r - l;
    l++;
  }

  cout << ret;

  return 0;
}