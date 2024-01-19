// https://www.acmicpc.net/problem/1781
#include <bits/stdc++.h>
using namespace std;

int N;
int main () {
  cin >> N;
  vector<pair<int, int>> ps(N); //problems
  for (int i = 0; i < N; ++i) {
    cin >> ps[i].first >> ps[i].second;
  }

  sort(ps.begin(), ps.end());

  priority_queue<int, vector<int>, greater<int>> pq; // number of cup ramen

  int submax = ps[0].second;
  for (int i = 1; i < N; ++i) {
    if (ps[i - 1].first == ps[i].first) {
      submax = max(submax, ps[i].second);
    } else {
      // cout << "submax: " << submax << "\n";
      pq.push(submax);
      submax = 0;
      while (pq.size() > ps[i - 1].first) {
        pq.pop();
      }
    }
  }
  submax = max(submax, ps[N - 1].second);
  // cout << "submax: " << submax << "\n";
  pq.push(submax);
  while (pq.size() > ps[N - 1].first) {
    pq.pop();
  }

  int ret;
  while (pq.size()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret;

  return 0;
}
