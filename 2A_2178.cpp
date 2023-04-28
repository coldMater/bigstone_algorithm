// https://www.acmicpc.net/problem/2178
#include <bits/stdc++.h>
using namespace std;

int w, h;
int m[101][101];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int visited[101][101];
queue<pair<int, int>> q;
string l;

void print (int c[101][101], int h, int w) {
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << c[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main () {
    cin >> h >> w;

    for (int i = 1; i <= h; ++i) {
        cin >> l;
        for (int j = 1; j <= l.size(); ++j) {
            m[i][j] = l[j - 1] - '0';
        }
    }

    // print(m, h, w);

    visited[1][1] = 1;
    q.push({1, 1});

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > w || ny > h) continue;
            if (visited[ny][nx] != 0 || m[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // print (visited, h, w);

    cout << visited[h][w];

    return 0;
}


