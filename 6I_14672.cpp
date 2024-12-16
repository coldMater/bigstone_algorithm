// https://www.acmicpc.net/problem/14672
#include <bits/stdc++.h>
using namespace std;

int S, C;
int ss[1'000'000];
long long ans;
int main () {
  cin >> S >> C;
  long long sum = 0;
  for (int i = 0; i < S; ++i) {
    cin >> ss[i];
    sum += ss[i];
  }

  // amount of green onions each chicken. (= mid)
  int l = 1;
  int r = 1'000'000'000;

  // int temp = 20;
  while (l <= r) {
    long long mid = (l + r) / 2;
    // cout << "l, r, mid: " << l << "," << r << "," << mid << "\n";

    long long cs = 0;
    for (int i = 0; i < S; ++i) {
      cs += ss[i] / mid;
    }

    // cout << cs << "\n";
    if (cs >= C) {
      ans = mid; // 🤔 Consider why min or max might not be necessary.
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << sum - (ans * C);

  return 0;
}