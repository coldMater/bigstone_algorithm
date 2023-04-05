// https://www.acmicpc.net/problem/1213
#include <bits/stdc++.h>
using namespace std;

string in; // input
int a[100]; // alphabet list
char alone; // ADDB'B'BDDC, 'B' is alone
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> in;

    for (auto c : in) {
        a[c]++;
    }

    char alone = 0; // 
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (a[i] % 2 != 0) {
            if (alone != 0) {
                cout << "I'm Sorry Hansoo";
                return 0;
            } 
            alone = char(i);
        }
        a[i] /= 2;
    }

    for (int i = 'A'; i <= 'Z'; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << char(i);
        }
    }

    if (alone != 0) cout << char(alone);

    for (int i = 'Z'; i >= 'A'; --i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << char(i);
        }
    }

    return 0;
}