// https://www.acmicpc.net/problem/14864
#include <bits/stdc++.h>
using namespace std;

int N, M;
int X, Y;
int n[100'001], v[100'001];
int main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    n[i] = i;
  }

  for (int i = 0; i < M; ++i) {
    cin >> X >> Y;
    n[X]++;
    n[Y]--;
  }

  for (int i = 1; i <= N; ++i) {
    if (++v[n[i]] >= 2) {
      cout << -1;
      return 0;
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << n[i] << " ";
  }

  return 0;
}