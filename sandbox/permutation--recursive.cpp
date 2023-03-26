#include <bits/stdc++.h>
using namespace std;

// vector<char> v = { 'a', 'b', 'c' };
vector<char> v = { 'a', 'b', 'c', 'd' };
// vector<char> v = { 'a', 'b', 'c', 'd', 'e' };
int i = 1;

void print (vector<char> &v, int r) {
    printf("%3d\t", i++);
    for (int i = 0; i < r; i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

void permutation (int n, int r, int d) {
    if (d == r) {
        print(v, r);
        return;
    }
    for (int i = d; i < n; i++) {
        swap(v[i], v[d]);
        // swap(v.at(i), v.at(d));
        permutation(n, r, d + 1);
        swap(v[i], v[d]);
        // swap(v.at(i), v.at(d));
    }
}

int main () {
    // swap(v.at(0), v.at(1));
    // print(v, 4);
    // swap(v[0], v[1]);
    // print(v, 4);
    permutation(v.size(), 4, 0);
    return 0;
}