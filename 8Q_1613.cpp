// https://www.acmicpc.net/problem/1613
#include <bits/stdc++.h>
using namespace std;

int n, k, s;
int from, to;
int adj[401][401];
int INF = 987'654'321;

void print() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  cin >> n >> k;

  fill(&adj[0][0], &adj[0][0] + 401 * 401, INF);
  for (int i = 0; i < k; ++i) {
    cin >> from >> to;
    adj[from][to] = 1;
  }

  cin >> s;

  // print();

  for (int k = 1; k <= n; ++k) {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }

  // print();

  for (int i = 0; i < s; ++i) {
    cin >> from >> to;
    // cout << from << "->" << to << "\n";
    // cout << adj[from][to] << "\n";
    // cout << adj[to][from] << "\n";

    bool forward = adj[from][to] != INF;
    bool backward = adj[to][from] != INF;

    if (forward == false && backward == false) cout << 0 << "\n";
    if (forward == true && backward == false) cout << -1 << "\n";
    if (forward == false && backward == true) cout << 1 << "\n";
  }

  return 0;
}