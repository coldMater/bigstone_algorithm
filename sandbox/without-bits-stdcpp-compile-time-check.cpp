#include <iostream>
#include <vector>
using namespace std;

int main () {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout << "Hello world!";
    vector<int> a;
    a.push_back(123);
    a.push_back(5);
    for (auto i : a) {
        cout << i << endl;
    }
    return 0;
}