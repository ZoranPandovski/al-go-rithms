package main

import "fmt"

var (
	visited []int
	graph   [][]int
)

func dfs(actual int) {
	fmt.Printf("Visiting node %d\n", actual)
	visited[actual] = 1
	for i := 0; i < len(graph[actual]); i++ {
		if visited[graph[actual][i]] == 0 {
			dfs(graph[actual][i])
		}
	}
}

func main() {
	// Load graph
	var n, e int // Number of nodes and edges

	fmt.Println("Enter number of nodes and edges as this example: \n5 4")
	fmt.Scanf("%d %d", &n, &e)

	visited = make([]int, n)
	graph = make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, 0)
	}

	// Adding edges
	var x, y int
	for i := 0; i < e; i++ {
		fmt.Printf("add next edge, input nodes numbers separed by a space (beetwen 0 and %d), example: 0 1\n", n)
		fmt.Scanf("%d %d", &x, &y)
		graph[x] = append(graph[x], y)
		graph[y] = append(graph[y], x)
	}

	dfs(0)

}
