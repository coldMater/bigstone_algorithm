// https://www.acmicpc.net/problem/16118
#include<bits/stdc++.h>
using namespace std;

int N, M;
int a, b, d;
int e[4001][4001];
double d_fox[4001];
double d_wolf[4001];
double INF = 987'654'321;
priority_queue<pair<double, int>> pq;
int main () {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> N >> M;

  fill(&e[0][0], &e[0][0] + 4001 * 4001, INF);
  fill(d_fox, d_fox + 4001, INF);
  fill(d_wolf, d_wolf + 4001, INF);
  for (int i = 0; i < M; ++i) {
    cin >> a >> b >> d;
    e[a][b] = d * 2;
    e[b][a] = d * 2;
  }

  // fox's
  pq.push({ 0, 1 });
  d_fox[1] = 0;

  while (!pq.empty()) {
    int here = pq.top().second;
    int d_here = -pq.top().first;
    pq.pop();
    for (int next = 1; next <= 4000; ++next) {
      int d_new = d_here + e[here][next];
      if (d_fox[next] > d_new) {
        pq.push({ -d_new, next });
        d_fox[next] = d_new;
      }
    }
  }

  // wolf's
  pq.push({ 0, 1 });
  d_wolf[1] = 0;

  bool boost = true;
  while (!pq.empty()) {
    int here = pq.top().second;
    int d_here = -pq.top().first;
    pq.pop();
    for (int next = 1; next <= 4000; ++next) {
      double d_new = d_here + e[here][next] * (boost ? 0.5 : 2);
      if (d_wolf[next] > d_new) {
        pq.push({ -d_new, next });
        d_wolf[next] = d_new;
      }
    }
    boost = !boost;
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (d_fox[i] < d_wolf[i]) ans++;
  }
  cout << ans;

  return 0;
}