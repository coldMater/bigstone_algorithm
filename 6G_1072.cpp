// https://www.acmicpc.net/problem/1072
#include <bits/stdc++.h>
using namespace std;

long long x, y;
int ans = 1'000'000'001;
int main () {
  cin >> x >> y;

  int iz = y * 100  / x; // initial Z
  int l = 0;
  int r = 1'000'000'000;
  while (l <= r) {
    int mid = (l + r) / 2;
    // cout << mid << " ";

    int z = (y + mid) * 100 / (x + mid);

    if (z == iz) {
      // no change, need to increase victory count(= mid)
      l = mid + 1;
    } else {
      // changed, need to find minimium victory count
      ans = mid;
      r = mid - 1;
    }
  }

  if (ans == 1'000'000'001) {
    cout << -1;
  } else {
    cout << ans;
  }
  return 0;
}