```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
vector<int> segment_tree;

int init(int node, int start, int end) {
  if (start == end) {
    return segment_tree[node] = arr[start];
  }

  int mid = (start + end) / 2;
  segment_tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
  return segment_tree[node];
}
```

```cpp
// 🚩 retry implementation
void update (int target, int adder, int node, int left, int right) {
  if (target < left || right < target) return;
  segment_tree[node] += adder;

  if (left == right) return;

  int mid = (left + right) / 2;
  update(target, adder, node * 2, left, mid);
  update(target, adder, node * 2 + 1, mid + 1, right);
}

int query (int node, int left, int right, int from, int to) {
  if (to < left || right < from) return 0;
  if (from <= left && right <= to) return segment_tree[node];
  if (left == right) return segment_tree[node];

  int mid = (left + right) / 2;
  int a = query (node * 2, left, mid, from, to);
  int b = query (node * 2 + 1, mid + 1, right, from, to);
  return a + b;
}

int main () {
  int height = ceil(log2(arr.size())); // height of segment tree

  int N = 1 << (height + 1); // size of segment tree

  segment_tree.resize(N);

  init(1, 0, arr.size() - 1);
  update(5, 100, 1, 0, 14);
  for (int i = 1; i < segment_tree.size(); ++i) {
    cout << segment_tree[i] << " ";
    if ((i + 1) == (1 << (int)ceil(log2(i + 1)))) cout << "\n";
  }

  cout << query(1, 0, 14, 3, 6) << "\n";
  cout << query(1, 0, 14, 0, 14) << "\n";
  cout << query(1, 0, 14, 7, 14) << "\n";
}
```
