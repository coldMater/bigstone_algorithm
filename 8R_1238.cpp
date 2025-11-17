// https://www.acmicpc.net/problem/1238
#include <bits/stdc++.h>
using namespace std;

int N, M, X;
int from, to, cost;
int INF = 987'654'321;
vector<pair<int, int>> m[10'001];
int getMinCost (int from, int to) {
  int dist[10'001];
  fill(dist, dist + 10'001, INF);
  priority_queue<pair<int, int>> q;
  dist[from] = 0;
  q.push({ 0, from });
  while (!q.empty()) {
    int start = q.top().second; q.pop();

    // 🚩 TODO: something do not have to iterate
    for (auto nc : m[start]) {
      int next = nc.first;
      int cost = nc.second;
      if (dist[next] > dist[start] + cost) {
        dist[next] = dist[start] + cost;
        q.push({ -dist[next], next });
      }
    }
  }

  return dist[to];
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M >> X;
  for (int i = 0; i < M; ++i) {
    cin >> from >> to >> cost;
    m[from].push_back(make_pair(to, cost));
  }

  int mx = 0;
  for (int i = 1; i <= N; ++i) {
    if (i == X) continue;
    int go = getMinCost(i, X);
    int back = getMinCost(X, i); //🚩 TODO: can be stored
    mx = max(mx, go + back);
  }

  cout << mx;

  return 0;
}