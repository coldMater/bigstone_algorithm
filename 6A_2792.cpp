// https://www.acmicpc.net/problem/2792
#include <bits/stdc++.h>
using namespace std;

int N, M; // number of children, number of colors
int cs[300'000]; // each jewerl's count
int largest = 0;
int ans;
int main () {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> cs[i];
    largest = max(cs[i], largest);
  }

  int l = 1;
  int r = largest;
  // cout << "l: " << l << ", r: " << r << "\n";
  while (l <= r) {
    int mid = (l + r) / 2; // mid: jelousy point
    // cout << "mid: " << mid << "\n";
    int sc = 0;
    for (int i = 0; i < M; ++i) {
      sc += cs[i] / mid; // student count
      if (cs[i] % mid != 0) sc += 1; // when a remaining jewel exists
      // cout << "sc: " << sc << "\n";
    }
    if (sc > N) l = mid + 1; // the number of students exceeds the given student count (N); this jealousy point (mid) cannot be fulfilled.
    else if (sc <= N) {
      ans = mid;
      r = mid - 1;
    }
  }

  cout << ans;

  return 0;
}