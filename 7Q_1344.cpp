// https://www.acmicpc.net/problem/1344
#include <bits/stdc++.h>
using namespace std;

double A, B;

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

  return go(gc + 1, d + 1, p) + go(gc, d + 1, p);
}

int main () {
  cin >> A >> B;

  // auto result = go(0, 1);
  // cout << result.first << " " << result.second;

  cout << 1. - (go(0, 1, A) * go (0, 1, B));
}