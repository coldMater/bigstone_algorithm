// https://www.acmicpc.net/problem/1094
#include <bits/stdc++.h>
using namespace std;

int X;
int res; // result
int main () {
  cin >> X;
  res = 0;
  for (int i = 0; i < 32; ++i) {
    if (X & (1 << i)) res++;
  }

  cout << res;
}
