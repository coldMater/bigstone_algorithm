# Fast I/O Notes

- **Large input/output**
  - Always use:  
    `ios::sync_with_stdio(false);`  
    `cin.tie(NULL); cout.tie(NULL);`
  - Missing this will almost likely cause TLE.
