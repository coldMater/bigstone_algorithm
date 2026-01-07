// https://www.acmicpc.net/problem/17611
#include <bits/stdc++.h>
using namespace std;

int n;
int v[1'000'001], h[1'000'001];
int x, y;
vector<pair<int, int>> cs;
int main () {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    cs.push_back({ x, y });
  }

  cs.push_back({ cs.front().first, cs.front().second });

  for (int i = 1; i < n + 1; ++i) {
    int x_1 = cs[i - 1].first;
    int y_1 = cs[i - 1].second;
    int x_2 = cs[i].first;
    int y_2 = cs[i].second;

    if (x_1 == x_2) {
      int from = min(y_1, y_2);
      int to = max(y_1, y_2);
      for (int y = from; y < to; ++y) { // 🚩 explain why condition looks like `from <= y < to`
        v[y + 500'000]++;
      }
    }

    if (y_1 == y_2) {
      int from = min(x_1, x_2);
      int to = max(x_1, x_2);
      for (int x = from; x < to; ++x) {
        h[x + 500'000]++;
      }
    }

    x_1 = x_2; y_1 = y_2;
    continue;
  }

  int mx = 0;
  int my = 0;
  for (int i = 0; i < 1'000'001; ++i) {
    mx = max(mx, h[i]);
    my = max(my, v[i]);
  }
  cout << max(mx, my);
  return 0;
}