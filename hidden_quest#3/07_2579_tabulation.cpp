// https://www.acmicpc.net/problem/2579
#include <bits/stdc++.h>
using namespace std;

int n;
int stairs[301];
int step[301];
int main () {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> stairs[i];
  }

  step[1] = stairs[1];
  step[2] = stairs[1] + stairs[2];
  step[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
  for (int i = 4; i <= n; ++i) {
    step[i] = max(step[i - 3] + stairs[i - 1] + stairs[i], step[i - 2] + stairs[i]);
  }

  cout << step[n];
}