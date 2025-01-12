// https://www.acmicpc.net/problem/2480
#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main () {
  cin >> a >> b >> c;
  if (a == b && a == c) {
    cout << a * 1000 + 10000;
    return 0;
  }

  if (a != b && a != c && b != c) {
    cout << max(a, max(b,c)) * 100 << "\n";
    return 0;
  }

  int sn = 0;
  if (a == b && a != c) {
    sn = a;
  }
  if (a == c && a != b) {
    sn = a;
  }
  if (b == c && b != a) {
    sn = b;
  }
  cout << 1000 + sn * 100;

  return 0;
}