// https://www.acmicpc.net/problem/15686
#include <bits/stdc++.h>
using namespace std;

int N, M;
int m[50][50];
vector<pair<int, int>> hs; // houses
vector<pair<int, int>> cs; // chicken stores
vector<pair<int, int>> rcs; // remained chicken stoes
int mm = INT_MAX; // min results

void calcCD () { // calculate Chicken Distance
    int d = 0;
    for (auto h : hs) {
        int mcd = INT_MAX; // min chicken distance
        for (auto c: rcs) {
            int cd = abs(h.first - c.first) + abs(h.second - c.second); // chicken distance
            if (cd < mcd) mcd = cd;
        }
        d += mcd;
    }
    if (d < mm) mm = d;
}

void go (int d) {
    if (d == M) {
        calcCD();
        return;
    }

    for (int i = d; i < cs.size(); ++i) {
        rcs.push_back(cs[i]);
        go(d + 1);
        rcs.pop_back();
    }
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> m[i][j];
            if (m[i][j] == 1) {
                hs.push_back({ i, j });
            }
            if (m[i][j] == 2) {
                cs.push_back({ i, j });
            }
        }
    }

    go(0);

    cout << mm;

    return 0;
}