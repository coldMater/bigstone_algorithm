#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main () {
  cin >> a >> b >> c;
  int s[3] = { a, b, c };
  sort(s, s + 3);
  if (s[2] < s[0] + s[1]) {
    cout << s[0] + s[1] + s[2];
  } else {
    cout << (s[0] + s[1]) * 2 - 1;
  }
  return 0;
}
