// https://www.acmicpc.net/problem/1546
#include <bits/stdc++.h>
using namespace std;

int N;
double s[1000];
double M;
double res;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
    M = max(M, s[i]);
  }
  for (int i = 0; i < N; ++i) {
    res += s[i] / M * 100;
  }
  printf("%.3f", res / N);
  return 0;
}