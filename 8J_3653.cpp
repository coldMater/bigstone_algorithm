// https://www.acmicpc.net/problem/3653
#include <bits/stdc++.h>
using namespace std;

int N;
int n, m; // 1 <= n, m <= 100,000 (n: number of movies, number of movies that going to watch)
int fenwick_tree[200'010];
int MID = 100'000;
int TOP = 100'000;
map<int, int> mpos; // position map of the movies

void update (int i, int v) {
  while (i <= 200'001) {
    fenwick_tree[i] += v;
    i += (i & -i);
  }
}

int query (int i) {
  int sum = 0;
  while (i > 0) {
    sum += fenwick_tree[i];
    i -= (i & -i);
  }
  return sum;
}

int main () {
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> n >> m;

    // initial state
    for (int mn = 1; mn <= n; ++mn) { // j: movie number
      mpos[mn] = MID + mn;
      update(mpos[mn], 1);
    }

    // watching movies
    for (int k = 0; k < m; ++k) {
      int mn; // watched movie number
      cin >> mn;
      cout << query(mpos[mn] - 1) << " ";
      update(mpos[mn], -1);
      mpos[mn] = --TOP;
      update(mpos[mn], 1);
    }

    // TODO cleansing
    memset(fenwick_tree, 0, sizeof(fenwick_tree));
    cout << "\n";
  }

  return 0;
}
