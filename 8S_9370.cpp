// https://www.acmicpc.net/problem/9370
#include <bits/stdc++.h>
using namespace std;

int cases;
int n, m, t;
int s, g, h;
int a, b, d;
int targets[100];
int INF = 987'654'321;
vector<pair<int, int>> adj[50'000];

void dijkstra(int from, int dist[2'001]) {
  fill(dist, dist + 2001, INF);
  priority_queue<pair<int, int>> pq;

  dist[from] = 0;
  pq.push(make_pair(0, from));

  while (!pq.empty()) {
    int here = pq.top().second;
    pq.pop();
    for (auto nc : adj[here]) {
      int next = nc.first;
      int cost = nc.second;
      if (dist[next] > dist[here] + cost) {
        dist[next] = dist[here] + cost;
        pq.push(make_pair(-dist[next], next));
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> cases;
  while (cases--) {
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    int dist_g_h;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> d;
      adj[a].push_back(make_pair(b, d));
      adj[b].push_back(make_pair(a, d)); // ⚠️ Every road is bidirectional.
    }
    for (int i = 0; i < t; ++i) {
      cin >> targets[i];
    }

    int s_to[2'001]; // s_to[t]: min distance from s to t
    int g_to[2'001]; // g_to[t]: min distance from h to t
    int h_to[2'001]; // h_to[t]: min distance from h to t
    dijkstra(s, s_to);
    dijkstra(g, g_to);
    dijkstra(h, h_to);

    sort(targets, targets + t);
    for (int i = 0; i < t; ++i) {
      int target = targets[i];

      bool throughGH = s_to[target] == (s_to[g] + g_to[h] + h_to[target]);
      bool throughHG = s_to[target] == (s_to[h] + h_to[g] + g_to[target]);

      if (throughGH || throughHG) cout << target << " ";
    }
    cout << "\n";

    // Initialization
    for (int i = 0; i < 50'000; ++i) {
      adj[i].clear();
    }
  }

  return 0;
}