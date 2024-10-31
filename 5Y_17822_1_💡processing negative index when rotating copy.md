```cpp
int nx = mm + dx[i];
if (nx >= M) nx = 0;
if (nx < 0) nx = M - 1;

// Instead of the above, we can use the following:
int nx = (x + dx[i] + m) % m;
```
