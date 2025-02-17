#include <bits/stdc++.h>
using namespace std;

int N;

int jariSum(int n) {
  int sum = 0; // ⚠️ caution: initialization
  int i = 10;
  while (true) {
    sum += n % i;
    n /= 10;
    if (n == 0) break;
  }
  return sum;
}

int main () {
  cin >> N;
  for (int i = 1; i < N; ++i) {
    int res = i + jariSum(i);
    if (res == N) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}