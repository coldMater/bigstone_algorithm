// https://www.acmicpc.net/problem/16118
#include<bits/stdc++.h>
using namespace std;

int N, M;
int a, b, d;
int e[4001][4001];
long long d_fox[4001];
long long d_wolf[4001][2];
int INF = 987'654'321;
priority_queue<pair<long long, int>> pq_fox;
priority_queue<tuple<long long, int, int>> pq_wolf;
int main () {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> N >> M;

  fill(&e[0][0], &e[0][0] + 4001 * 4001, INF);
  fill(d_fox, d_fox + 4001, INF);
  fill(&d_wolf[0][0], &d_wolf[0][0] + 4001 * 2, INF);
  for (int i = 0; i < M; ++i) {
    cin >> a >> b >> d;
    e[a][b] = d * 2;
    e[b][a] = d * 2;
  }

  // fox's
  pq_fox.push({ 0, 1 });
  d_fox[1] = 0;

  while (!pq_fox.empty()) {
    int here = pq_fox.top().second;
    long long d_here = -pq_fox.top().first;
    pq_fox.pop();
    for (int next = 1; next <= N; ++next) {
      if (e[here][next] == INF) continue; // ⚠️ Without this line, TLE occurs.  (🚩 is more reasonable to use an adjacency list approach.)
      long long d_new = d_here + e[here][next];
      if (d_fox[next] > d_new) {
        pq_fox.push({ -d_new, next });
        d_fox[next] = d_new;
      }
    }
  }

  // wolf's
  pq_wolf.push({ 0, 1, 1 });
  d_wolf[1][1] = 0; // ⚠️ incorrect code: `d_wolf[1][0] = 0;`

  while (!pq_wolf.empty()) {
    int here = get<1>(pq_wolf.top());
    long long d_here = -get<0>(pq_wolf.top());
    int boost = get<2>(pq_wolf.top());
    pq_wolf.pop();
    if (d_here != d_wolf[here][boost]) continue;
    for (int next = 1; next <= N; ++next) {
      if (e[here][next] == INF) continue; // ⚠️ Without this line, TLE occurs.  (🚩 is more reasonable to use an adjacency list approach.)
      long long d_new = d_here + (boost ? e[here][next] / 2 : e[here][next] * 2);
      if (d_wolf[next][!boost] > d_new) {
        pq_wolf.push({ -d_new, next, !boost });
        d_wolf[next][!boost] = d_new;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (d_fox[i] < min(d_wolf[i][0], d_wolf[i][1])) ans++;
  }
  cout << ans;

  return 0;
}