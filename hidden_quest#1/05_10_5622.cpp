#include <bits/stdc++.h>
using namespace std;

string s;
int ret;
int main () {
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] <= 'R') {
      ret += (s[i] - 'A') / 3;
      ret += 3;
      continue;
    }
    if (s[i] == 'S') {
      ret += 8;
      continue;
    }
    if (s[i] >= 'T' && s[i] <= 'V') {
      ret += 9;
      continue;
    }
    if (s[i] >= 'W' && s[i] <= 'Z') {
      ret += 10;
      continue;
    }
  }
  cout << ret;

  return 0;
}
