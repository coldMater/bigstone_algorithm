// https://www.acmicpc.net/problem/2884
#include <bits/stdc++.h>
using namespace std;

int H, M;
int main () {
  cin >> H >> M;
  int mins = H * 60 + M;
  mins += 60 * 24;
  mins -= 45;
  mins %= 60 * 24;
  cout << mins / 60 << " " << mins % 60;
  return 0;
}
