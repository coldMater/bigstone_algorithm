```cpp
// Declaration
void combi(int n, int r, int start, vector<int> b) {
  if (b.size() == r) {
    // Do something
    return;
  }
  for (int i = start; i < n; ++i) {
    b.push_back(i);
    combi(n, r, i + 1, b);
    b.pop_back();
  }
}

// call
vector<int> v;
combi(9, 3, 0, v);

```