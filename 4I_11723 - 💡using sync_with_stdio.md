When a large number of standard input or standard output operations are expected, the following code should be included in the main() function.
https://www.geeksforgeeks.org/fast-io-for-competitive-programming/

```cpp
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
```

When expecting numerous standard input or standard output operations, consider using scanf/printf instead of cin/cout.