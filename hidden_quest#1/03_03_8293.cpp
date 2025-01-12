// https://www.acmicpc.net/problem/8393
#include <bits/stdc++.h>
using namespace std;

int n, sum;
int main () {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    sum += i;
  }
  cout << sum;
  return 0;
}