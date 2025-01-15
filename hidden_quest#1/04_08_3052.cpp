// https://www.acmicpc.net/problem/3052
#include <bits/stdc++.h>
using namespace std;

int r[42], temp; // remainder
int main () {
  for (int i = 0; i < 10; ++i) {
    cin >> temp;
    r[temp % 42] = 1;
  }

  int sum = 0;
  for (int i = 0; i <= 41; ++i) {
    if (r[i]) sum += 1;
  }
  cout << sum;
  return 0;
}