#include <bits/stdc++.h>
using namespace std;

string s;
char n[10];
int main () {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> s;
  // cout << s << "\n";
  for (int i = 0; i < s.length(); ++i) {
    n[i]  = s[i];
  }
  sort(n, n + s.length()); // 🚩 range of sort (❌: n + s.length() - 1)
  for (int i = s.length() - 1; i >= 0; --i) {
    cout << n[i];
  }
  return 0;
}