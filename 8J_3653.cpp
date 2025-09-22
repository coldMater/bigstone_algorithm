// https://www.acmicpc.net/problem/3653
#include <bits/stdc++.h>
using namespace std;

int N;
int n, m; // 1 <= n, m <= 100,000 (n: number of movies, number of movies that going to watch)
int fenwick_tree[200'010];
int MID = 100'001;
int TOP;
map<int, int> mpos; // Map for tracking the position of each movie

void update (int i, int v) {
  while (i <= 200'002) {
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
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // ⚠️ For large input/output. Omitting this line caused TLE.
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> n >> m;
    memset(fenwick_tree, 0, sizeof(fenwick_tree)); // ⚠️ initialization
    mpos.clear(); // ⚠️ Clear position map to avoid incorrect answers
    TOP = MID; // ⚠️ Reset TOP for each test case to prevent errors (especially TLE in this problem)

    // Set initial positions for all movies
    for (int mn = 1; mn <= n; ++mn) { // j: movie number
      mpos[mn] = MID + mn;
      update(mpos[mn], 1);
    }

    // Process movie watching sequence
    for (int k = 0; k < m; ++k) {
      int mn;
      cin >> mn;
      cout << query(mpos[mn] - 1) << " ";
      update(mpos[mn], -1);
      mpos[mn] = --TOP;
      update(mpos[mn], 1);
    }

    cout << "\n";
  }

  return 0;
}
