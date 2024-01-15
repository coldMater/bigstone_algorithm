// https://www.acmicpc.net/problem/1931
#include <bits/stdc++.h>
using namespace std;

int N;
int ret = 1;
int main () {
  cin >> N;
  vector<pair<int, int>> ms(N); // meetings
  for (int i = 0; i < N; ++i) {
    cin >> ms[i].second >> ms[i].first;
  }
  sort(ms.begin(), ms.end());


  int beforeEnd = ms[0].first;
  for (int i = 1; i < N; ++i) {
    int nextStart = ms[i].second;
    if (beforeEnd <= nextStart) {
      ret++;
      beforeEnd = ms[i].first;
    }
  }
  // for (int i = 0; i < N; ++i) {
  //   cout << ms[i].second << " " << ms[i].first << "\n";
  // }
  cout << ret;
  return 0;
}