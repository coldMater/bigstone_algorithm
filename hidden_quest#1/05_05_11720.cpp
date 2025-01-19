#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int res;
int main () {
  cin >> N;
  cin >> s;
  for (int i = 0; i < N; ++i) {
    res += s[i] - '0';
    // cout << res << "\n";
  }
  cout << res;
  return 0;
}