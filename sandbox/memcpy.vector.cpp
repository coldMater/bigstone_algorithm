#include <bits/stdc++.h>
using namespace std;

main () {
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < 10; ++i) {
        a.push_back(i*i*i);
        b.push_back(0);
    }

    memcpy(b.begin().base(), a.begin().base(), (a.end().base() - a.begin().base()) * 4);

    for (int ael : a) cout << ael << " ";
    cout << "\n";

    for (int bel : b) cout << bel << " ";
    cout << "\n";

    // Check the sizeof vector for memcpy.
    // cout << *(a.begin().base() + 2) << "\n"; 
    // cout << a.begin().base() << "\n";
    // cout << a.end().base() << "\n"; 
    // cout << a.end().base() - a.begin().base() << "\n"; 

    return 0;
}