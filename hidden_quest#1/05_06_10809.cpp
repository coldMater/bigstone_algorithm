#include <bits/stdc++.h>
using namespace std;

string s;
int main () {
  cin >> s;
  for (char a = 'a'; a <= 'z'; ++a) {
    bool found = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == a) {
        cout << i << " ";
        found = true;
        break;
      }
    }
    if (!found) {
      cout << -1 << " ";
    }
  }
  return 0;
}