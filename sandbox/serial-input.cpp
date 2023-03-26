#include <bits/stdc++.h>
using namespace std;

// input as like next type.
// 4 4
// 1234
// 2345
// 3456
// 4567
int n, m, a[10][10];
string s;
int main () {
    cin >> n >> m;
    printf("%d %d", n, m);
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    } 
    return 0;
}