```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
  vector<int> l = {1, 5, 3, 2, 3, 3, 2};

  sort(l.begin(), l.end());
  for (int e : l) cout << e; cout << "\n"; // 1223335

  vector<int>::iterator it = unique(l.begin(), l.end()); // returns: An iterator designating the end of the resulting sequence.
  for (int e : l) cout << e; cout << "\n"; // 1235335

  l.erase(it, l.end());
  for (int e : l) cout << e; cout << "\n"; // 1235

  // abbreviation
  // l.erase(unique(l.begin(), l.end()), l.end());

  return 0;
}
```
