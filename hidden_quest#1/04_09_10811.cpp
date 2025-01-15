// https://www.acmicpc.net/problem/10811
#include <bits/stdc++.h>
using namespace std;


int N, M, i, j;
int b[100];
int main () {
  cin >> N >> M;
  for (int x = 0; x < N; ++x) {
    b[x] = x + 1;
  }

  for (int x = 0; x < M; ++x) {
    cin >> i >> j;
    int s = min(i, j) - 1; // start
    int e = max(i, j) - 1; // end
    for (int y = 0; y <= (e - s) / 2; ++y) {
      int temp = b[s + y];
      b[s + y] = b[e - y];
      b[e - y] = temp;
    }
  }

  for (int x = 0; x < N; ++x) {
    cout << b[x] << " ";
  }

  return 0;
}