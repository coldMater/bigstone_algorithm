# Priority queue

By default, it retrieves the largest value first (max-heap behavior).

## min-heap behavior

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

## string default behavior

Declare a priority queue for strings with ascending order (min-heap behavior)

```cpp
priority_queue<string, vector<string>, greater<string>> minHeap;
```

## custom ordering

```cpp
// declare custom comparator
struct CustomCompare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        // Sort by integer value in ascending order
        // If integer values are equal, sort by string in lexicographical order
        if (a.first == b.first) {
            return a.second > b.second; // Lexicographical order for strings
        }
        return a.first > b.first; // Ascending order for integers
    }
};

// declare priority queue using custom comparator
priority_queue<pair<int, string>, vector<pair<int, string>>, CustomCompare> customPQ;

customPQ.push({3, "banana"});
customPQ.push({1, "apple"});
customPQ.push({3, "cherry"});
customPQ.push({2, "date"});
```
