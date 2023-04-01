// https://www.acmicpc.net/problem/9996
#include <bits/stdc++.h>
using namespace std;

int n; // number
int a; // index of asterisk
int l; // remained length after asterisk
string nm; // name
vector<string> fs; //files
string s;
int main () {
    cin >> n;
    cin >> nm;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        fs.push_back(s);
    }

    for (int i = 0; i < nm.size(); ++i) {
        if (nm[i] == '*') {
            a = i; // idx of asterisk
            l = nm.size() - a - 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        int start = 0;
        int as = a;
        int al = fs[i].size() - l;
        int end = fs[i].size();

        bool isMatch = true;

        for (int j = 0; j < as; ++j) {
            // cout << j << " " << fs[i][j] << " " << nm[j] << "\n";
            if (fs[i][j] == nm[j]) continue;
            isMatch = false;
            break;
        }

        for (int j = fs[i].size() - 1; j >= al; --j) {
            // cout << j << " " << fs[i][j] << " " << nm[j - al + as + 1] << "\n";
            if (fs[i][j] == nm[j - al + as + 1]) continue;
            isMatch = false;
            break;
        }

        if (isMatch) {
            cout << "DA";
        } else {
            cout << "NE";
        }

        cout << "\n";
    }

    return 0;
}
