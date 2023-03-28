// https://www.acmicpc.net/problem/2979

#include <bits/stdc++.h>
using namespace std;

void printArr(int* t) {
    for (int i = 0; i < 100; ++i) {
        cout << t[i] << " ";
    }
    cout << "\n";
}

int f[3], s, e, t[100], sum;
int main () {
    cin >> f[0] >> f[1] >> f[2];

    for (int i = 0; i < 3; i++) {
        cin >> s >> e;
        for (int j = s; j < e; j++) {
            t[j] += 1;
        }
    }

    
    for (int i = 1; i <= 100; ++i) {
        sum += f[t[i] - 1] * t[i];
    }

    cout << sum;
    return 0;
}