#include <bits/stdc++.h>
using namespace std;

const int S = 10;
int a[S][S];
int visited[S];

void print (int adj[S][S]) {
    for (int i = 0 ; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void go (int from) {
    visited[from] = 1;
    cout << from << "\n";
    for (int i = 0; i < S; ++i) {
        if (visited[i] == 1) continue;
        if (a[from][i] == 1) {
            go(i);
        }
    }
}

int main () {
    a[1][2] = 1; a[2][1] = 1;
    a[1][3] = 1; a[3][1] = 1;
    a[3][4] = 1; a[4][3] = 1;

    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            if (a[i][j] == 1 && visited[i] == 0) {
                go(i);
            }
        }
    }

    return 0;
}