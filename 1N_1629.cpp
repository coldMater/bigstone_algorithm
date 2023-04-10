// https://www.acmicpc.net/problem/1940
#include <bits/stdc++.h>
using namespace std;

int l, r, d, rs; // (left * right) % divider, result
int main () {
    cin >> l >> r >> d;

    rs = 1;
    for (int i = 0; i < r; ++i) {
        rs = (rs * (l % d)) % d;
    }

    cout << rs;

    return 0;
}
