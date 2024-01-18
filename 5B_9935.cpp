// https://www.acmicpc.net/problem/9935
#include <bits/stdc++.h>
using namespace std;

string i;
string b;
void printStack (stack<char> s) {
  if (s.empty()) {
    cout << "Stack empty!\n";
    return;
  }
  stack<char> tmp;
  while (s.size()) {
    cout << s.top();
    tmp.push(s.top());
    s.pop();
  }
  while (tmp.size()) {
    s.push(tmp.top());
    tmp.pop();
  }
  cout << "\n";
}

int main () {
  cin >> i;
  cin >> b;
  stack<char> stk;
  for (char c : i) {
    stk.push(c);
    if (stk.size() < b.size()) continue;
    stack<char> tmp;
    bool boom;
    // cout << boom << "\n";
    for (int i = b.size() - 1; i >= 0; --i) {
      // cout << stk.top() << " " << b[i] << "\n";
      if (stk.top() == b[i]) {
        tmp.push(stk.top());
        stk.pop();
        // printStack(stk);
        if (i == 0) {
          boom = true;
        }
        continue;
      }
      break;
    }
    // printStack(stk);
    if (boom) {
      boom = false;
      continue;
    }
    // cout << "boom!\n";
    while (tmp.size()) {
      stk.push(tmp.top());
      tmp.pop();
    }
  }

  if (stk.empty()) {
    cout << "FRULA";
    return 0;
  }

  stack<char> temp;
  while (stk.size()) {
    temp.push(stk.top());
    stk.pop();
  }

  while(temp.size()) {
    cout << temp.top();
    temp.pop();
  }
  return 0;
}

// method1: using string
// string i;
// string b;
// int main () {
//   cin >> i;
//   cin >> b;

//   string s;
//   for (char c : i) {
//     s += c;
//     if (s.size() >= b.size() && s.substr(s.size() - b.size(), b.size()) == b) {
//       // cout << s << "\n";
//       s.erase(s.size() - b.size(), b.size());
//       // cout << s << "\n";
//     }
//   }
  
//   if (s.size() == 0) {
//     cout << "FRULA";
//   } else {
//     cout << s;
//   }
//   return 0;
// }