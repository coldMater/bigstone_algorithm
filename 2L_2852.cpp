// https://www.acmicpc.net/problem/2852
#include<bits/stdc++.h>
using namespace std;

int gc; // goal count
int tn; // team number
string t; // time
int to[3]; // team occupied
int rgt; // recent goal time (unit: second)
int rgn; // recent goal team number
int winning;
int score[3];
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
    for (int i = 0; i < gc; ++i) {
        cin >> tn;
        cin >> t;
        to[winning] += getSecFromStr(t) - rgt;

        score[tn]++;

        rgn = tn;
        rgt = getSecFromStr(t);
        winning = score[1] > score [2] ? 1 : score[2] > score[1] ? 2 : 0;
    } 

    // After Last Goal
    to[winning] += (48 * 60) - rgt;

    printf("%02d:%02d\n", to[1] / 60, to[1] % 60);
    printf("%02d:%02d\n", to[2] / 60, to[2] % 60);
    return 0;
}