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
string a[100001]; // Using number(number - represented as '1') as a key
unordered_map<string, int> da; // Using name(character - represented as 'a') as a key
// map<string, int> da; // Also has passed with 'map' with 160ms. But unordered_map was faster with 108ms.
// using map(160ms): https://www.acmicpc.net/source/share/16ae131eb2db42cab64b658deddf31b9
// using unordered_map(108ms): https://www.acmicpc.net/source/share/e8714cba564d44398eccd0a3f40e8170
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> qn;

    for (int i = 1; i <= n; ++i) {
        cin >> name;
        a[i] = name;
        da.insert({name, i});
    }

    for (int i = 0; i < qn; ++i) {
        cin >> t; // target
        if (atoi(t.c_str()) == 0) {
            cout << da[t] << "\n";
        } else {
            // cout << d1[atoi(t.c_str())] << "\n"; // Time Complexity of this line is O(logN), but O(1) is better like below.
            cout << a[atoi(t.c_str())] << "\n";
        }
    }

    return 0;
}
