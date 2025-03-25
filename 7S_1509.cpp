// https://www.acmicpc.net/problem/1509
#include <bits/stdc++.h>
using namespace std;

string s;
int dp[2500][2501]; // 1st dimension: palindrome length, 2nd dimension: string index, value: whether it is a palindrome
int dp2[2500];

int go (int idx) {
  if (idx == s.length()) return 0;

  int &dpv = dp2[idx];
  if (dpv != -1) return dpv;

  int mn = 1'234'567'890;
  for (int len = 1; len <= s.length() - idx; ++len) {
    if (dp[len][idx]) {
      mn = min(mn, go(idx + len) + 1);
    }
  }

  dpv = mn;
  return mn;
}

int main () {
  cin >> s;

  memset(dp2, -1, sizeof(dp2));

  // Every single character is a palindrome
  for (int i = 0; i < s.length(); ++i) {
    dp[1][i] = 1;
    // cout << dp[1][i];
  }
  // cout << "\n";

  // Every two-character-string 
  for (int i = 0; i < s.length() - 1; ++i) {
    char fl = s[i]; // first letter
    char ll = s[i + (2 - 1)]; // last letter
    dp[2][i] = fl == ll;
    // cout << dp[2][i];
  }
  // cout << "\n";

  // Every three-character-string
  for (int i = 0; i < s.length() - 2; ++i) {
    char fl = s[i]; // first letter
    char ll = s[i + (3 - 1)]; // last letter
    bool isMiddleSectionPalindrome = dp[3 - 2][i + 1]; // Actually, this line is meaningless when the length is 3. Regardless of the middle section, when fl == ll, it is always a palindrome.
    dp[3][i] = (fl == ll) && isMiddleSectionPalindrome; // About every two-chracter-string 
    // cout << dp[3][i];
  }
  // cout << "\n";

  // Generalization (len >= 4)
  for (int len = 4; len <= s.length(); ++len) {
    for (int i = 0; i < s.length() - (len - 1); ++i) {
      char fl = s[i]; // first letter
      char ll = s[i + (len - 1)]; // last letter
      bool isMiddleSectionPalindrome = dp[len - 2][i + 1]; // Actually, this line is meaningless when the length is 3. Regardless of the middle section, when fl == ll, it is always a palindrome.
      dp[len][i] = (fl == ll) && isMiddleSectionPalindrome; // About every two-chracter-string 
      // cout << dp[len][i];
    }
    // cout << "\n";
  }

  cout << go(0);
  return 0;
}


// 1st attempt: TLE ⌛
// 2nd attempt:
// * Idea: Precompute the DP table first (not my idea)