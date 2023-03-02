// https://www.acmicpc.net/problem/2309
// run at PowerShell on Windows11: `Get-Content .\1A_2309_input.txt | .\1A_2309.exe`
#include<bits/stdc++.h>
using namespace std;

int main() {
    int h[9]; // height list of dwrafs
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        int t; // temp
        cin >> t;
        h[i] = t;
    }

    sort(h, h+9);

    for (int i : h) {
        sum += i;
    }

    int diff = sum - 100;

    int o = 0; // one 
    int a = 0; // another
    bool end = false;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            o = h[i];
            a = h[j];
            if (o + a == diff) {
                end = true;
                break;
            }
        }
        if (end) break;
    }

    for (int i = 0; i < 9; i++) {
        if (h[i] == o || h[i] == a) continue;
        cout << h[i] << '\n';
    }

    return 0;
}