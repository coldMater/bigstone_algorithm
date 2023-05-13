// https://www.acmicpc.net/problem/3474
#include <bits/stdc++.h>
using namespace std;

int n, t; // number, target number
int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        int c = 0; // count
        for (int j = 5; j <= t; j = j + 5) {
            int t = j; // temp
            while (t % 5 == 0) {
                c++;
                t /= 5;
            }
        }
        cout << c << "\n";
    }
    return 0;
}