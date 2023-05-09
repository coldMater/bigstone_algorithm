// https://www.acmicpc.net/problem/2870
#include <bits/stdc++.h>
using namespace std;

int ln; // line number
string s;
vector<string> nv; // number vector

void print () {
    for (int i = 0; i < nv.size(); ++i) {
        cout << nv[i] << "\n";
    }
}

void pn (string &n) { // push number
    if (n.size() != 0) {
        while (n[0] == '0' && n.size() > 1) {

            string ns = ""; // new string
            for (int i = 1; i <= n.size(); ++i) {
                if (n[i] == '\0') break;
                ns += n[i];
            }
            n = ns;
        }
        nv.push_back(n);
        n = "";
    }
}

bool c (string a, string b) {
    if (a.size() > b.size()) {
        return false;
    } else if (a.size() < b.size()) {
        return true;
    } else {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > b[i]) {
                return false;
            } else if (a[i] < b[i]) {
                return true;
            }
        }
        return true;
    }
}

int main () {
    cin >> ln;

    for (int i = 0; i < ln; ++i) {
        cin >> s;
        string n = ""; // number
        for (auto c : s) {
            if ( '0' <= c && c <= '9') {
                n += c;
            } else {
                pn(n);
            }
        }
        pn(n);
    }

    sort(nv.begin(), nv.end(), c);

    print();

    return 0;
}