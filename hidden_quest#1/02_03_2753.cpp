// https://www.acmicpc.net/problem/2753
#include <bits/stdc++.h>
using namespace std;

int y;
int main () {
  cin >> y;
  if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
    cout << 1;
  } else {
    cout << 0;
  }
  return 0;
}