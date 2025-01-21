#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int n[26]; // idx: alphabet(0: 'a', 1: 'b'), value: position
int ret;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    memset(n, -1, sizeof(n));
    cin >> s;
    bool isGroup = true;
    for (int j = 0; j < s.length(); ++j) {
      int& prev = n[s[j] - 'a'];
      if (prev == -1) {
        prev = j;
        continue;
      }
      if (j - prev > 1) {
        isGroup = false;
        break;
      }
      prev = j;
    }
    if (isGroup) {
      // cout << i;
      ret++;
    }
  }
  cout << ret;
  return 0;
}