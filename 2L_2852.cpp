// https://www.acmicpc.net/problem/2852
#include<bits/stdc++.h>
using namespace std;

int gc; // goal count
int tn; // team number
string t; // time
int to[3]; // team occupied
int rgt; // recent goal time (unit: second)
int rgn; // recent goal team number

int getSecFromStr(string t) {
    bool flag = false;
    string m;
    string s;
    for (char c : t) {
        if (c == ':') {
            flag = true;
            continue;
        }

        if (flag) {
            s += c;
        } else {
            m += c;
        }
    }

    return atoi(m.c_str()) * 60 + atoi(s.c_str());
}

int main () {
    cin >> gc;
    cin >> tn;
    cin >> t;
    rgn = tn;
    rgt = getSecFromStr(t);
    for (int i = 1; i < gc; ++i) {
        cin >> tn;
        cin >> t;

        if (tn == rgn) continue;

        to[rgn] += getSecFromStr(t) - rgt;

        rgn = tn;
        rgt = getSecFromStr(t);
    }

    to[rgn] += (48 * 60) - rgt;

    printf("%02d:%02d\n", to[1] / 60, to[1] % 60);
    printf("%02d:%02d\n", to[2] / 60, to[1] % 60);

    return 0;
}