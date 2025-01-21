#include <bits/stdc++.h>
using namespace std;

string s;
int res;
int main () {
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (
      (s[i] == 'c' && s[i + 1] == '=') ||
      (s[i] == 'c' && s[i + 1] == '-') ||
      (s[i] == 'd' && s[i + 1] == '-') ||
      (s[i] == 'l' && s[i + 1] == 'j') ||
      (s[i] == 'n' && s[i + 1] == 'j') ||
      (s[i] == 's' && s[i + 1] == '=') ||
      (s[i] == 'z' && s[i + 1] == '=')
    ){
      res++;
      i++;
      continue;
    }
    if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
      res++;
      i += 2;
      continue;
    }
    res++;
  }
  cout << res;

  return 0;
}