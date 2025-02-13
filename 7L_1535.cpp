// https://www.acmicpc.net/problem/1535
#include <bits/stdc++.h>
using namespace std;

int N;
int hp[20];
int dlpt[20]; // dlpt: delight point
int dp[100]; // index: hp, value: delight point
int main () {
  cin >> N;
  for (int i = 0; i  < N; ++i) {
    cin >> hp[i];
  }
  for (int i = 0; i  < N; ++i) {
    cin >> dlpt[i];
  }
  for (int i = 0; i < N; ++i) {
    int h = hp[i], d = dlpt[i];
    for (int j = 99; j >= h; --j) {
      dp[j] = max(dp[j], dp[j - h] + d);
    }
    // for (int j = 0; j <= 100; ++j) {
    //   cout << dp[j] << " ";
    // }
    // cout << "\n";
  }
  cout << dp[99];
  return 0;
}