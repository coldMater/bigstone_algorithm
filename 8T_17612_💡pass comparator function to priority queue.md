### using class

```cpp
class Compare {
public:
  bool operator()(pair<int, int> a, pair<int, int> b) {
    // ...
  }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
```

### using struct

```cpp
struct comp{
    bool operator()(Cacher & a, Cacher & b){
      // ...
    }
};

priority_queue<Cacher, vector<Cacher>, comp> pq;

```
