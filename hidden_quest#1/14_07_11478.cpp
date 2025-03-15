#include <bits/stdc++.h>
using namespace std;

string S;
set<string> s;
int main () {
  cin >> S;
  for (int l = 1; l <= S.size(); ++l) {
    for (int i = 0; i <= S.size() - l; ++i) {
      // cout << S.substr(i, l) << "\n";
      s.insert(S.substr(i, l));
    }
  }
  cout << s.size();
  return 0;
}