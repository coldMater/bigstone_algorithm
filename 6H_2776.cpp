// https://www.acmicpc.net/problem/2776
#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int n1[1000000];
int check (int t) {
  int l = 0;
  int r = N - 1;
  while (l <= r) {
    int m = (l + r) / 2;

    if (n1[m] < t) {
      l = m + 1;
    } else if (n1[m] > t) {
      r = m - 1;
    } else {
      return 1;
    }
  }
  return 0;
}
int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    map<int, bool> m;
    for (int j = 0; j < N; ++j) {
      scanf("%d", n1 + j);
    }
    sort(n1, n1 + N);
    cin >> M;
    for (int j = 0; j < M; ++j) {
      int temp;
      scanf("%d", &temp);
      cout << check(temp) << "\n";
    }
  }
  return 0;
}