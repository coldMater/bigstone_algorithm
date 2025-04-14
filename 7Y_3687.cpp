// https://www.acmicpc.net/problem/3687
#include <bits/stdc++.h>
using namespace std;

int n, C;
//             0  1  2  3  4  5  6  7  8  9
int dm[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; // The array represents the matchstick count needed to form each digit, indexed by the digit.

string dp[101];

string fmx(int c) { // find maximum
  string str = "";
  if (c % 2 == 0) {
    str += "1"; 
    c -= 2;
  } else { 
    str += "7";
    c -= 3;
  }

  while (c > 0) {
    str += "1";
    c -= 2;
  }
  return str;
}

string getMinStr(string a, string b) {
  if (a.length() > b.length()) return b;

  for (int i = 0; i < a.length(); ++i) {
    if (a[i] == b[i]) continue;
    else if (a[i] < b[i]) return a;
    else return b;
  }

  return a; // a == b
}

// Top Down Solution
string fmn(int c) {
  if (c == 0) return "";

  if (!dp[c].empty())  return dp[c];
  string mnStr = "11111111111111111111111111111111111111111111111111"; // "1" x (100 / 2)
  for (int i = 0; i <= 9; ++i) {
    if (i == 0 && c == C) continue; // 💡 `dpeth == 0` can be checked without using the parameter `int d` (when c is not reduced)
    if (c - dm[i] >= 0) {
      string res = getMinStr(mnStr, to_string(i) + fmn(c - dm[i]));
      mnStr = res;
    }
  }

  dp[c] = mnStr;
  return mnStr;
}

int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> C;
    cout << fmn(C);
    cout << " ";
    cout << fmx(C) << "\n";
  }
  return 0;
}
