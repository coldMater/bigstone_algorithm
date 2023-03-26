#include <iostream>
#include <set>
using namespace std;

set <pair<int, int>> s;
multiset <pair<int, int>> ms;
int main() {
    s.insert({ 1, 3 });
    s.insert({ 1, 3 });
    s.insert({ 1, 3 });
    s.insert({ 1, 4 });
    s.insert({ 1, 4 });
    s.insert({ 1, 5 });

    cout << s.size() << endl;

    auto it = s.find({1, 3});
    cout << (*it).first << " " << (*it).second << "\n";
    for (auto e : s) {
        cout << e.first << " : " << e.second << "\n";
    }

    cout << endl;

    ms.insert({1, 3});
    ms.insert({1, 3});
    ms.insert({1, 4});
    ms.insert({1, 4});
    ms.insert({1, 4});
    ms.insert({1, 5});

    cout << ms.size() << endl;

    auto it2 = ms.find({1, 3});
    cout << (*it2).first << " " << (*it2).second << "\n";
    for (auto e : ms) {
        cout << e.first << " : " << e.second << "\n";
    }
    return 0;
}