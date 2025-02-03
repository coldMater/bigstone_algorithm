#include <bits/stdc++.h>
using namespace std;

long long n, sum;
int main () {
    cin >> n;
    for (int i = 1; i <= n - 2; ++i) {
        sum += ((n - i - 1) + 1) * (n - i - 1) / 2;
    }
    cout << sum << "\n" << 3;
    return 0;
}