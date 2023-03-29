// https://www.acmicpc.net/problem/1159 
#include <bits/stdc++.h>
using namespace std;

void print (int* c) {
    for (int i = 0; i < 30; i++) {
        cout << 'a' + i << ": " << c[i];
        cout << "\n";
    }
}
int n, c[30]; // number, firstName, count
string f, r;
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f;
        c[f[0] - 'a']++;
    }
    for (int i = 0; i < 30; i++) {
        if (c[i] >= 5) {
            r += char(i + 'a');
        }
    }
    if (r.length() == 0) {
        cout << "PREDAJA";
        return 0;
    }
    cout << r << "\n";
    return 0;
}
