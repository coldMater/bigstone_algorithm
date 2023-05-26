// https://www.acmicpc.net/problem/17298
#include <bits/stdc++.h>
using namespace std;

int N;
int a[1'000'000];
int nge[1'000'000];
stack<int> s;
int main () {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N; ++i) {
        if (s.empty()) {
            s.push(i);
            continue;
        }

        if (a[s.top()] < a[i]) {
            while(!s.empty() && a[s.top()] < a[i]) {
                nge[s.top()] = a[i];
                s.pop();
            }
        }

        s.push(i);
    }

    while (!s.empty()) {
        nge[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < N; ++i) {
        cout << nge[i] << " ";
    }

    return 0;
}
