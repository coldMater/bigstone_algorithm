// https://www.acmicpc.net/problem/10709
#include <bits/stdc++.h>
using namespace std;

int H, W;
int r[100][100]; // result
vector<int> yy; // clouds y
vector<int> xx; // clouds x
int minute;
void print (int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << r[i][j] << " ";
        }
        cout << "\n";
    }
}
void tick () {
    for (auto i = 0; i < xx.size(); ++i) {
        xx[i]++;
    }
    minute++;
}
int main () {
    cin >> H >> W;
    fill(&r[0][0], &r[H][W], -1);

    for (int i = 0; i < H; ++i) {
        string h = "";
        cin >> h;
        for (int j = 0; j < W; ++j) {
            if (h[j] == 'c') {
                yy.push_back(i);
                xx.push_back(j);
                r[i][j] = 0;
            }
        }
    }

    for (int t = 0; t < W; ++t) {
        tick();
        for (auto i = 0; i < xx.size(); ++i) {
            if (xx[i] >= W) {
                continue;
            }
            if (r[yy[i]][xx[i]] == -1) {
                r[yy[i]][xx[i]] = minute;
            }
        }
    }

    print(H, W);
    return 0;
}
