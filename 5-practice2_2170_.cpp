// https://www.acmicpc.net/problem/
#include <bits/stdc++.h>
using namespace std;

int N;
int ret;
int main () {
  cin >> N;
  vector<pair<int, int>> lines(N);
  for (int i = 0; i < N; ++i) {
    cin >> lines[i].first >> lines[i].second;
  }
  sort (lines.begin(), lines.end());

  int left = lines[0].first;
  int right = lines[0].second;
  for (int i = 1; i < N; ++i) {
    int nextLeft = lines[i].first;
    int nextRight = lines[i].second;
    if (right >= nextLeft) {
      right = nextRight;
      continue;
    } else if (right < nextLeft) {
      ret += right - left;
      left = nextLeft;
      right = nextRight;
    }
  }
  ret += right - left;
  cout << ret;

  return 0;
}