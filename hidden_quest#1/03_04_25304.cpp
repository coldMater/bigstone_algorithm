// https://www.acmicpc.net/problem/25304
#include <bits/stdc++.h>
using namespace std;

int X, N;
int a, b;
int sum;
int main () {
  cin >> X >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a >> b;
    sum += a * b;
  }
  if (X == sum) cout << "Yes";
  else cout << "No";
  return 0;
}