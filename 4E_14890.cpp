// https://www.acmicpc.net/problem/14890
#include <bits/stdc++.h>
using namespace std;

int N, L;
int a[101][101];
int b[101][101]; // diagonally symmetrical of A
int answer;

void check (int m[101][101]) {
  for (int j = 0; j < N; ++j) {
    int cnt = 1;
    int i = 0;
    for (; i < N - 1; ++i) {
      int diff = m[j][i + 1] - m[j][i];
      if(diff == 0) {
        cnt++;
        continue;
      }
      if (diff == 1 && cnt >= L) {
        cnt = 1;
        continue;
      }
      if (diff == -1 && cnt >= 0) {
        cnt = -L + 1;
        continue;
      }
      break;
    }
    if (i == N - 1 && cnt >= 0) answer++;
  }
}

int main () {
  cin >> N >> L;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> a[i][j];
      b[j][i] = a[i][j];
    }
  }
  check(a);
  check(b);

  cout << answer << "\n";

  return 0;
}
