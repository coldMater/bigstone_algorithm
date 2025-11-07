# The reason why additional BFS search is needed

- Problem condition: If you can reach the destination and obtain infinite profit, you should output "Gee".
- Even if there is a negative cycle in the graph, it may not be "Gee" because the shortest path and the negative cycle may not share any nodes.
- Therefore, you should not output "Gee" based only on the existence of a negative cycle.
- "Gee" should be output only if there is a path from a node in the negative cycle to the destination node.
