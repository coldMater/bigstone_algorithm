// https://www.acmicpc.net/problem/4179
#include <bits/stdc++.h>
using namespace std;

int R, C;
string s;
char m[1000][1000];
int v[1000][1000];
int jv[1000][1000]; // jihoon's visited

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 }; 

void print () {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void printJ () {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << jv[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

queue<pair<int, int>> fs; // fires
void bfs () {
    while (fs.size()) {
        int y = fs.front().first;
        int x = fs.front().second;
        fs.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (v[ny][nx] != 0 || m[ny][nx] == '#') continue;
            v[ny][nx] = v[y][x] + 1;
            fs.push({ ny, nx });
        }
    }
}

queue<pair<int, int>> jp; // jihoon's position
int f () {
    while (jp.size()) {
        int y = jp.front().first;
        int x = jp.front().second;
        jp.pop();
        if (y == 0 || x == 0 || y == R - 1 || x == C - 1) return jv[y][x];

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (jv[ny][nx] != 0 || m[ny][nx] == '#') continue;
            if (v[ny][nx] != 0 && v[ny][nx] - jv[y][x] < 2) continue;
            jv[ny][nx] = jv[y][x] + 1;
            // if (ny == 0 || nx == 0 || ny == R - 1 || nx == C - 1) return jv[ny][nx];
            jp.push({ ny, nx });
        }
    }
    return -1;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cin.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> s;
        for (int j = 0; j < C; ++j) {
            m[i][j] = s[j];
            if (m[i][j] == 'F') {
                fs.push({ i, j });
                v[i][j] = 1;
            }
            if (m[i][j] == 'J') {
                // if (i == R - 1 || j == C - 1 || j == 0 || i == 0) { // 💡 Didn't consider zero index
                //     cout << 1;
                //     return 0;
                // }
                jp.push({ i, j });
                jv[i][j] = 1;
            }
        }
    }

    bfs();
    // print();
    // cout << "\n";
    int r = f();
    // printJ();
    if (r == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << r;
    }

    return 0;
}
