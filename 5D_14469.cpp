// https://www.acmicpc.net/problem/14469
#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  vector<pair<int, int>> cows(N);
  for (int i = 0; i < N; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }

  sort(cows.begin(), cows.end());

  int t = cows[0].first + cows[0].second;
  for (int i = 1; i < N; ++i) {
    if (cows[i].first < t) {
      t += cows[i].second;
      continue;
    }
    if (cows[i].first == t) {
      t += cows[i].second;
      continue;
    }

    if (cows[i].first > t) {
      t = cows[i].first + cows[i].second;
      continue;
    }
  }

  cout << t;
  return 0;
}