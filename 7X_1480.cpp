// https://www.acmicpc.net/problem/1480
#include <bits/stdc++.h>
using namespace std;

int N; // number of jewels N (1 <= N <= 13)
int M; // number of bags M (1 <= M <= 10)
int C; // maximum capacity of each bag (1 < C <= 20)
int js[13]; // weight of jewels (each element: 1 <= weight <= 20)
int bags[10];
int dp[10][1 << 13][21];

int go(int bn, int bm, int rc) { // bn: bag number, bm: bit masking, rc: remained capacity of bag
  if (bn == M) {
    return 0;
  }

  int& dpv = dp[bn][bm][rc];
  if (dpv) return dpv;

  int mx = 0;
  mx = max(mx, go (bn + 1, bm, C)); // the case that jump next bag without put jewel present bag

  for (int i = 0; i < N; ++i) {
    if (rc < js[i])  continue; // can't pack jewel in present bag
    if (bm & (1 << i)) continue; // i'th jewel is already packed in previous packing phase
    mx = max(mx, go(bn, bm | (1 << i), rc - js[i]) + 1);
  }

  dpv = mx;
  return mx;
}

int main () {
  cin >> N >> M >> C;

  for (int i = 0; i < N; ++i) {
    cin >> js[i];
  }

  cout << go (0, 0, C);
  return 0;
}