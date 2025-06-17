// https://www.acmicpc.net/problem/11404
#include <bits/stdc++.h>
using namespace std;

int n, m; // n: number of cities, m: number of buses
int a, b, c; // a: from, b: to, c: fare
int adj[101][101];
int INF = 987'654'321; // ⚠️ INF should be set so that the result of INT + INT does not exceed the range of an integer. e.g., 1234567890 (x), 987654321 (o)
int main () {
  cin >> n >> m;
  fill(&adj[0][0], &adj[0][0] + (101 * 101), INF); // 💡 Initializing 2D Array
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    adj[a][b] = min(adj[a][b], c);
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     if (adj[i][j] == INF) cout << 0 << " ";
  //     else cout << adj[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  for (int k = 1; k <= n; ++k) { // ⚠️ order of iteration (k -> i or j)
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        // cout << "adj " << i << " " << j << " " << adj[i][j] << "\n";
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j || adj[i][j] == INF) cout << 0 << " ";
      else cout << adj[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
