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

void push(long long lv, long long cnt) {
  // cout << "push " << lv << "(" << cnt << ") \t|";
  stk.push({lv, cnt});
  // printStk();
}

void pop() {
  // cout << "pop \t\t|";
  stk.pop();
  // printStk();
}

int main () {
  cin >> N;

  cin >> l;
  stk.push({ l, 1 });
  for (int i = 1; i < N; ++i) {
    cin >> l;
    // cout << "turn: " << i << "(left: " << stk.top().first << ", right: " << l[i] << ")" << "\n";
    if (stk.top().first > l) {
      // cout << "\tdown\n";
      // cout << "\t";
      push(l, 1);
      if (stk.size()) {
        r++;
      }
      // cout << "\t\tafter loop (r: " << r << ")" << "\n";
      continue;
    }

    if (stk.top().first == l) {
      // cout << "\tequal\n";
      r += stk.top().second;
      long long cnt = stk.top().second + 1;
      // cout << "\t";
      pop();
      // cout << "\t";
      if (stk.size()) {
        r++;
      }
      push(l, cnt);
      // cout << "\t\tafter loop (r: " << r << ")" << "\n";
      continue;
    }

    if (stk.top().first < l) {
      // int cnt = 1;
      // cout << "\tup\n";
      // cout << "\t== loop start\n";
      // while(stk.size() && stk.top().first <= l[i]) {
      //   if (l[i] == stk.top().first) {
      //     cnt = stk.top().second + 1;
      //     cout << "\tequal -> cnt + prevCnt\n";
      //   } else {
      //     cout << "\tup    -> do nothing\n";
      //   }
      //   cout << "\t";
      //   pop();
      //   cout << "\t#cycle end(r: " << r << ", cnt: " << cnt << ")" << "\n";
      // }
      // cout << "\t== end loop\n";
      // cout << "\t";
      // if (stk.size()) {
      //   r += stk.top().second;
      // } else {
      //   r += cnt;
      // }
      r += stk.top().second;
      // cout << "\t";
      pop();
      long long cnt = 1;
      if (stk.size() && stk.top().first == l) {
        cnt = stk.top().second + 1;
        r += stk.top().second;
        // cout << "\t";
        pop();
      }
      // cout << "\t";
      if (stk.size()) {
        ++r;
      }
      push(l, cnt);
      // cout << "\t\tafter loop (r: " << r << ")" << "\n";
      continue;
    }

    // if (stk.top().first == l[i]) {
    //   stk.push({l[i], 1});
    // }
  }
  cout << r;
  return 0;
}