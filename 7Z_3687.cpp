// https://www.acmicpc.net/problem/3687
#include <bits/stdc++.h>
using namespace std;

//             0  1  2  3  4  5  6  7  8  9
int dm[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; // The array represents the matchstick count needed to form each digit, indexed by the digit.
int n, C;
string dp[101]; // In `string v = dp[n]`, n represents the number of matchsticks, and v represents the smallest number that can be formed using n matchsticks.

string getMinStr(string a, string b) {
  if (a.length() > b.length()) return b;
  else if (a.length() < b.length()) return a; // ⚠️ Initially, I missed this condition.

  for (int i = 0; i < a.length(); ++i) {
    if (a[i] < b[i]) return a;
    else if (a[i] > b[i]) return b;
  }
  return a; // b is also fine since a == b, so either can be returned.
}

string fmx(int c) {
  string res = "";
  if (c % 2 == 0) {
    res += "1";
    c -= 2;
  } else {
    res += "7";
    c -= 3;
  }

  while (c > 0) {
    res += "1";
    c -= 2;
  }

  return res;
}

string fmn(int c) {
  for (int i = 2; i <= c; ++i) {
    for (int j = 0; j <= 9; ++j) {
      int prev = i - dm[j];
      if (prev < 0 || prev == 1) continue;
      if (j == 0 && dp[prev] == "") continue;

      if (dp[i].empty()) {
        dp[i] = dp[prev] + to_string(j); // ⚠️ "Pay attention to the direction the number progresses.
      } else {
        dp[i] = getMinStr(dp[i], dp[prev] + to_string(j));
      }
    }
  }
  return dp[c];
}

int main () {
  cin >> n;

  dp[0] = "";
  dp[1] = "";
  // dp[2] = "1"; // dp[2] = "1" + dp[0] (The digit 1 requires 2 matchsticks.)
  // dp[3] = "7"; // dp[3] = "1" + dp[1] (The digit 1 requires 2 matchsticks.)
  // dp[4] = "4"; // dp[4] = "4" + dp[0] (`dp[4] = "1" + dp[2]` and `dp[4] = "7" + dp[1]` are also valid, but "4" is smallest among them.) 

  for (int i = 0; i < n; ++i) {
    cin >> C;
    cout << fmn(C);
    cout << " ";
    cout << fmx(C) << "\n";
  }
  return 0;
}