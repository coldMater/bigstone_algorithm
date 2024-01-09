// https://www.acmicpc.net/problem/3273
#include <bits/stdc++.h>
using namespace std;

int n, x;
int v[100'001];
int ret;
int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cin >> x;

  sort(v, v + n);

  int l = 0; // left
  int r = n - 1; // right
  while (l < r) { // ⚠️ out of bound when `l == r`
    int sum = v[l] + v[r];
    if (sum == x) {
      ret++;
      l++; r--;
    } 
    else if (sum < x) l++; 
    else if (sum > x) r--;
  }

  cout << ret;

  return 0;
}