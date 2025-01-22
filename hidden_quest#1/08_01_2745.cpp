#include <bits/stdc++.h>
using namespace std;

string N;
int B;
int digits = 1;
int res;
int main () {
  cin >> N >> B;
  for (int i = N.length() - 1; i >= 0; --i) {
    // cout << "i: " << i << "\n";
    // cout << "digits: " << digits << "\n";
    char d = N[i];
    if (d <= '9') {
      res += (d - '0') * digits;
    }
    if (d >= 'A') {
      res += (d - 'A' + 10) * digits;
    }
    digits *= B;
  }

  cout << res;

  return 0;
}