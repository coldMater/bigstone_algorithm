// https://www.acmicpc.net/problem/6236
#include <bits/stdc++.h>
using namespace std;

int N, M;
int ps[100'000];
int se = 1'987'654'321; // smallest expenditure
int ans = 1'987'654'321;
int main () {
  cin >> N >> M;

  int te = 0; // total expenditure
  for (int i = 0; i < N; ++i) {
    cin >> ps[i];
    se = min(se, ps[i]);
    te += ps[i];
  }

  int l = se;
  int r = te;

  while (l <= r) {
    int K = (l + r) / 2; // Withdrawal amount (referred to as K in the problem)

    int wc = 0; // withdrawal count
    int wallet = 0;
    for (int i = 0; i < N; ++i) {
      int de = ps[i]; // daily expenditure

      // withdrawal
      if (de > wallet) {
        wallet = K;
        wc++;
      }
      wallet -= de;
    }
    // cout << "K: " << K << ", wc: " << wc << "\n";
    if (wc > M) { // Withdrawal count(=M) is too high. Need to increase withdrawal amount (=K).
      l = K + 1;
    } else {
      r = K - 1;
      ans = min(ans, K);
    }
  }

  cout << ans;

  return 0;
}