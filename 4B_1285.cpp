// https://www.acmicpc.net/problem/1285
#include <bits/stdc++.h>
using namespace std;

int N;
int r[20];
int fm = 987654321; //final minimum
void go (int here) {
  // cout << here << " " << N << "\n";
  if (here == N) {
    int m = 0; // mininum
    for (int i = 0; i < N; ++i) {
      int rc = 0;// count of T to row
      for (int j = 0; j < N; ++j) {
        if (r[j] & 1 << i) {
          rc++;
        }
      }
      // cout << "i: " << i << ":" << rc << "\n";
      m += min(N - rc, rc);
    }
    fm = min(fm, m);
    return;
  }
  r[here] = ~r[here];
  go(here + 1);
  r[here] = ~r[here];
  go(here + 1);
}

int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int c = 0;
    string s;
    cin >> s;
    for (int j = 0; j < N; ++j) {
      // THTT -> 1101 -> 13
      if (s[j] == 'T') {
        c += 1 << j; // c |= 1 << j;
      }
    }
    r[i] = c;
  }

  go (0);
  cout << fm;
  return 0;
}