// https://www.acmicpc.net/problem/14888
#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> seq; // sequence
vector<int> ops; // operators // 0: +, 1: -, 2: *, 3: / 

int mx = -1'987'654'321; // max
int mn = 1'987'654'321; // min

void swap (int l, int r) {
  int temp = ops[l];
  ops[l] = ops[r];
  ops[r] = temp;
}

int calc (int left, int right, int op) {
  switch (op) {
    case 0:
    return left + right;
    case 1:
    return left - right;
    case 2:
    return left * right;
    case 3:
    return left / right;
    default:
    throw "Unavailable operator: " + op;
  }
}

void go (int d) {
  if (d == ops.size()) {
    int order = 0;
    int c = seq[order];
    for (int o : ops) {
      c = calc(c, seq[++order], o);
    }
    mx = max(mx, c);
    mn = min(mn, c);
    return;
  }

  for (int i = d; i < ops.size(); ++i) {
    swap(d, i);
    go (d + 1);
    swap(d, i);
  }
  return;
}

int main () {
  cin >> N;
  for (int i = 0; i< N; ++i) {
    int temp = 0;
    cin >> temp;
    seq.push_back(temp);
  }

  for (int i = 0; i < 4; ++i) {
    int cnt = 0;
    cin >> cnt;
    while (cnt-- > 0) {
      ops.push_back(i);
    }
  }

  go(0);

  cout << mx << "\n";
  cout << mn << "\n";

  return 0;
}

