// https://www.acmicpc.net/problem/2583
#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int m[100][100];
int visited[100][100];
int d1x, d1y, d2x, d2y;
vector<int> as; // areas
int cnt;
int a; // area

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void print(int a, int b) {
    for (int i = a - 1; i >= 0; --i) {
        for (int j = 0; j < b; ++j) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void go (int y, int x) {
    visited[y][x] = 1;
    a++;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (m[ny][nx] == 1 || visited[ny][nx] == 1) continue;
        go (ny, nx);
    }
}

int main () {
    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> d1x >> d1y >> d2x >> d2y;
        for (int x = d1x; x < d2x; ++x) {
            for (int y = d1y; y < d2y; ++y) {
                m[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (m[i][j] == 0 && visited[i][j] != 1) {
                go(i, j);
                cnt++;
                as.push_back(a);
                a = 0;
            }
        }
    }

    cout << cnt << "\n";
    sort(as.begin(), as.end());
    for (int i = 0; i < as.size(); ++i) {
        cout << as[i] << " ";
    }

    return 0;
}
