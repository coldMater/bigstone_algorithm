// https://www.acmicpc.net/problem/15353
#include <bits/stdc++.h>
using namespace std;

string A, B;
vector<int> l1;
vector<int> l2;
vector<int> r;

void print (vector<int> l) {
  for (int a : l) {
    cout << a << "";
  }
  cout << "\n";
}

int main () {
  cin >> A >> B;
  for (char a : A) {
    l1.push_back(a - '0');
  }
  for (char b : B) {
    l2.push_back(b - '0');
  }
  reverse(l1.begin(), l1.end());
  reverse(l2.begin(), l2.end());
  int carry = 0;
  if (l1.size() < l2.size()) {
    int diff = l2.size() - l1.size();
    for (int i = 0; i < diff; ++i) {
      l1.push_back(0);
    }
  } else if (l1.size() > l2.size()) {
    int diff = l1.size() - l2.size();
    for (int i = 0; i < diff; ++i) {
      l2.push_back(0);
    }
  }
  for (long i = 0; i < l1.size(); ++i) {
    // cout << "step: " << i << "\n";
    int s = l1.at(i) + l2.at(i) + carry;
    // cout << "s: " << s << "\n";
    int remained = s % 10;
    r.push_back(remained);
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
