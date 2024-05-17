Graph-Based Shortest Path Calculation with BFS

Introduction

This project implements a graph-based solution to determine the shortest path between cities using Breadth-First Search (BFS). The graph consists of cities connected by roads and optional aerial routes. The objective is to calculate the shortest path from the starting city to the target city and determine the number of days required for the travel, considering both road and aerial routes.

Features

Graph Representation: The cities and their connections are represented using an adjacency matrix.

Shortest Path Calculation: Uses BFS to find the shortest path from the starting city to the target city.

Route Management: Allows for the addition of both road and aerial routes.

Travel Days Calculation: Calculates the total number of days required to travel the shortest path.

Example

Input

Enter number of test cases:

2

Enter number of cities:

5

Enter the number of aerial routes:

1

Enter the origin and destination of the aerial routes:

2 4

Enter number of cities:

3
Enter the number of aerial routes:

1

Enter the origin and destination of the aerial routes:

1 3

Output

Case 1 :2

Case 2 :1

Explanation

Test Case 1: The shortest path from city 1 to city 5 includes a direct aerial route from city 2 to city 4, reducing the travel days.

Test Case 2: The shortest path from city 1 to city 3 includes a direct aerial route from city 1 to city 3, reducing the travel days.

Notes

Ensure the input format is followed correctly to avoid runtime errors.

The program currently supports up to 100 cities. Modify the array size in the graph class if more cities are needed.

Conclusion

This program provides an efficient way to determine the shortest path and the number of days required for a journey in a graph with both road and aerial routes. The BFS algorithm ensures the shortest path is found, and the day calculation logic adheres to the specified conditions.
