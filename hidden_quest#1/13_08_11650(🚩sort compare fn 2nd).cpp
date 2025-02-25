#include <bits/stdc++.h>
using namespace std;

int N, x, y;
vector<pair<int, int>> v;

// 🚩 Controlling Order in Array Sorting
// 1st argument: preceding argument (earlier in the array respectively)
// 2nd argument: following argument (later in the array respectively)
// return value: true: maintain order, false: do not maintain order
// `bool compare(int a, int b) { return a < b; }` 
// 1. It means 'it is true that the preceding argument is smaller than the following argument'.
// 2. Such that their order is preserved.
// 3. In point 2, 'order' refers to the sequence that makes `a < b` true. 
// 4. Since `a` is the preceding argument and `b` is the following argument, this means that the order should ensure the smaller values are at the beginning of the array.
// 6. This ensures that the array maintains an ascending order from the front to the back.
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  else return a.second < b.second;
}

int main () {
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    v.push_back({ x, y });
  }
  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < v.size(); ++i) {
    cout << v[i].first << " " << v[i].second << "\n";
  }
  return 0;
}