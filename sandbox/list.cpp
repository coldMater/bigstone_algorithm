#include <bits/stdc++.h>
using namespace std;

list<int> a;

void print(list<int> a) {
    for (auto n : a) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < 4; i++) {
        a.push_back(i);
    }
    for (int i = 0; i < 4; i++) {
        a.push_front(i);
    }
    print(a);

    auto it = a.begin(); it++;
    a.insert(it, 1000);
    print(a);

    it = a.begin(); it++;
    a.erase(it);
    print(a);

    a.pop_front();
    print(a);

    a.pop_back();
    print(a);

    cout << a.front() << " : " << a.back();

    a.clear();
    print(a);


    return 0;
}