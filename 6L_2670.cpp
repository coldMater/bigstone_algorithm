// https://www.acmicpc.net/problem/2670
#include <bits/stdc++.h>
using namespace std;

int N;
float n[10'000];
float res;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }

  float s = n[0]; // serial multiplier
  res = s;
  for (int i = 1; i < N; ++i) {
    float next = s * n[i];
    if (n[i] > next) {
      s = n[i];
      // cout << "max: " << res << ", n[i]: " << n[i] << "\n";
    } else {
      s = next;
      // cout << "new: " << s << "\n";
    }
    res = max(res, s);
  }
  printf("%.3f", round(res*1000) / 1000);

  return 0;
}