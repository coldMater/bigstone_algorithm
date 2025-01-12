// https://www.acmicpc.net/problem/15552
#include <bits/stdc++.h>
using namespace std;

int T, A, B;
int main () {
  cin.tie(NULL);
  cin >> T;
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < T; ++i) {
    cin >> A >> B;
    cout << A + B << "\n";
  }
  return 0;
}
