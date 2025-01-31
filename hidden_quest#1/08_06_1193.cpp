#include <bits/stdc++.h>
using namespace std;

int X;
void go (int x) {
  int n = sqrt(2 * (x - 1) + (1.0f / 4.0f)) + 0.5f; // n: diagonal index
  int d = n % 2; // direction (1: The direction in which the denominator increases)
  int s = (n * (n - 1)) / 2 + 1; // head of diagnal
  int diff = x - s;
  // cout << n << " " << d << " " << diff << " " << x << "(h: " << s << ")" << "\n";

  int numerator;
  int denominator;
  if (d == 1) {
    numerator = n - diff;
    denominator = 1 + diff;
  } else {
    numerator = 1 + diff;
    denominator = n - diff;
  }
  cout << numerator << "/" << denominator << "\n";
}

int main () {
  cin >> X;

  go(X);

  // for (int i = 1; i < 30; ++i) {
    // go(i);
  // }
  return 0;
}
