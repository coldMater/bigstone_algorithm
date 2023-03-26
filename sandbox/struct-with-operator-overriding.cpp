#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point (int y, int x): y(y), x(x) {}

    bool operator < (const Point &a) const {
        if (x*x + y*y < a.x*a.x + a.y*a.y) {
            return true;
        }
        return false;
    }

    bool operator == (const Point &a) const {
        if (x*x + y*y == a.x*a.x + a.y*a.y) {
            return true;
        }
        return false;
    }

    bool operator > (const Point &a) const {
        if (x*x + y*y > a.x*a.x + a.y*a.y) {
            return true;
        }
        return false;
    }
};

int main() {
    Point p1 = Point(2, 3);
    Point p2 = Point(2, 3);
    cout << "p1 < p2: "<< (p1 < p2)<< endl << "p1 > p2: " << (p1 > p2) << endl << "p1 == p2: " << (p1 == p2);
    return 0;
}