// https://www.acmicpc.net/problem/4949
#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[') {
            stk.push(c);
        } else if (c == ')' || c == ']') {
            if (stk.empty()) return false;
            if (stk.top() == '(' && c == ')') stk.pop();
            else if (stk.top() == '[' && c == ']') stk.pop();
            else return false;
        }
    }

    return stk.empty();
}

string s;
int main () {
    while (true) {
        getline(cin, s);
        if (s == ".") break;

        if(check(s)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}