// https://www.acmicpc.net/problem/1753
#include <bits/stdc++.h>
using namespace std;

int V, E; // 1 <= V <= 20,000, 1 <= E <= 300,000
int K; // number of start node
int adj[20'001][20'001];
int u, v, w;
int dist[20'001];
int INF = 1'234'567'890;
priority_queue<pair<int, int>> pq; // <dist, idx>
int main () {
  cin >> V >> E;
  cin >> K;
  for (int i = 0; i < E; ++i) {
    cin >> u >> v >> w;
    adj[u][v] = w;
    // cout << adj[u][v] << "\n";
  }

  fill(dist, dist + V + 1, INF);

  dist[1] = 0;
  pq.push({0, 1});
  while (pq.size()) {
    int here = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    for (int to = 1; to <= V; ++to) {
      if (adj[here][to] == 0 || to == here) continue;
      // cout << "here,to: " << here << "," << to << "\n";
      if (d + adj[here][to] < dist[to]) {
        dist[to] = d + adj[here][to];
        pq.push({dist[to], to});
      }
    }
  }

  for (int i = 1; i <= V; ++i) {
    if (dist[i] == INF) {
      cout << "INF" << "\n";
      continue;
    }
    cout << dist[i] << "\n";
  }
  return 0;
}
