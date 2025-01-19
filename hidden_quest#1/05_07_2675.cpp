#include <bits/stdc++.h>
using namespace std;

int T, R;
string s;
int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> R;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      for (int k = 0; k < R; ++k) {
        cout << s[j];
      }
    }
    cout << "\n";
  }
  return 0;
}