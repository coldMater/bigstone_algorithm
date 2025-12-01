A priority queue should always remove the element with the highest priority first. If you think of a queue as a pipe, the value at the front is the one to be dequeued, and new elements are enqueued at the rear.

```
           0     1     2     n-1   n
enqueue -> |-----|-----| ... |-----|-----| -> dequeue
              |                       |
           (rear)                  (front)
```

So, what does it mean in C++'s priority_queue when using the default `less` comparator (where the first argument should be smaller) for `int` elements?

To make this more intuitive, imagine the queue as a simple array (even though it's actually implemented as a heap). Suppose enqueue happens at index 0. Just like with the `sort` function using `less`, smaller values end up towards the rear, and larger values towards the front. This means that the greater values are positioned at the front (to be dequeued first), and the lesser values are at the rear.
