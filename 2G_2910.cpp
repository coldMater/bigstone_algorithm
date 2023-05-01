// https://www.acmicpc.net/problem/2910
#include <bits/stdc++.h>
using namespace std;

int N, C;
map<int, int> m;
map<int, int> mo; // map for ordering
vector<pair<int, int>> v;

bool comp (const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return mo[a.first] < mo[b.first];
    }
    return a.second > b.second;
}


int main () {
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        int temp = 0;
        cin >> temp;
        m[temp] = m[temp] + 1;
        if (mo[temp] == 0) mo[temp] = i + 1;
    }

    for (auto i : m) {
        // cout << i.first << ": " << i.second << "\n";
        v.push_back(i);
    }

    sort(v.begin(), v.end(), &comp);

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].second; ++j) {
            cout << v[i].first << " ";
        }
    }
    return 0;
}