// https://www.acmicpc.net/problem/15684
#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int a, b;
int m[34][12];
int test[34][12];
vector<pair<int, int>> rungs;
vector<int> s;
bool flag = false;

void print () {
  for (int i = 1 ; i <= H; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << test[i][j] << " ";
    }
    cout << "\n";
  }
}

bool check() {
  for (int i = 1; i <= N; ++i) {
    int y = 1;
    int x = i;
    while (true) {
      if (y > H && i == x) break;
      if (y > H && i != x) return false;
      // cout << y << ":" << x << "\n";
      if (test[y][x] == 0) {
        y++;
        continue;
      }
      if (test[y][x] != 0) {
        int nextX = test[y][x];
        x = nextX;
        y++;
        continue;
      }
    }
  }
  return true;
}

void combi(int n, int r, int d, int start) {
  if (r == d) {
    memcpy(test, m, sizeof(int) * 12 * 32);
    // cout << "rungs: ";
    for (int cc : s) {
      // cout << rungs[cc].first << ":" << rungs[cc].second << " ";
      int y = rungs[cc].first;
      int x = rungs[cc].second;
      if (test[y][x] != 0 || test[y][x + 1] != 0) { 
        // cout << "Unavailable\n";
        return; 
      }
      test[y][x] = x + 1;
      test[y][x + 1] = x;
      // cout << y << ":" << x << " ";
    }
    // if (r == 1) {
    // cout << "\n";
    // print();
    // }
    if (check()) {
      flag = true;
    }
    return;
  }
  for (int i = start; i < n; ++i) {
    s.push_back(i);
    combi(n, r, d + 1, i + 1);
    s.pop_back();
  }
}

int main () {
  cin >> N >> M >> H;

  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    m[a][b] = b + 1;
    m[a][b + 1] = b;
  }

  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j < N; ++j) {
      if (m[i][j] == 0 && m[i][j + 1] == 0) {
        rungs.push_back({ i, j });
      }
    }
  }

  memcpy(test, m, sizeof(m));
  if (check()) {
    cout << 0;
    return 0;
  }
  for (int r = 1; r <= rungs.size(); ++r) {
    combi(rungs.size(), r, 0, 0);
    if (flag) {
      cout << r;
      return 0;
    }
  }
  cout << -1;

  return 0;
}
