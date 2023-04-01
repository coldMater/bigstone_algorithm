// https://www.acmicpc.net/problem/9996
#include <bits/stdc++.h>
using namespace std;

int n;
int pos;
string p, pre, suf, s; //pattern
int main () {
    cin >> n;
    cin >> p;
    pos = p.find('*');
    string pre = p.substr(0, pos); // from, till
    string suf = p.substr(pos + 1, p.length()); 

    for (int i = 0; i < n; ++i) {
        cin >> s;

        // Without this condition block, runtime error occurred when checking.
        if (s.length() < pre.length() + suf.length()) {
            cout << "NE\n";
            continue;
        }

        if (pre == s.substr(0, pre.length()) && suf == s.substr(s.length() - suf.length(), s.length())) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }

    return 0;
}
