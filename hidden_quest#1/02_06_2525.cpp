// https://www.acmicpc.net/problem/2525
#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int main () {
  cin >> A >> B >> C;
  int mins = A * 60 + B;
  mins += 60 * 24;
  mins += C;
  mins %= 60 * 24;
  cout << mins / 60 << " " << mins % 60;
  return 0;
}
