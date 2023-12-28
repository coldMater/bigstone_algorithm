// https://www.acmicpc.net/problem/15926
#include <bits/stdc++.h>
using namespace std;

int l;
string s;
stack<int> st; // stack
bool h[200'001];
int main () {
  cin >> l;  cin >> s;
  for (int i = 0; i < l; ++i) {
    // cout << "c : " << c << "\n";
    if (s[i] == '(') {
      // cout << "push" << "\n";
      st.push(i);
    } else if (s[i] == ')' && !st.empty()) {
      // cout << "pop" << "\n";
      h[st.top()] = 1;
      h[i] = 1;
      st.pop();
    }
  }

  int mc = 0; // matching count
  int mmc = 0; // max matching count
  for (int i = 0; i < l; ++i) {
    // cout << (h[i] ? "1" : "0") << " ";
    if (h[i]) {
      mc++;
      mmc = max(mmc, mc);
    } else {
      mc = 0;
    }
  }
  // cout << "\n";
  cout << mmc;
  return 0;
}