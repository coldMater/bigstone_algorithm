// https://www.acmicpc.net/problem/2562
#include <bits/stdc++.h>
using namespace std;

int temp, M, idx; // max
int main () {
  for (int i = 0 ; i < 9; ++i) {
    cin >> temp;
    if (temp > M) {
      M = temp;
      idx = i;
    }
  }
  cout << M << "\n" << idx + 1;
  return 0;
}
