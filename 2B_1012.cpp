// https://www.acmicpc.net/problem/1012
#include <bits/stdc++.h>
using namespace std;

int tcn; // Test Case Number
int w, h, n;
int xx, yy;
int m[50][50];
int visited[50][50];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int r;
int nx, ny;
void print (int hh, int ww) {
    for (int i = 0; i < hh; ++i) {
        for (int j = 0; j < ww; ++j) {
            cout << visited[i][j] << "\t";
        }
        cout << "\n";
    }
}
 
void go (int y, int x) {
    for (int i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || nx >= w || ny >= h) continue;
        if (visited[ny][nx] != 0 || m[ny][nx] == 0) continue;
        visited[ny][nx] = 1;
        go(ny, nx);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> tcn;
    for (int i = 0; i < tcn; ++i) {
        r = 0;
        cin >> w >> h >> n;
        for (int j = 0; j < n; ++j) {
            cin >> xx >> yy;
            m[yy][xx] = 1;
        }

        // print();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (visited[y][x] == 0 && m[y][x] == 1) {
                    visited[y][x] = 1;
                    r++;
                    go(y, x);
                    // print(h, w);
                    // cout << "\n";
                }
            }
        }
        // print();
        // cout << "\n";
        cout << r << "\n";

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                m[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
    return 0;
}