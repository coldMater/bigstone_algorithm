// https://www.acmicpc.net/problem/9012
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
stack<char> st;
int main () {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (char c : s) {
            if (st.size() != 0 && st.top() != c) {
                st.pop();
            } else {
                if (st.size() == 0 && c == ')') {
                    st.push(')');
                    break;
                }
                st.push(c);
            }
        }
        if (st.size() == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

        while (st.size() != 0) {
            st.pop();
        }
    }
    return 0;
}