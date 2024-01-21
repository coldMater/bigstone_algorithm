// https://www.acmicpc.net/problem/1931
#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;

  vector<pair<int, int>> ms(N); // meetings
  for (int i = 0; i < N; ++i) {
    cin >> ms[i].second >> ms[i].first;
  }

  sort(ms.begin(), ms.end());

  int end = ms[0].first;
  int ret = 1;
  for (int i = 1; i < N; ++i) {
    if (ms[i].second >= end) {
      end = ms[i].first;
      ret++;
    }
  }

  cout << ret;

  return 0;
}