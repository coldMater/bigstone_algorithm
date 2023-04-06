// https://www.acmicpc.net/problem/1940
#include <bits/stdc++.h>
using namespace std;

int c; // count
int t; // target number to create armor
int s; // serial number of materials for making armor
int cl, cr; // cursor left, cursor right
int r; // count of available armor
map<int, bool> a;
int main () {
    cin >> c;
    cin >> t;

    for (int i = 0; i < c; ++i) {
        cin >> s;
        a[s] = true;
    }

    if (t & 1) {
        cl = t / 2 ;
        cr = cl + 1;
    } else {
        cl = (t / 2) - 1;
        cr = cl + 2;
    }

    while (cr < t) {
        // cout << cl << " " << cr;
        
        if (a[cl] && a[cr]) r++;
        cl--;
        cr++;
    }

    cout << r;

    return 0;
}