# Performing Operations at Each Turn in BFS Traversal

In BFS, we can count each propagation. The basic BFS structure is as follows:

```cpp
int visited[size];
while (!q.empty()) {
    int qSize = q.size();
    // Do something each turn
    for (int i = 0; i < qSize; i++) {
        int prev = q.front();
        q.pop();

        for (int next : possible movement) {
            if (next is a visited point OR next is out of boundary) continue;
            visited[next] = VISITED (or visited[prev] + 1);
            q.push(next);
        }
    }
    // Do something each turn
}
```

By adding an extra for loop right below the while loop and using the variable qSize to keep track of the number of elements at the current level, we can process each level of the BFS separately. This allows us to perform certain operations or counting tasks at each turn before moving on to the next level.