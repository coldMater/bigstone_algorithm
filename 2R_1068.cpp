// https://www.acmicpc.net/problem/1068
#include<bits/stdc++.h>
using namespace std;

int n;
int p[50]; // parent
int v[50]; // visited
int lc; // leaf count
int cn; // cut node number
vector<int> adj[50];

void dfs(int node) {
    int cnt = 0;
    for (int i : adj[node]) {
        if (cn == i) continue;
        dfs(i);
        cnt++;
    }
    if (cnt == 0) lc++;
    return;
}

int main () {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] != -1) {
             adj[p[i]].push_back(i);
        }
    }

    cin >> cn;
    
    if (cn == 0) {
        cout << 0;
        return 0;
    }

    dfs(0);

    cout << lc;

    return 0;
}