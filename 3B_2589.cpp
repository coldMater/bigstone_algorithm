// https://www.acmicpc.net/problem/2589
#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int h, w;
string s;
char m[50][50]; // map
int v[50][50]; // visited
const char L = 'L'; // Land
const char W = 'W'; // (maybe) Water
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
int nx, ny;

// void bfs () {
//     if (q.size() != 0) {
//         int y = q.front().first;
//         int x = q.front().second;
//         q.pop();
//         for (int i = 0; i < 4; ++i) {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
//             if (v[ny][nx] || m[ny][nx] == W) continue;
//             q.push({ ny, nx });
//             v[ny][nx] = v[y][x] + 1;
//             cout << v[y][x] << "\n";
//         }
//     }
// }

int bfs2nd () {
    int mm = 0; // max
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (v[ny][nx] || m[ny][nx] == W) continue;
            v[ny][nx] = v[y][x] + 1;
            mm = max(mm, v[ny][nx]);
            q.push({ ny, nx });
            // for (int a = 0; a < h; ++a) {
            //     for (int b = 0; b < w; ++b) {
            //         cout << v[a][b] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
        }
    }
    return mm;
}

int main () {
    int mm = 0;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> s;
        for (int j = 0; j < w; ++j) {
            m[i][j] = s[j];
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == L) {
                q.push({ i, j });
                v[i][j] = 1;
                mm = max(mm, bfs2nd());
                // bfs();
            }
            fill(&v[0][0], &v[49][49], 0);
        }
    }

    cout << mm - 1;
    return 0;
}