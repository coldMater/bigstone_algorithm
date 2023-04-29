// https://www.acmicpc.net/problem/2468
#include <bits/stdc++.h>
using namespace std;

int w;
int m[100][100];
int wt[100][100];
int visited[100][100];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int maxArea = 1;
int maxLv;

void print () {
    for (int i = 0; i < w; ++i) {
        for (int j =0; j < w; ++j) {
            cout << wt[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void go (int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= w || nx >= w) continue;
        if (visited[ny][nx] == 1 || wt[ny][nx] == 1) continue;
        go (ny, nx);
    }
}

int main () {
    cin >> w;

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> m[i][j];
            if (m[i][j] > maxLv) maxLv = m[i][j];
        }
    }

    // print();
    
    for (int lv = 1; lv <= maxLv; ++lv) {
        int area = 0;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                visited[i][j] = 0;
                if (m[i][j] <= lv) { 
                    wt[i][j] = 1; 
                } else {
                    wt[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                if (visited[i][j] == 0 && wt[i][j] == 0) {
                    go(i, j);
                    area++;
                }
            }
        }

        // cout << "lv: " << lv << ", area:" << area << "\n";
        // print();

        maxArea = max(maxArea, area);
    }

    cout << maxArea;

    return 0;
}
