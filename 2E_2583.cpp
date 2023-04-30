// https://www.acmicpc.net/problem/2583
#include <bits/stdc++.h>
using namespace std;

int N;
int m[64][64];
string s;

void print () {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

string q (int y, int x, int n) {
    if (n == 1) return m[y][x] == 0 ? "0" : "1";
    string ul = q(y, x, n / 2); // incorrect history: q(0, 0, n/2)
    string ur = q(y, x + n / 2, n / 2);
    string dl = q(y + n / 2, x, n / 2);
    string dr = q(y + n / 2, x + n / 2, n / 2);

    if (ul.size() == 1 && ul == ur && ur == dl && dl == dr) { // incorrect history: Not considering the size of string
        return ul;
    }

    return "(" + ul + ur + dl + dr + ")";
}

int main () {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        for (int j = 0; j < N; ++j) {
            m[i][j] = s[j] - '0';
        }
    }
    // print();

    cout << q(0, 0, N) << "\n";
    
    return 0;
}