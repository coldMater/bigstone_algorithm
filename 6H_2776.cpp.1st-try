// https://www.acmicpc.net/problem/2776
#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int nn[1000000];
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    map<int, bool> m;
    for (int j = 0; j < N; ++j) {
      int temp;
      cin >> temp;
      m[temp] = true;
    }
    cin >> M;
    for (int j = 0; j < M; ++j) {
      cin >> nn[j];
    }
    for (int j = 0; j < M; ++j) {
      cout << m[nn[j]] << "\n";
    }
    memset(nn, 0, sizeof(nn));
  }
  return 0;
}