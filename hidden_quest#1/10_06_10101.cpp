#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main () {
  cin >> a >> b >> c;
  if (a + b + c != 180) {
    cout << "Error";
    return 0;
  }
  if (a == b && b == c) {
    cout << "Equilateral";
  }
  if ((a == b && b != c) || (a == c && b != c) || (b == c && a != b)) {
    cout << "Isosceles";
  }
  if (a != b && b != c && a != c) {
    cout << "Scalene";
  }
  return 0;
}