// https://www.acmicpc.net/problem/10950
#include <bits/stdc++.h>
using namespace std;

int T, A, B;
int main () {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> A >> B;
    cout << A + B << "\n";
  }
  return 0;
}