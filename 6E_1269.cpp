// https://www.acmicpc.net/problem/1269
#include <bits/stdc++.h>
using namespace std;

int A, B;
map<int, bool> a;
map<int, bool> b;
map<int, bool> ans;
map<int, bool> b_a;
int main () {
  cin >> A >> B;
  for (int i = 0; i < A; ++i) {
    int temp;
    cin >> temp;
    a[temp] = true;
  }
  for (int i = 0; i < B; ++i) {
    int temp;
    cin >> temp;
    b[temp] = true;
  }

  // cout << "A: \n";
  for (pair<int, bool> p : a) {
    if (b[p.first]) {
    } else {
      // cout << p.first << "\n";
      ans[p.first] = true;
    }
  }

  // cout << "B: \n";
  for (pair<int, bool> p : b) {
    if (a[p.first]) {
    } else {
      // cout << p.first << "\n";
      ans[p.first] = true;
    }
  }

  cout << ans.size();

  return 0;
}