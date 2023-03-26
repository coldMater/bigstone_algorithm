#include <bits/stdc++.h>
using namespace std;

void printV (vector<int> v) {
    for (auto n : v) {
        cout << n << ' ';
    }
    cout << endl;
}
vector<int> v;
int main () {
    int n = 1234123;
    int b = 16; // 2
    while (n > 0) {
        v.push_back(n % b);
        n /= b;
    }

    // if (n == 1) v.push_back(1);
    reverse(v.begin(), v.end());
    printV(v);

    // print as base_b;
    for (int a : v) {
        if (a >= 10) cout << char(a + 55);
        else cout << a;
    }
    return 0;
}