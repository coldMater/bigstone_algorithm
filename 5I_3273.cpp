// https://www.acmicpc.net/problem/3273
#include <bits/stdc++.h>
using namespace std;

int n, x, ret;
int arr[100'001];
map<int, bool> m;
int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cin >> x;
  for (int i = 0; i < n; ++i) {
    if (m.find(arr[i]) != m.end()) {
      ret++;
      continue;
    }
    int complement = x - arr[i];
    m[complement] = 1;
  }
  cout << ret;
  return 0;
}