// https://www.acmicpc.net/problem/2776
#include <bits/stdc++.h>
using namespace std;

int T, N, M;
map<int, bool> m;
int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    for (int j = 0; j < N; ++j) {
      int temp;
      cin >> temp;
      m[temp] = true;
    }
    cin >> M;
    for (int j = 0; j < M; ++j) {
      int temp;
      cin >> temp;
      cout << m[temp] << "\n";
    }
  }
  return 0;
}