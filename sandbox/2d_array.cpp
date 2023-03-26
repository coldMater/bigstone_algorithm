#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10][20];

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        for (int j = 0; j < sizeof(a[10]) / sizeof(a[10][0]); j++) {
            a[i][j] = i*j;
        }
    }

    cout << *(*a + 1) << endl;

    return 0;
}