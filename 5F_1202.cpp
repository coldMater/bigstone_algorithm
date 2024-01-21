// https://www.acmicpc.net/problem/1202
#include <bits/stdc++.h>
using namespace std;

int N, K;
long long ret;
priority_queue<int> pq;
int main () {
  cin >> N >> K;
  vector<pair<int, int>> js(N); // jewels
  vector<int> bs(K); // bags
  for (int i = 0; i < N; ++i) {
    cin >> js[i].first >> js[i].second;
  }
  for (int i = 0; i < K; ++i) {
    cin >> bs[i];
  }

  sort(js.begin(), js.end());
  sort(bs.begin(), bs.end());

  int idx = 0;
  for (int i = 0; i < K; ++i) {
    while (idx < N && js[idx].first <= bs[i]) {
      pq.push(js[idx++].second);
    }
    if (pq.size()) {
      ret += pq.top();
      pq.pop();
    }
  }

  cout << ret;
  return 0;
}