// https://www.acmicpc.net/problem/1620
#include <bits/stdc++.h>
using namespace std;

// Data Structure Concept of a Map 
// Uses a red-black tree, where the time complexity of search, insertion, and deletion are all O(logN).

// Data Structure Concept of a Unordered-Map
// Uses a hash-table, where the time complexity of search, insertion, and deletion are, on average, O(1). 
// However, in the worst case scenario, the time complexity can be O(N).

int n, qn; // number(pokemon total count), number of question
string name, t; // target
map<int, string> d1; // Using number(number - represented as '1') as a key
map<string, int> da; // Using name(character - represented as 'a') as a key
int main () {
    cin >> n >> qn;

    for (int i = 1; i <= n; ++i) {
        cin >> name;
        d1.insert({i, name});
        da.insert({name, i});
    }

    for (int i = 0; i < qn; ++i) {
        cin >> t; // target
        if (atoi(t.c_str()) == 0) {
            cout << da[t] << "\n";
        } else {
            cout << d1[atoi(t.c_str())] << "\n";
        }
    }

    return 0;
}
