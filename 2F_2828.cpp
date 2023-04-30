// https://www.acmicpc.net/problem/2828
#include <bits/stdc++.h>
using namespace std;

int N, M;
int n;
int mt; // move total
int l, r; // left, right (left and right position of basket)
int p; // position of apple
int main () {
    cin >> N >> M;
    l = 1;
    r = M;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        if (l <= p && p <= r) {
            continue; // doesn't have to move
        }
        if (p < l) {
            int move = l - p;
            r -= move;
            l -= move;
            mt += move;
        }
        if (r < p) {
            int move = p - r;
            r += move;
            l += move;
            mt += move;
        }
    }
    cout << mt;
    return 0;
}
