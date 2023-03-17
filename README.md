# Graph Coloring

## Problem
Theorem 1. Let $G$ be a connected graph with every vertex having degree $\leq k$. If G irregular, then $χ(G) \leq k$.

The proof of this proposition tells us how to construct the order of vertices for the algorithm to refer to use less than or equal to $k$ color (for irregular graphs). This exercise requires you to implement this algorithm.

### Request
Enter graphs from the keyboard as an edge list. Show the screen a way to color the graph using:
- Less than or equal to $k$ color for irregular graphs.
- less than or equal to $k+1$ color for regular graphs.
### Input
From file graph.txt:
- The first line contains two integers $n$ and $m$ is the number of vertices and edges of the graph.
- In the next $m$ lines, each line contains two integers corresponding to an edge of the graph.
### Output
File coloredgraph.dot graph representation in DOT language with colored vertices.

## Example
### Input
```bash
5 5
1 2
2 3
3 4
4 1
1 5
```
### Output
```bash
graph graph
{
5 [fillcolor=red, style=filled];
4 [fillcolor=red, style=filled];
1 [fillcolor=green, style=filled];
3 [fillcolor=green, style=filled];
2 [fillcolor=red, style=filled];
1 -- 2;
2 -- 3;
3 -- 4;
4 -- 1;
1 -- 5;
}
```
With output data coloredgraph.dot, we compile with the program graphviz:
```bash
dot -Tpdf coloredgraph.dot -o graph.pdf
```
then file graph.pdf with the content as shown in Figure 1.

About drawing graphs with dot document: [DOT language documentation](https://www.graphviz.org/pdf/dotguide.pdf)

![Screenshot 2023-03-17 220032](https://user-images.githubusercontent.com/89787228/225942139-aa151ad1-b6c6-4ec4-8128-a67d040b7b8d.png)

Figure 1. Colored graph of the previous example
