#include <bits/stdc++.h>
using namespace std;

string s;
int a[26];
int m1, m2, i1, i2;
int main () {
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] <= 'Z') a[s[i] - 'A']++;
    if (s[i] >= 'a') a[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; ++i) {
    if (m1 < a[i]) {
      m1 = a[i];
      i1 = i;
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (i == i1) continue;
    if (m2 < a[i]) {
      m2 = a[i];
      i2 = i;
    }
  }

  if (m1 == m2) cout << '?';
  else cout << (char)(i1 + 'A');
  return 0;
}
