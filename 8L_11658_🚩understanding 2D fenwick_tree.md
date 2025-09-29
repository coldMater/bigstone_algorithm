Understanding 2D Fenwick Tree

```cpp
void update(int y, int x, int value){
  while(y <= n){
    int j = x;
      while(j <= n){
        bit[y][j] += value;
        j += (j & -j);
      }
      y += (y & -y);
    }
  return;
}

int sum(int y, int x) {
  int s = 0;
  while(y > 0){
    int j = x;
    while(j > 0){
      s += bit[y][j];
      j -= (j & -j);
    }
    y -= (y&-y);
  }
  return s;
}
```
