// https://www.acmicpc.net/problem/2S
#include <bits/stdc++.h>
using namespace std;

int N, M;
int a, b;
vector<int> l[100'001];
bool visited[100'001];
vector<int> reliable;
int m;
int cnt;

void dfs (int cn) { // computer number
    visited[cn] = true;
    cnt++;
    // for (int b : l[cn]) { // believer
    for (size_t i = 0; i < l[cn].size(); ++i) {
        int n = l[cn][i]; // next computer number
        if (visited[n]) continue;
        dfs(n);
    }
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        l[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        dfs(i);
        if (m < cnt) {
            m = cnt;
            reliable.clear();
            reliable.push_back(i);
        } else if (cnt != 0 && m == cnt) {
            reliable.push_back(i);
        }

        //initialize
        cnt = 0;
        fill(begin(visited), end(visited), false);
    }

    for (int c : reliable) {
        cout << c << " ";
    }

    return 0;
}
