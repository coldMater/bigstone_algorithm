// https://www.acmicpc.net/problem/11723
#include <bits/stdc++.h>
using namespace std;

int M, n, operand;
string op; // operator
int main () {

  // Without this block, a timeout occurs.
  {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    // cout.tie(NULL); // Even without this code, a timeout does not occur.
  }

  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> op;

    if (op == "add") {
      cin >> operand;
      n |= 1 << operand;
    } else if (op == "remove") {
      cin >> operand;
      n &= ~(1 << operand);
    } else if (op == "check") {
      cin >> operand;
      if (n & (1 << operand)) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else if (op == "toggle") {
      cin >> operand;
      n ^= 1 << operand;
    } else if (op == "all") {
      n = ~0;
    } else if (op == "empty") {
      n = 0;
    }
  }
  return 0;
}