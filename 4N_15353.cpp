// https://www.acmicpc.net/problem/15353
#include <bits/stdc++.h>
using namespace std;

string A, B;
vector<int> r;

void print (vector<int> l) {
  for (int a : l) {
    cout << a << "";
  }
  cout << "\n";
}

int main () {
  cin >> A >> B;
  int carry = 0;
  for (int i = max(A.size(), B.size()) - 1; i >= 0; --i) {
    // cout << "step: " << i << "\n";
    int s = (A[i] - '0') + (B[i] - '0');
    // cout << "s: " << s << "\n";
    int remained = s % 10;
    r.push_back(remained + carry);
    if (s >= 10) {
      carry = 1;
    } else {
      carry = 0;
    }
  }
  if (carry) {
    r.push_back(1);
  }
  reverse(r.begin(), r.end());
  for (int d : r) {
    cout << d;
  }
  return 0;
}
