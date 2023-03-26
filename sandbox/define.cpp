#include <bits/stdc++.h>
using namespace std;
// #define end aaa

vector<int> v;
int main () {
    for (int i : { 1, 2, 3, 4, 5 }) v.push_back(i);
    sort(v.begin(), v.end());

    for (auto n : v) {
        cout << n << " ";
    }
}