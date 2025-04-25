#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> w;
vector<int> d;
int INF = 1'234'567'890;
int check (int fi, int bm) { // fi: friend's index, bm: bit masking
    // cout << "call!" <<"\n";
    if (bm == 0) {
        // cout << fi << " " << "end\n\n";
        return (d.size() - 1) - fi;
    }
    if (fi == -1) {
        // cout << "cant cover\n";
        return INF;
    }
    
    int mn = INF;
    // cout << "here\n";
    for (int i; i < w.size(); ++i) {
        int wp = w[i]; // weak point
        if (bm & 1 << i) {
            int di = d[fi]; // distance
            
            // debug
            // cout << "fi, wp, di: " << fi << "," << wp << "," << di << "\n";
            // cout << bitset<15>(bm) << "\n";
            // for (int j = 0; j < 15; ++j) {
                // if (1 << (14 - j) & 1 << wp) cout << "s";
                // else if (1 << (14 - j) & 1 << (wp + di) % N) cout << "e";
                // else cout << "-";
            // }
            // cout << "\n";
           
            int afterChecked = bm;
            // cout << "b: " << bitset<15>(bm) << "\n";
            for (int j = 0; j < w.size(); ++j) {
                if (wp + di < N) {
                    int left = wp;
                    int right = wp + di;
                    // cout << "normal: " << left << "," << right << " - " << w[j] << "\n";
                    if (left <= w[j] && w[j] <= right) {
                        afterChecked &= ~(1 << j % N);
                    }
                } else {
                    int left = (wp + di) % N;
                    int right = wp;
                    // cout << "abnorm: " << left << "," << right << " - " << w[j] << "\n";
                    if (w[j] <= left || right <= w[j]) {
                        afterChecked &= ~(1 << j % N);
                    }
                }
            }
            // cout << "a: " << bitset<15>(afterChecked) << "\n";
            mn = min(mn, check(fi - 1, afterChecked));
        }
    }

    return mn;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n;
    w = weak;
    d = dist;
    
    int mask = 0;
    for (int i = 0; i < w.size(); ++i) {
        mask |= 1 << i;
    }
    
    int answer = check(dist.size() - 1, mask);
    return answer == INF ? -1 : answer;
}