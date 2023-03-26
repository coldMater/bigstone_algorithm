#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool cmp (const Point &a, const Point &b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

vector<Point> v;
int main () {
    for (int i = 0; i < 10; i++) {
        Point p = Point({ i*i*i % 10, i*i*i*i % 10 });
        v.push_back(p);
        cout << "(" <<p.x << "," << p.y << ")" << endl;
    }

    sort(v.begin(), v.end(), cmp);

    cout << endl;

    for (auto i : v) {
        cout << "(" << i.x << "," << i.y << ")" << endl;
    }
    return 0;
}
