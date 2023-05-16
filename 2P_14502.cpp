// https://www.acmicpc.net/problem/14502
#include <bits/stdc++.h>
using namespace std;

int m[8][8];
int N, M; // height, width
int dac; // danger area count
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ret = 64;
vector<pair<int, int>> zeros; // Area presented as '0' - plain area
vector<pair<int, int>> twos; // Area presented as '0' - initial virus area

void printM () {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void dfs (int y, int x) {
    if (m[y][x] == 0) { 
        m[y][x] = 3; // 3 means visited (affacted by virus)
        dac++;
    }
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (m[ny][nx] != 0) continue;
        dfs(ny, nx);
    }
    // cout << "\n";
    // printM(N, M);
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> m[i][j];
            if (m[i][j] == 0) {
                zeros.push_back({ i, j });
            }
            if (m[i][j] == 2) {
                twos.push_back({ i, j });
            }
        }
    }

    for (int w1 = 0; w1 < zeros.size(); ++w1) {
        for (int w2 = w1 + 1; w2 < zeros.size(); ++w2) {
            for (int w3 = w2 + 1; w3 < zeros.size(); ++w3) {
                dac = 0;
                m[zeros[w1].first][zeros[w1].second] = 4; // wall 1, 4 means erected wall
                m[zeros[w2].first][zeros[w2].second] = 4; // wall 2
                m[zeros[w3].first][zeros[w3].second] = 4; // wall 2
                for (int i = 0; i < twos.size(); ++i) {
                    dfs(twos[i].first, twos[i].second);
                }
                m[zeros[w1].first][zeros[w1].second] = 0; // remove wall
                m[zeros[w2].first][zeros[w2].second] = 0; // remove wall
                m[zeros[w3].first][zeros[w3].second] = 0; // remove wall

                for (int i = 0; i < zeros.size(); ++i) {
                    m[zeros[i].first][zeros[i].second] = 0; // initialize visited(Affected Area)
                }
                ret = min(ret, dac);
            }
        }
    }

    cout << zeros.size() - (ret + 3); // `zeros.size()` means empty areas, `ret` means newly affacted areas, `3` means erected wall areas

    return 0;
}