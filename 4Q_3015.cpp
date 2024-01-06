// https://www.acmicpc.net/problem/3015
#include <bits/stdc++.h>
using namespace std;

int N;
int l; // level
stack<pair<long long, long long>> stk;
long long r;

void printStk() {
  stack<pair<long long, long long>> tempStk;
  while(stk.size()) {
    tempStk.push(stk.top());
    stk.pop();
  }

  while(tempStk.size()) {
    // cout << "| " << tempStk.top().first << "(" << tempStk.top().second << ") ";
    stk.push(tempStk.top());
    tempStk.pop();
  }
  // cout << "\n";
}

// void push(long long lv, long long cnt) {
//   // cout << "push " << lv << "(" << cnt << ") \t|";
//   stk.push({lv, cnt});
//   // printStk();
// }

// void pop() {
//   // cout << "pop \t\t|";
//   stk.pop();
//   // printStk();
// }

int main () {
  cin >> N;

  cin >> l;
  stk.push({ l, 1 });
  for (int i = 1; i < N; ++i) {
    cin >> l;
    // cout << "turn: " << i << "(left: " << stk.top().first << ", right: " << l[i] << ")" << "\n";
    long long cnt = 1;
    while (stk.size() && stk.top().first <= l) {
      r += stk.top().second;
      if (stk.top().first == l) {
        cnt = stk.top().second + 1;
      }
      stk.pop();
      // cout << "\t\tafter loop (r: " << r << ")" << "\n";
    } 

    if (stk.size()) {
      r++;
    }
    stk.push({l, cnt});
  }
  cout << r;
  return 0;
}