The DP table after each iteration for test case #2.

### when ascending order

Iterating forward in the for loop causes the same knapsack weight to be counted multiple times.

```text
1 2
dp: 0 2 4 6 8 10 12 14

2 6
dp: 0 2 6 8 12 14 18 20

7 7
dp: 0 2 6 8 12 14 18 20
```

### when descending order

```text
1 2
dp: 0 2 2 2 2 2 2 2

2 6
dp: 0 2 6 8 8 8 8 8

7 7
dp: 0 2 6 8 8 8 8 8
```
