// https://www.acmicpc.net/problem/10810
#include <bits/stdc++.h>
using namespace std;

int N, M;
int b[100]; // baskets
int i, j, k;
int main () {
  cin >> N >> M;
  for (int x = 0; x < M; ++x) {
    cin >> i >> j >> k;
    for (int y = i; y <= j; ++y) {
      b[y - 1] = k;
    }
  }

  for (int x = 0; x < N; ++x) {
    cout << b[x] << " ";
  }
  return 0;
}