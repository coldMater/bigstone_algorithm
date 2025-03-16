// https://www.acmicpc.net/problem/10942
#include <bits/stdc++.h>
using namespace std;

int N, M, S, E;
int str[2000];
int dp[2001][2001];

bool isPalindrome (int s, int e) {
  int ns = s, ne = e;

  while (ns < ne) {
    if (dp[ns][ne] != -1) {
      return dp[ns][ne];
    }
    if (str[ns - 1] == str[ne - 1]) {
      ns++;ne--;
      continue;
    }
    dp[s][e] = 0;
    return false;
  }
  while (s < e) { // If 987(12321)789 is a palindrome and (12321) is also a palindrome, then 87(12321)78 and 7(12321)7 are also palindromes.
    dp[s++][e--] = 1;
  }
  return true;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> str[i];
  }

  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> S >> E;
    cout << isPalindrome(S, E) << "\n";
  }
  return 0;
}