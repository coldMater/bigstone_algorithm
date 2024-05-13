Luckily, the first attempt was successful. However, the lines of code are too long, and inevitably, there is a 2D array copying with every function call.

It seems necessary to attempt another approach to simplify this.

---

### hint: rotate and action

There's no need to implement separate functions for each direction. By creating a function that operates in one direction and applying it to rotate the target board by 90 degrees, it eventually covers all directions.
