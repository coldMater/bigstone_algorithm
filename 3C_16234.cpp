// https://www.acmicpc.net/problem/16234
#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int m[50][50];
bool v[50][50];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int day;

void print () {
    for (int i = 0 ; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

vector<pair<int, int>> u; // union

void dfs (int y, int x) {
    v[y][x] = true;
    u.push_back({y, x});
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (v[ny][nx]) continue;
        int diff = abs(m[y][x] - m[ny][nx]);
        if (L <= diff && diff <= R) {
            dfs(ny, nx);
        }
    }
}

int main () {
    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++ j) {
            cin >> m[i][j];
        }
    }

    while (true) {
        int uc = 0; // union count
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (v[i][j]) continue;
                dfs(i, j);
                if (u.size() == 1) {
                    u.clear();
                    continue;
                }
                int p = 0; // population
                for (auto n : u) { // nation
                    p +=m[n.first][n.second];
                }
                int avg = p / u.size();
                for (auto n : u) {
                    m[n.first][n.second] = avg;
                }
                // print();
                u.clear();
                uc++;
            }
        }
        fill(&v[0][0], &v[49][49], false);
        if (uc == 0) break;
        day++;
    }

    cout << day;

    return 0;
}