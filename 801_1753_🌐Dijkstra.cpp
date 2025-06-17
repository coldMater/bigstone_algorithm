// https://www.acmicpc.net/problem/1753
#include <bits/stdc++.h>
using namespace std;

int V, E; // 1 <= V <= 20,000, 1 <= E <= 300,000
int K; // number of start node
vector<pair<int, int>> adj[20'001]; // adj[u]<v, w>
int u, v, w;
int dist[20'001];
int INF = 1'234'567'890;
priority_queue<pair<int, int>> pq; // <dist, idx>
int main () {
  cin >> V >> E;
  cin >> K;
  for (int i = 0; i < E; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  fill(dist, dist + V + 1, INF);

  dist[K] = 0;
  pq.push({0, K});
  while (pq.size()) {
    int here = pq.top().second;
    int d = -pq.top().first;
    pq.pop();

    // if (dist[here] < d) continue;  // Without this line, the problem still works, but this line is necessary to avoid redundant computations.
    for (pair<int, int> next : adj[here]) {
      int to = next.first; // v
      int weight = next.second; // w
      if (d + weight < dist[to]) {
        dist[to] = d + weight;
        pq.push({-dist[to], to});
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
