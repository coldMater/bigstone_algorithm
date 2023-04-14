// https://www.acmicpc.net/problem/1629
#include <bits/stdc++.h>
using namespace std;

long long l, r, d; // (left ^ right) % divider, result

long long rec (long long n) {
    if (n == 1) return l % d;
    long long ret = rec(n / 2);
    ret = (ret * ret) % d;
    if (n % 2) ret = (ret * l) % d;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> l >> r >> d;

    cout << rec(r);

    return 0;
}
