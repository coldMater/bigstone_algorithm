In the given problem, the "horizontal line" represents the path.

Initially, I added both edge points of the line to the map array.

If the left point of the line is represented as (y, x) and the right point of the line as (y, x + 1), I mistakenly added both points to the map.

However, in accordance with the conditions of the question, I only need to remember the left point of the line. That's all that's required. To check if the current position (a, b) is on the right side of the line, all I need to do is check if (a, b-1) is the left point of the line.