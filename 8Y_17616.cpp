// https://www.acmicpc.net/problem/17616
#include <bits/stdc++.h>
using namespace std;

vector<int> highRanks[100001];
vector<int> lowRanks[100001];
int N, M, X, A, B;
int visited[100001];
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M >> X;

  for (int i = 0; i < M; ++i) {
    cin >> A >> B;
    highRanks[B].push_back(A);
    lowRanks[A].push_back(B);
  }

  queue<int> q;
  int higherRankerCnt = 0;
  {
    q.push(X);
    visited[X] = 1;
    while (!q.empty()) {
      int here = q.front(); q.pop();
      // cout << "here: " << here << "\n";
      for (int next : highRanks[here]) {
        if (visited[next] == 1) continue;
        q.push(next);
        visited[next] = 1;
        higherRankerCnt++;
      }
    }
  }
  fill(visited, visited + N, 0);

  int lowerRankerCnt = 0;
  {
    q.push(X);
    visited[X] = 1;
    while (!q.empty()) {
      int here = q.front(); q.pop();
      // cout << "here: " << here << "\n";
      for (int next : lowRanks[here]) {
        if (visited[next] == 1) continue;
        q.push(next);
        visited[next] = 1;
        lowerRankerCnt++;
      }
    }
  }

  cout << higherRankerCnt + 1 << " " << N - lowerRankerCnt;

  return 0;
}