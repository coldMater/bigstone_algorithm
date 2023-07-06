// https://www.acmicpc.net/problem/12851
#include <bits/stdc++.h>
using namespace std;

int isp; // subin's initial position
int bp; // brother's position
int v[100'001];
int t;
int mt; // minimum time
int mtpc; // minimum time path count

int bfs (int s) {
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int p = q.front();
        if (p == bp) { 
            return v[p];
        }
        q.pop();

        if (p - 1 >= 0 && v[p - 1] == 0) {
            t++;
            v[p-1] = v[p] + 1;
            q.push(p - 1);
        }
        if (p + 1 < 100'001 && v[p + 1] == 0) {
            t++;
            v[p+1] = v[p] + 1;
            q.push(p + 1);
        }
        if (p * 2 < 100'001 && v[p * 2] == 0) {
            t++;
            v[p*2] = v[p] + 1;
            q.push(p * 2);
        }
    }
    return -1;
}

int cc = 0;
void go (int s, int d) {
    cc++;
    if (d >= mt - 1) {
        if (s == bp) mtpc++;
        return;
    }

    go(s - 1, d + 1);
    go(s + 1, d + 1);
    go(s * 2, d + 1);
}

int main () {
    cin >> isp >> bp;

    v[isp] = 1;
    mt = bfs(isp);

    cout << mt - 1 << "\n";

    go(isp, 0);
    cout << mtpc << "\n";
    cout << cc;

    return 0;
}