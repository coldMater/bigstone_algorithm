```cpp
#include <bits/stdc++.h>
using namespace std;

int fenwick_tree[17];
void update (int idx, int val) {
  while (idx < 17) {
    fenwick_tree[idx] += val;
    idx = idx + (idx & -idx);
  }
}

int sum (int to) {
  int ret = 0;
  while (to > 0) {
    ret += fenwick_tree[to];
    to = to - (to & -to);
  }
  return ret;
}

int main () {
  for (int i = 1; i < 17; ++i) {
    update(i, i);
  }

  // sum 1 to 5
  cout << sum(5) << "\n"; // 15
  // sum 1 to 10
  cout << sum(10) << "\n"; // 55
  // sum 6 to 10
  cout << sum(10) - sum(5) << "\n"; // 40
}
```
