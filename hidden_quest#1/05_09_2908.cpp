#include <bits/stdc++.h>
using namespace std;

int A, B;
int a, b;
int main () {
  cin >> A >> B;
  a += (A / 100);
  a += (A % 100) / 10 * 10;
  a += (A % 10) * 100;

  b += (B / 100);
  b += (B % 100) / 10 * 10;
  b += (B % 10) * 100;

  cout << max(a, b);
  return 0;
}