// https://www.acmicpc.net/problem/10952
#include <bits/stdc++.h>
using namespace std;

int A, B;
int main () {
  while (true) {
    cin >> A >> B;
    if (A == 0 && B == 0) break;
    cout << A + B << "\n";
  }
  return 0;
}