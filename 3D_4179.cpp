// https://www.acmicpc.net/problem/4179
#include <bits/stdc++.h>
using namespace std;

int R, C;
string s;
char m[1000][1000];
pair<int, int> J; // jihoon's position

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 }; 

bool escaped;
bool died;
int c = 0; // count

void print () {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void fire () {
    c++;
    vector<pair<int, int>> jhs; // jihoon's 
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (m[i][j] == 'J') {
                jhs.push_back({ i, j });
            }
        }
    }

    if (jhs.size() == 0) {
        died = true;
        return;
    }

    for (auto j : jhs) {
        int y = j.first;
        int x = j.second;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (m[ny][nx] == '#' || m[ny][nx] == 'J' || m[ny][nx] == 'F') continue;
            m[ny][nx] = 'J';
        }
    }

    vector<pair<int, int>> fires;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (m[i][j] == 'F') {
                fires.push_back({ i, j });
            }
        }
    }

    for (auto f : fires) {
        int y = f.first;
        int x = f.second;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (m[ny][nx] == '#' || m[ny][nx] == 'F') continue;
            if (m[ny][nx] == 'J') {
                // Fire reached to jihoon's area
            }
            m[ny][nx] = 'F';
        }
    }

    for (auto j : jhs) {
        if (j.first == 0 || j.first >= C - 1 || j.second == 0 || j.second >= R - 1) {
            // cout << "escpaed! " << j.first << " " << j.second << "\n";
            escaped = true;
            return;
        }
    }
}

int main () {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> s;
        for (int j = 0; j < C; ++j) {
            m[i][j] = s[j];
        }
    }

    for (int t = 0; t < max(C, R); ++t) {
        fire();
        if (escaped) {
            cout << c;
            return 0;
        }

        if (died) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        if (max(C, R) < t) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
