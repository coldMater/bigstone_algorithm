// https://www.acmicpc.net/problem/10942
#include <bits/stdc++.h>
using namespace std;

int N, M, S, E;
int str[2000];

bool isPalindrome (int s, int e) {
  while (s < e) {
    if (str[s - 1] == str[e - 1]) {
      s++;e--;
      continue;
    }
    return false;
  }
  return true;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

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