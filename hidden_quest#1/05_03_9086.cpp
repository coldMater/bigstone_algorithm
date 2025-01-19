#include <bits/stdc++.h>
using namespace std;

int T;
string s;
int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> s;
    cout << s[0] << s[s.length() - 1] << "\n";
  }
  return 0;
}