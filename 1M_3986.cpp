// https://www.acmicpc.net/problem/1940
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
stack<char> st;
int r;
int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;

        for (int j = 0; j < s.size(); ++j) {
            if (st.size() == 0) {
                st.push(s[j]);
                continue;
            } 

            if (st.top() == s[j]) {
                st.pop();
                continue;
            }

            st.push(s[j]);
        }
        if (st.size() == 0) ++r;

        while(st.size() > 0) {
            st.pop();
        }
    }
    cout << r;
    return 0;
}