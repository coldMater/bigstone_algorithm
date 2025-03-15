// https://www.acmicpc.net/problem/1344
#include <bits/stdc++.h>
using namespace std;

double A, B;
double dp[19][19];
bool isPrime(int gc) {
  if (gc == 0 || gc == 1) return false;
  for (int i = 2; i * i <= gc; ++i) {
    if (gc % i == 0) return false;
  }
  return true;
}

double pq(int gc, double p) {
  double gp = p / 100.;
  double ngp = 1. - gp;

  double res = 1;
  for (int i = 0; i < gc; ++i) {
    res *= gp;
  }
  for (int i = 0; i < 18 - gc; ++i) {
    res *= ngp;
  }
  return res;
}

double go (int gc, int d, double p) { // gc: goal count, d: depth(order of 5 minute interval), p: probability
  if (d > 18) {
    if (!isPrime(gc)) return pq(gc, p);
    return 0.;
  }
  double& ret = dp[gc][d];
  if (ret > -0.5) return ret;

  ret = go(gc + 1, d + 1, p) + go(gc, d + 1, p);
  return ret;
}

int main () {
  cin >> A >> B;

  // auto result = go(0, 1);
  // cout << result.first << " " << result.second;
  memset(dp, -1, sizeof(dp));
  double r1 = go(0, 1, A);
  memset(dp, -1, sizeof(dp));
  double r2 = go(0, 1, B);
  cout << 1. - (r1 * r2);
}