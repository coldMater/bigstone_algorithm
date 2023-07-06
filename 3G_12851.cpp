// https://www.acmicpc.net/problem/12851
#include <bits/stdc++.h>
using namespace std;

int isp; // subin's initial position
int bp; // brother's position
const int M = 100'001;
int v[M];
int c[M];

void bfs (int s) {
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int next : { now - 1, now + 1, now * 2 }) {
            if (next < 0 || next >= M) continue;
            if (v[next] == 0) {
                c[next] += c[now];
                v[next] = v[now] + 1;
                q.push(next);
            } else if (v[next] == v[now] + 1) {
                c[next] += c[now];
            }
        }
    }
}

int main () {
    cin >> isp >> bp;

    v[isp] = 1;
    c[isp] = 1;
    bfs(isp);

    cout << v[bp] - 1 << "\n";
    cout << c[bp] << "\n";

    return 0;
}