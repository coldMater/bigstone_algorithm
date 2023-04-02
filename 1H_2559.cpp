// https://www.acmicpc.net/problem/2559
#include <bits/stdc++.h>
using namespace std;

int dn, sn, m = INT_MIN, a[100100]; // day num, sum num
int main () {
    cin >> dn >> sn;

    for (int i = 0; i < dn; ++i) {
        cin >> a[i];
    }


    int sum = 0;
    for (int i = 0; i < sn; ++i) {
        sum += a[i];
    }
    if (sum > m) m = sum; // If the sum of the first group is maximum.

    for (int i = sn; i < dn; ++i) {
        sum -= a[i-sn];
        sum += a[i];

        // cout << i << "(" << ps<< "," << pe << ") ";
        // cout << "-(" << a[ps] << ")-("<< a[pe] <<")="<< sum << " ";
        if (m < sum) m = sum;
    }

    cout << m;

    return 0;
}