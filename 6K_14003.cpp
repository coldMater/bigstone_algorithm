// https://www.acmicpc.net/problem/14003
#include <bits/stdc++.h>
using namespace std;

int N;
int len;
int arr[1'000'001];
int lis[1'000'001];
int mem[1'000'001];
int INF = 1'234'567'890;
stack<int> stk;
int main () {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  fill(mem, mem + 1'000'001, INF);

  for (int i = 0; i < N; ++i) {
    int* pos = lower_bound(lis, lis + len, arr[i]);
    int cur = (int)(pos - lis);
    // cout << "val: " << arr[i] << ", cur: " << pos - lis << "\n";
    if (cur == len) { // cannot find
      lis[len] = arr[i];
      len++;
    } else {
      lis[cur] = arr[i];
    }
    mem[i] = cur;
    // cout << "res: ";
    // for (int j = 0; j < len; ++j) {
    //   cout << lis[j] << " ";
    // }
    // cout << "\n";
    // cout << "mem: ";
    // for (int j = 0; j < N; ++j) {
    //   cout << mem[j] << " ";
    // }
    // cout << "\n";
  }

  // cout << len << "\n"; // length of LIS: first answer
  // int f = 0;
  // for (int i = 0; i < N; ++i) {
  //   if (mem[i] == f) {
  //     cout << lis[mem[i]] << " ";
  //     f++;
  //   }
  // }
  cout << len << "\n";
  for (int i = N - 1; i >= 0; --i) {
    if (mem[i] == len - 1) {
      stk.push(arr[i]);
      len--;
    }
  }

  while (!stk.empty()) {
    cout << stk.top() << " ";
    stk.pop();
  }

  return 0;
}