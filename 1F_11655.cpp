// https://www.acmicpc.net/problem/11655
#include <bits/stdc++.h>
using namespace std;

string s;
int main () {
    getline(cin, s);

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' and s[i] <= 'Z') {
            cout << char(((s[i] - 'A' + 13) % 26) + 'A');
            continue;
        }
        if (s[i] >= 'a' and s[i] <= 'z') {
            cout << char(((s[i] - 'a' + 13) % 26) + 'a');
            continue;
        }
        cout << s[i];
    }
    return 0;
}