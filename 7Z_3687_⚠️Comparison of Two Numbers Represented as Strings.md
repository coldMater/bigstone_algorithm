```cpp
// ❌ Wrong Case (🚩Find the part that needs improvement!)

string getMinStr(string a, string b) {
  if (a.length() > b.length()) return b;

  for (int i = 0; i < a.length(); ++i) {
    if (a[i] < b[i]) return a;
    else if (a[i] > b[i]) return b;
  }
  return a; // b is also fine since a == b, so either can be returned.
}
```
