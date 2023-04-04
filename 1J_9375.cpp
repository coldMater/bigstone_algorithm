// https://www.acmicpc.net/problem/9375
#include <bits/stdc++.h>
using namespace std;

int cn, n; // case number, number(wear count)
string nm, t; // wear name, wear type
map<string, int> w; // wears
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);

    cin >> cn;

    for (int i = 0; i < cn; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> nm >> t;
            w[t]++;
        }
        int noc = 1; // number of cases
        for (auto k : w) {
            noc *= k.second + 1;
        }
        noc -= 1;
        cout << noc << "\n";

        w.clear();
    }

    return 0;
}