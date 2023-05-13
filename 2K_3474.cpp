// https://www.acmicpc.net/problem/3474
#include <bits/stdc++.h>
using namespace std;

int n, t; // number, target number
int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        int c = 0; // count
        for (int j = 5; j <= t; j *= 5) {
            c += t / j; 
            // when j = 5, count multiples of 5.
            // when j = 25, count multiples of 25. It is second iteration of this for loop. 25 is 5 times 5, so another five has to be included as count.
            // and by repeating the power of 5, count number of 5 like this.
        }
        cout << c << "\n";
    }
    return 0;
}