#include <bits/stdc++.h>
using namespace std;

int N, M, sum, m = 10'001;
int main () {
  cin >> N >> M;
  for (int i = max(N, 2); i <= M; ++i) {
    int cnt = 0;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) cnt++;
    }
    if (cnt == 0) {
      sum += i;
      m = min(m, i);
    }
  }
  if (m == 10'001) {
    cout << -1;
    return 0;
  }
  cout << sum << "\n";
  cout << m;
  return 0;
}
