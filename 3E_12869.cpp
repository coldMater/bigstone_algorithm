// https://www.acmicpc.net/problem/12869
#include <bits/stdc++.h>
using namespace std;

int N;
int h[3];
int deal[3] = { 9, 3, 1 };

void swap (int i, int d, vector<int> &v) {
    int t = v[i];
    v[i] = v[d];
    v[d] = t;
}

void p (int n, int r, int d, vector<int> &iv, vector<vector<int>> &v) {
    if (d == r) {
        vector<int> t;
        for (int i = 0; i < r; ++i) {
            t.push_back(iv[i]);
        }
        v.push_back(t);
    }

    for (int i = d; i < n; ++i) {
        swap(i, d, iv);
        p(n, r, d + 1, iv, v);
        swap(i, d, iv);
    }
}

int main () {
    cin >> N;
    vector<int> iv;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        iv.push_back(t);
    }

    int depth = 0;
    vector<vector<int>> nv;
    nv.push_back(iv);
    while (true) {
        depth++;
        vector<vector<int>> tv;
        for (auto s : nv) {
            vector<vector<int>> v;
            p(s.size(), s.size(), 0, s, v);
            for (auto ss : v) {
                tv.push_back(ss);
            }
        }

        nv.clear();
        for (auto s : tv) {
            vector<int> ns;
            for (int i = 0; i < s.size(); ++i) {
                int h = s[i] - deal[i];
                if (h > 0) {
                    ns.push_back(h); 
                }
            }
            if (ns.size() == 0) {
                cout << depth;
                return 0;
            }
            nv.push_back(ns);
        }
    }

    return 0;
}