#include <bits/stdc++.h>
using namespace std;

int T, C;
int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> C;

    cout << C / 25 << " ";  // Quarter
    C %= 25;
    cout << C / 10 << " "; // Dime
    C %= 10;
    cout << C / 5 << " "; // Nickel
    C %= 5;
    cout << C << "\n"; // Penny
  }
  return 0;
}