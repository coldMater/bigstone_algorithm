#include <bits/stdc++.h>
using namespace std;

string s;
char m[5][15];
int main () {
  for (int i = 0; i < 5; ++i) {
    cin >> s;
    for (int j = 0; j < s.length(); ++j) {
      m[i][j] = s[j];
    }
  }

  for (int x = 0; x < 15; ++x) {
    for (int y = 0; y < 5; ++y) {
      char& num = m[y][x];
      if (num == 0) continue;
      cout << num;
    }
  }

  return 0;
}