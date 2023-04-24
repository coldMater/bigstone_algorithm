#include <bits/stdc++.h>
using namespace std;

vector<int> adj[9];
int visited[9];

void go(int from) {
    visited[from] = 1;
    cout << from << "\n";
    for (int i = 0; i < adj[from].size(); ++i) {
        int to = adj[from][i];
        if (visited[to] != 0) continue;
        go(to);
    }
}

int main () {
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[1].push_back(3);
    adj[3].push_back(1);

    for (int i = 0; i < 9; ++i) {
        if (adj[i].size() && visited[i] == 0) {
            go(i);
        }
    }
    return 0;
}