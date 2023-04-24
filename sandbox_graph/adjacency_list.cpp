#include <bits/stdc++.h>
using namespace std;

vector<int> adj[4];
int visited[4];
void go (int from) {
    cout << from << "\n";
    visited[from] = 1;
    for (int i = 0; i < adj[from].size(); ++i) {
        int to = adj[from][i];
        if (visited[to] == 1) continue;
        visited[to] = 1;
        go(to);
    }

    return ;
}

int main () {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[3].push_back(0);

    for (int i = 0; i < 4; ++i) {
        if (visited[i] == 0) {
            go(0);
        }
    }


    return 0;
}