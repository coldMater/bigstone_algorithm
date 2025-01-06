// https://www.acmicpc.net/problem/14002
#include <bits/stdc++.h>
using namespace std;

int N;
int n[1000];
int c[1000];
int pre[1000]; // previous
int res;
int res_i; // result index
int main () {
  fill(pre, pre + 1000, -1);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> n[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (n[j] < n[i] && c[i] < c[j] + 1) {
        c[i] = c[j] + 1;
        if (res < c[i]) {
          res = c[i];
          res_i = i;
        }
        pre[i] = j;
      }
    }
  }

  cout << res + 1 << "\n";

  // cout << "res_i: " << res_i << "\n";
  stack<int> stk;
  int i = res_i;
  while (true) {
    stk.push(n[i]);
    i = pre[i];
    if (i == -1) break;
  }

  while (!stk.empty()) {
    cout << stk.top() << " ";
    stk.pop();
  }
  // cout << "\n";

  // for (int i = 0; i < N; ++i) {
  //   cout << pre[i] << " ";
  // }

  return 0;
}