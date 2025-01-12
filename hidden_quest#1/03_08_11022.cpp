// https://www.acmicpc.net/problem/11022
#include <bits/stdc++.h>
using namespace std;

int T;
int A, B;
int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> A >> B;
    cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << "\n";
  }
  return 0;
}