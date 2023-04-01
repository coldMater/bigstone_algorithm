// https://www.acmicpc.net/problem/2559
#include <bits/stdc++.h>
using namespace std;

int dn, sn, m = INT_MIN, d[100000]; // day num, sum num
int main () {
    cin >> dn >> sn;

    for (int i = 0; i < dn; ++i) {
        cin >> d[i];
    }

    for (int i = sn - 1; i < dn; ++i) {
        int sum = 0;
        for (int j = 0; j < sn; ++j) {
            sum += d[i - j];
        }
        if (m < sum) m = sum;
    }

    cout << m << "\n";

    return 0;
}