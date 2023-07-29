// https://www.acmicpc.net/problem/9934
#include <bits/stdc++.h>
using namespace std;

int d, n; // depth, node count
int v[1023]; // visited history (given as input)
vector<int> t[11]; // tree

int go (int d, int s, int e) { // depth, start index, end index
  // cout << d << ":" << s << ":" << e << "\n";
  int midIdx = (e + s) / 2;
  int mid = v[midIdx];
  t[d].push_back(mid);
  if (s == e) {
    return mid;
  }
  int left = go(d + 1, s, midIdx - 1);
  int right = go(d + 1, midIdx + 1, e);
  return mid;
}

int main () {
  cin >> d;
  n = pow(2, d) - 1;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  go (1, 0, n - 1);
  for (int i = 1; i <= d; ++i) {
    for (int nn : t[i]) { // node's name
      cout << nn << " ";
    }
    cout << "\n";
  }

  return 0;
}
