#include <bits/stdc++.h>
using namespace std;

int N, M;
int cards[100];
int res;
int main () {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> cards[i];
  }

  for (int i = 0; i < N - 2; ++i) {
    for (int j = i + 1; j < N - 1; ++j) {
      for (int k = j + 1; k < N; ++k) {
        int sum = cards[i] + cards[j] + cards[k];
        if (sum > M) continue;
        res = max(sum, res);
      }
    }
  }
  cout << res;
  return 0;
}