// https://www.acmicpc.net/problem/2170
#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> ls[1'000'000]; // lines
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int l, r;
    cin >> l;
    cin >> r;
    ls[i] = {l, r};
  }

  sort(ls, ls + N);

  long sum = 0;
  int bl = ls[0].first;
  int br = ls[0].second;
  for (int i = 1; i < N; ++i) {
    int l = ls[i].first;
    int r = ls[i].second;
    if (r <= br) continue;
    if (l <= br) {
      br = r;
      continue;
    }
    if (l > br) {
      sum += br - bl;
      bl = l;
      br = r;
      continue;
    }
  }
  sum += br - bl;
  cout << sum;
  return 0;
}