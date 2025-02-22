#include <bits/stdc++.h>
using namespace std;

int N, k;
int n[1000];
int main () {
  cin >> N >> k;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }
  sort(n, n + N);
  cout << n[N - k];
  return 0;
}