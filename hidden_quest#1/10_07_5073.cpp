#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main () {
  while (true) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) break;

    int s[3] = {a, b, c}; // sides
    sort(s, s + 3);

    if (s[2] >= s[0] + s[1]) {
      cout << "Invalid\n";
      continue;
    }

    if (a == b && b == c) {
      cout << "Equilateral\n";
    }
    if ((a == b && b != c) || (a == c && b != c) || (b == c && a != c)) {
      cout << "Isosceles\n";
    }
    if (a != b && b != c && a != c) {
      cout << "Scalene\n";
    }
  }
}