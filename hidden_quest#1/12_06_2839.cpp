#include <bits/stdc++.h>
using namespace std;

int N;
int mn = 1'234'567'890;
int main () {
  cin >> N;
  int fc = -1; // five count
  while (++fc * 5 <= N) {
    // cout << fc << "\n";
    int cnt = fc;
    int rem = N - (fc * 5);
    if (rem % 3 != 0) continue;
    cnt += rem / 3;
    mn = min(mn, cnt);
  }
  if (mn == 1'234'567'890) {
    cout << -1;
    return 0;
  }
  cout << mn;
  return 0;
}