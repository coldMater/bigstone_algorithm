from:

```cpp
if (height_hall <= h && height_neighbor > h) {
  wh[ny][nx] = h;
  q.push({ { ny, nx }, wh[ny][nx] });
  continue;
}

if (height_hall > h && height_hall <= height_neighbor) {
  wh[ny][nx] = height_hall;
  q.push({ { ny, nx }, wh[ny][nx] });
  continue;
}
```

to:

```cpp
int height_next = max(h, min(height_hall, height_neighbor));
if (height_neighbor > height_next) {
  wh[ny][nx] = height_next;
  q.push({ { ny, nx }, height_next });
}
```
