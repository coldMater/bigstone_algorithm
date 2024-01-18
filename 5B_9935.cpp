// https://www.acmicpc.net/problem/9935
#include <bits/stdc++.h>
using namespace std;

string i;
string b;
int main () {
  cin >> i;
  cin >> b;

  string s;
  for (char c : i) {
    s += c;
    if (s.size() >= b.size() && s.substr(s.size() - b.size(), b.size()) == b) {
      // cout << s << "\n";
      s.erase(s.size() - b.size(), b.size());
      // cout << s << "\n";
    }
  }
  
  if (s.size() == 0) {
    cout << "FRULA";
  } else {
    cout << s;
  }
  return 0;
}