// https://www.acmicpc.net/problem/1940
#include <bits/stdc++.h>
using namespace std;

int c; // count
int t; // target number to create armor
int s; // serial number of materials for making armor
int cl, cr; // cursor left, cursor right
int r; // count of available armor
// map<int, bool> a; // 1st Try Passed, 26408 KB Memory, 140ms
// bool a[200'001]; // 2nd Try Passed, 11788 KB Memory, 4ms
int a[15001]; // 4th Try Passed, 2080 KB Memory, 0ms - Reduce Memory Waste
int main () {
    ios_base::sync_with_stdio(false); // 3nd Try Passed, 11788 KB Memory, 0ms
    cin.tie(NULL);cout.tie(NULL);

    cin >> c;
    cin >> t;

    for (int i = 0; i < c; ++i) {
        cin >> a[i];
    }
    cl = 0;
    cr = c - 1;

    sort(a, a + c);

    while (cl < cr) {
        if (a[cl] + a[cr] == t) {
            r++;
            cl++;
            cr--;
        } else if (a[cl] + a[cr] > t) {
            cr--;
        } else {
            cl++;
        }
    }

    cout << r;

    return 0;
}