// https://www.acmicpc.net/problem/13244
#include<bits/stdc++.h>
using namespace std;

int T; // number of graphs to check
int N; // number of nodes in the graph, 1~1000, the identifier of each node will be an integer from 1 to N.
int M; // number of edges in the graph, at most 10^6 edges
int connected[1001][1001]; // edges
bool nodes[1001]; // nodes
bool visited[1001]; // nodes visited history
int a, b;
string result;
void bfs(int n) {
  visited[n] = true;

  for (int i = 1; i < 1001; ++i) {
    if (n == i) continue;
    if (visited[i]) continue;
    if (!connected[n][i]) continue;
    // cout << n << "->" << i << "\n";
    bfs(i);
  }
}

int main () {
  cin >> T;

  for (int j = 0; j < T; ++j) {
    cin >> N;
    cin >> M;

    result = "tree";
    for (int i = 0; i < M; ++i) {
      cin >> a >> b;
      connected[a][b]++;
      connected[b][a]++;
    }

    bfs(a);
    if (N - M != 1) {
      result = "graph";
    } else {
      for (int i = 1; i <= N; ++i) {
        if(!visited[i]) {
          result = "graph";
          break;
        }
      }
    }
    cout << result << "\n";

    fill(begin(nodes), end(nodes), 0);
    fill(begin(visited), end(visited), 0);
    fill(&connected[0][0], &connected[1000][1000], 0);
  }
}