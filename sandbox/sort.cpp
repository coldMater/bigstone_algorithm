#include <bits/stdc++.h>
using namespace std;

bool rev(int a, int b) {
    return a > b;
}

main () {
    srand(1234);
    int a[10];
    vector<int> b;

    for (int i = 0; i < 10; ++i) {
        a[i] = rand();
    }

    sort(a, a + 10, rev);

    for (int num : a) {
        cout << num << ' ';
    }
    return 0;
}