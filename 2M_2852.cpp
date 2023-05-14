// https://www.acmicpc.net/problem/2852
#include <bits/stdc++.h>
using namespace std;

int n, c, cc;
int main () {
    cin >> n;
    while (true) {
        c++;
        int six = 0;
        string s = to_string(c);
        if(s.find("666") != string::npos) {
            cc++;
        }
        if (cc == n) {
            cout << c;
            break;
        }
    }
    return 0;
}