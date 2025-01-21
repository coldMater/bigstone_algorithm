#include <bits/stdc++.h>
using namespace std;

int t;
int m = -1; // max
int y, x;
int M;
int main () {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      cin >> t;
      if (t > m) {
        m = t;
        y = i;
        x = j;
      }
    }
  }
  cout << m << "\n";
  cout << y << " " << x;

  return 0;
}