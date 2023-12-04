reset 2D array
```cpp
int m[N][M];
int reset_value = 0;

// using memset()
memset(m, reset_value, sizeof(m));

// using fill()
fill(m, fill(&m[0][0], &m[0][0] + (N * M), reset_value);
)
```