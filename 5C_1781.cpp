// https://www.acmicpc.net/problem/1781
#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  vector<pair<int, int>> ps(N); //problems
  for (int i = 0; i < N; ++i) {
    cin >> ps[i].first >> ps[i].second; // first: deadline, second: number of cup ramen 
  }

  sort(ps.begin(), ps.end());

  priority_queue<int, vector<int>, greater<int>> pq; // number of cup ramen
  
  for (int i = 0; i < N; ++i) {
    pq.push(ps[i].second);
    while (pq.size() > ps[i].first) {
      pq.pop();
    }
  }

  int ret = 0; // ☠️ overlooked element: initialization `int ret;`
  while (pq.size()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret;

  return 0;
}
