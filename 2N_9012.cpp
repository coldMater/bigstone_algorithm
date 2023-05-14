// https://www.acmicpc.net/problem/9012
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool c(string s) {
    stack<char> st;
    for (char c : s) {
        if (st.empty()) {
            if (c == ')') return false;
        }

        if (c == '(') {
            st.push(c);
        } else {
            st.pop();
        }
    }

    return st.empty();
}

int main () {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (c(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}