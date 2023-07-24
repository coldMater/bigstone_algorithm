# Initializing Visited 2D Array

I declared a 2D array as follows.
```cpp
int visited[301][301];
```

It contains a total of 301 * 301 elements. 
So, to initialize all the elements of the variable visited to 0, the following function call is needed.
```cpp
fill(&visited[0][0], &visited[0][0] + 301 * 301);
```

However, I made a mistake as shown below.
```cpp
fill(&visited[0][0], &visited[0][0] + w * h); // w and h are the width and height as a input
```
It can't initialize the whole 2D array. It only initializes the first w * h elements.