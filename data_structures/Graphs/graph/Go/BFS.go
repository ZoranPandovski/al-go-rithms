package main

import "fmt"

var (
	visited []int
	graph   [][]int
)

func bfs(start int) {
	// Create queue and push start value
	queue := make([]int, 0)
	queue = append(queue, start)
	visited[start] = 1

	// While queue is not empty, read the current node in queue and check its neighbors for unvisited nodes
	for len(queue) != 0 {
		current := queue[0]
		queue = queue[1:] // Remove element from queue
		fmt.Printf("visited %d\n", current)
		for i := 0; i < len(graph[current]); i++ {
			nextNode := graph[current][i]
			if visited[nextNode] == 0 {
				queue = append(queue, nextNode)
				visited[nextNode] = 1
			}
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

	bfs(0)

}
