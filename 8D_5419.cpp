// https://www.acmicpc.net/problem/5419
#include <bits/stdc++.h>
using namespace std;

int TC;
int n;
vector<pair<int, int>> c; // coordinates
int st[4 * 750'000]; // segment tree
long long ans;
bool ascByX_descByY(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return a.first < b.first; // Sort by x-coordinate in ascending order.
  if (a.second != b.second) return a.second > b.second; // Sort by y-coordinate in descending order.
  return false;
}


bool descByY (pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

// The largest y-coordinate is assigned to 0. (backward)
void compressY() {
  sort(c.begin(), c.end(), descByY);
  int pv = c[0].second; // previous value
  c[0].second = 0;
  int ci = 0; // zero(0): firstly compressed value of y-coordinates ()
  for (int i = 1 ; i < c.size(); ++i) {
    if (c[i].second == pv) {
      c[i].second = ci;
    } else {
      pv = c[i].second;
      c[i].second = ++ci;
    }
  }
}

// segement-tree update
void st_update(int sgNode, int l, int r, int i, int cnt) {
  // cout << sgNode << " " << l << " " << r << " " << i << " " << cnt << "\n";
  if (i < l || r < i) return;
  st[sgNode] = st[sgNode] + cnt;
  // cout << "st: " << st[sgNode] << "\n";

  if (l != r) {
    int mid = (l + r) / 2;
    st_update(sgNode * 2, l, mid, i, cnt);
    st_update(sgNode * 2 + 1, mid + 1, r, i, cnt);
  }
}

// segment-tree query
int st_query(int sgNode, int l, int r, int from, int to) {
  // cout << "l, r, f, t: " << l << " " << r  << " " << from << " " << to << " " << "\n";
  if (r < from || to < l) {
    // cout << "no match!\n";
    return 0;
  }
  if (from <= l && r <= to) {
    // cout << "match! return: " << st[sgNode] << " " << sgNode << "\n";
    return st[sgNode];
  }

  int mid = (l + r) / 2;
  int left = st_query(sgNode * 2, l, mid, from, to);
  int right = st_query(sgNode * 2 + 1, mid + 1, r, from, to);
  return left + right;
}

int main () {
  cin >> TC;
  for (int i = 0; i < TC; ++i) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x;
      cin >> y;
      c.push_back({ x, y });
    }

    compressY();

    // for (auto e : c) {
    //   cout << e.first << " " << e.second << "\n";
    // }
    // cout << "\n";

    sort(c.begin(), c.end());
    // for (auto e : c) {
    //   cout << e.first << " " << e.second << "\n";
    // }
    // cout << "\n";

    // for (int i = 1; i < c.size() * 4; ++i) {
    //   cout << st[i] << "-";
    //   if ((i & (i - 1)) == 0) cout << "\n"; // ⚠️ The equality operator (==) has higher precedence than the bitwise AND operator (&).
    // }
    // cout << "\n";
    for (auto e : c) {
      ans += st_query(1, 0, c.size() - 1, 0, e.second);
      // cout << "ans: " << ans << "\n";
      st_update(1, 0, c.size() - 1, e.second, 1);

      // for (int i = 1; i < c.size() * 4; ++i) {
      //   // cout << st[i] << " ";
      //   if (((i + 1) & (i + 1) - 1) == 0) cout << "\n"; // ⚠️ The equality operator (==) has higher precedence than the bitwise AND operator (&).
      // }
      // cout << "\n";
    }

    cout << ans << "\n";

    // int r = st_query(1, 0, c.size() - 1, 0, 3);
    // cout << "r: " << r;


    // for (auto e : c) {
    //   cout << e.first << " " << e.second << "\n";
    // }
    // cout << "\n";

    // sort(c.begin(), c.end(), compare);

    // cout << "begin\n";
    // for (auto e : c) {
    //   cout << e.first << " " << e.second << "\n";
    // }
    // cout << "end\n";

    // solution
    // 0. sort y-coords ascending, sort x-coords descending
    // 1. coordinate compression
    //    a. 💡 using binary search
    // 2. while sweeping, update the segment-tree and add to the answer
    // 3. print answer
    // 4. initialization
    c.clear();
    memset(st, 0, sizeof(st));
    ans = 0;
  }
}