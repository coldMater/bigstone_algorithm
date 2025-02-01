#include <bits/stdc++.h>
using namespace std;

int a, b;
int main () {
  cin >> a >> b;
  while (a != 0 && b != 0) {
    if (b % a == 0) {
      cout << "factor\n";
    } else if (a % b == 0) {
      cout << "multiple\n";
    } else {
      cout << "neither\n";
    }
    cin >> a >> b;
  }
  return 0;
}