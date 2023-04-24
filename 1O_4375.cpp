// https://www.acmicpc.net/problem/4375
#include <bits/stdc++.h>
using namespace std;

int n, p; // prev - multiplier of 10
int main () {
    while ( scanf("%d", &n)!= EOF) {
        int a = 1; // accumulated
        int c = 1; // count
        p = 1;
        while (0 != (a % n)) {
            p = ((p % n) * (10 % n)) % n;
            a += p;
            c++;
        }
        cout << c << "\n";
    }
}