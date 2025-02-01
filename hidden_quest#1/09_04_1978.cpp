#include <bits/stdc++.h>
using namespace std;

int N, in, cnt, res;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> in;
    if (in < 2) continue;
    cnt = 0;
    for (int j = 2; j * j <= in; ++j) {
      if (in % j == 0) cnt++;
    }
    if (cnt == 0) res++;
  }
  cout << res;
  return 0;
}