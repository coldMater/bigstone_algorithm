#include <bits/stdc++.h>
using namespace std;

vector<char> v = { 'a', 'b', 'c', 'd', 'e' };
int k = 4;
void print (vector<char> &s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
    }
    cout << endl;
}

void combi (int start, vector<char> s) {
    if (s.size() == k) {
        print(s);
        return;
    }

    for (int i = start + 1; i < v.size(); i++) {
        s.push_back(v[i]);
        combi(i, s);
        s.pop_back();
    }
}


int main () {
    vector<char> s;
    combi(-1, s);

    return 0;
}