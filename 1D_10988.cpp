// https://www.acmicpc.net/problem/10988
#include <bits/stdc++.h>
using namespace std;

string s;
int main () {
    cin >> s;
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1 << "\n";
    return 0;
}