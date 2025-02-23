#include <bits/stdc++.h>
using namespace std;

int N, in;
int c[10'001];
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> in;
    c[in]++;
  }
  for (int i = 1; i <= 10'000; ++i) {
    for (int j = 0; j < c[i]; ++j) {
      cout << i << "\n";
    }
  }
  return 0;
}