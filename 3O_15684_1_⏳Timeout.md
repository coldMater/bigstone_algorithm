https://github.com/coldMater/bigstone_algorithm/commit/8f8743b3457263ede1865d280818c379b220f374

The previous approach of solving the "사다리타기" (ladder climbing) algorithm problem 
involved adjusting the horizontal line in each turn, which could be time-consuming.
Additionally, it mistakenly iterated through the count of rungs as 1, 2, 3, ..., n. 
However, a more efficient solution can be achieved by using a BFS or DFS approach. 
Instead of iterating through the rungs one by one, 
we can use a recursive function that adds a new rung to a position 
based on the previous caller function's rung position.
At each recursive call, we check if the current status satisfies the result condition.
If it does, we only need to count the depth of the call.
This insight was not a part of my natural thinking process,
and I received help from the answer to arrive at this solution.
The revised approach, using the recursive function,
should lead to a more optimized solution for the problem.
