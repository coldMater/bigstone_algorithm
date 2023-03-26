#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
 
    bool operator < (const Point& other) const {
        return x < other.x;
    }
};

int main() {
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<Point> pq3;

    pq.push(1);
    pq.push(5);
    pq.push(2);
    pq.push(3);
    pq.push(9);
    pq.push(10);

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

    cout << endl;
    
    pq2.push(1);
    pq2.push(5);
    pq2.push(2);
    pq2.push(3);
    pq2.push(9);
    pq2.push(10);

    while(!pq2.empty()){
        cout << pq2.top() << endl;
        pq2.pop();
    }

    cout << endl;

    pq3.push({ 1, 3 });
    pq3.push({ 2, 2 });
    pq3.push({ 3, 1 });
    pq3.push({ 5, 5 });
    pq3.push({ 1, 2 });
    pq3.push({ 2, 3 });
    pq3.push({ 3, 2 });
    pq3.push({ 2, 4 });
    pq3.push({ 1, 5 });

    while(!pq3.empty()) {
        cout << pq3.top().x << endl;
        pq3.pop();
    }

    return 0;
}