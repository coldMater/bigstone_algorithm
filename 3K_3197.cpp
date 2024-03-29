// https://www.acmicpc.net/problem/3197
#include <bits/stdc++.h>
using namespace std;

int r, c;
const int M = 1501;
char m[M][M];
bool visited[M][M];
bool sVisited[M][M]; // swan visited
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
pair<int, int> sw; // swan
queue<pair<int, int>> ims; // ice list to be melted
queue<pair<int, int>> tempIms; // ice list to be melted TEMP
queue<pair<int, int>> sQ; // swan Queue
queue<pair<int, int>> tempSQ; // swan Queue TEMP

bool check () {
  while (!sQ.empty()) {
    pair<int, int> prev = sQ.front();
    sQ.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = prev.first + dy[i];
      int nx = prev.second + dx[i];
      if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
      if (sVisited[ny][nx] != 0) continue;
      sVisited[ny][nx] = 1;
      if (m[ny][nx] == 'X') tempSQ.push({ ny, nx });
      else if (m[ny][nx] == 'L') return true;
      else sQ.push({ ny, nx });
    }
  }
  return false;
}

bool nearWater(int y, int x) {
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] != 0) continue;
    if (m[ny][nx] != 'X') return true;
  }
  return false;
}

int main () {
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < c; ++j) {
      m[i][j] = s[j];
      if (m[i][j] == 'L') {
        sw = { i, j };
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (m[i][j] == 'X' && nearWater(i, j)) {
        ims.push({ i, j });
        visited[i][j] = 1;
      }
    }
  }

  sQ.push(sw);
  sVisited[sw.first][sw.second] = 1;

  int d = 0;
  while (true) {
    if (check()) {
      cout << d;
      break;
    }
    d++;
    while (!ims.empty()) {
      pair<int, int> ice = ims.front();
      ims.pop();
      m[ice.first][ice.second] = '.';
      for (int j = 0; j < 4; ++j) {
        int ny = ice.first + dy[j];
        int nx = ice.second + dx[j];
        if (m[ny][nx] == 'X' && visited[ny][nx] == 0) { 
          tempIms.push({ ny, nx });
          visited[ny][nx] = 1;
        };
      }
    }
    swap(ims, tempIms);
    queue<pair<int, int>> emptyQ;
    tempIms = emptyQ;
    swap(sQ, tempSQ);
    queue<pair<int, int>> emptyQ2;
    tempSQ = emptyQ2;
  }

  return 0;
}
