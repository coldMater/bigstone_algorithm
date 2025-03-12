#include <bits/stdc++.h>
using namespace std;

int N, M;
set<string> s;
int main () {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string temp;
    cin >> temp;
    s.insert(temp);
  }

  int cnt = 0;
  for (int i = 0; i < M; ++i) {
    string temp;
    cin >> temp;
    if (s.find(temp) != s.end()) cnt++;
  }

  cout << cnt;
  return 0;
}