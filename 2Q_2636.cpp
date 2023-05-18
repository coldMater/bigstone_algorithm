// https://www.acmicpc.net/problem/2636
#include <bits/stdc++.h>
using namespace std;

int h, w;
int m [100][100];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int rac; // remained area count
vector<int> cch; // cheese count history

void print () {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << m[i][j]<< " ";
        }
        cout << "\n";
    }
    cout << "---\n";
}

void dfs (int y, int x) {
    m[y][x] = 2;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
        if (m[ny][nx] == 1) {
            m[ny][nx] = 3;
            continue;
        }
        if (m[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main () {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> m[i][j];
            if (m[i][j] == 1) {
                rac++;
            }
        }
    }

    cch.push_back(rac);

    int t = 0;
    while (rac) {
        rac = 0;
        t++;
        dfs(0, 0);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (m[i][j] == 1) {
                    rac++;
                }
                if (m[i][j] == 2 || m[i][j] == 3) {
                    m[i][j] = 0;
                }
            }
        }
        // print();
        cch.push_back(rac);
    }
    cout << t << "\n";
    cout << *(cch.end() - 2) << "\n";

    return 0;
}