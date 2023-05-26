// https://www.acmicpc.net/problem/17298
#include <bits/stdc++.h>
using namespace std;

int N;
int a[1'000'000];
int nge[1'000'000];
int main () {
    cin >> N;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = N - 1 ; i >= 0; --i) {
        nge[i] = -1;
        for (int j = i + 1; j < N; ++j) {
            if (a[i] == a[j]) {
                nge[i] = nge[j];
                break;
            } else if (a[i] < a[j]) {
                nge[i] = a[j];
                break;
            } else if (a[i] > a[i]) {
                continue;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << nge[i] << " ";
    }

    return 0;
}