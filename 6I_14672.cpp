// https://www.acmicpc.net/problem/14672
#include <bits/stdc++.h>
using namespace std;

int S, C;
int ss[1'000'000];
int ssM = 1'000'001; // min of ss
long long ans = 1'000'000'000'000'000LL;
int main () {
  cin >> S >> C;
  for (int i = 0; i < S; ++i) {
    cin >> ss[i];
    ssM = min(ssM, ss[i]);
  }

  // amount of green onions each chicken. (= mid)
  int l = 1;
  int r = ssM;

  // int temp = 20;
  while (l <= r) {
    long long mid = (l + r) / 2;
    // cout << mid << "\n";

    long long rem = 0; // remained
    long long cs = 0;
    for (int i = 0; i < S; ++i) {
      cs += ss[i] / mid;
      rem += ss[i] % mid;
    }

    // cout << cs << "\n";
    if (cs == 5) {
      ans = min(ans, rem);
      l = mid + 1;
    } else if (cs > 5) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << ans;

  return 0;
}