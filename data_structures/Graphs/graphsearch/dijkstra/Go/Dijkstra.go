package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

type graph struct {
	edges map[int][]*edge
	nodes map[int]struct{}
}

type edge struct {
	head   int
	length int
}

var shortestPaths = make(map[int]int)

func (g *graph) load(filename string) error {
	file, err := os.Open(filename)

	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		edges := strings.Split(strings.TrimSpace(scanner.Text()), "\t")

		// Convert tail vertex to number
		tail, err := strconv.Atoi(edges[0])
		if err != nil {
			log.Fatal(err)
		}

		g.nodes[tail] = struct{}{}

		for i := 1; i < len(edges); i++ {
			data := strings.Split(edges[i], ",")

			// Convert adjacent vertex to number
			head, err := strconv.Atoi(data[0])
			if err != nil {
				log.Fatal(err)
			}

			// Convert length to number
			length, err := strconv.Atoi(data[1])
			if err != nil {
				log.Fatal(err)
			}

			g.nodes[head] = struct{}{}
			g.edges[tail] = append(g.edges[tail], &edge{head: head, length: length})
		}
	}

	return scanner.Err()
}

func (g *graph) dijkstra(source int) map[int]int {

	// Create map to track distances from source vertex
	var u int
	dist := make(map[int]int)

	// Distance from source to source is zero
	dist[source] = 0

	// Initalize all distances to maximum
	for index := range g.nodes {
		if index != source {
			dist[index] = 32767
		}
	}

	// Iterate over all vertices
	for {

		// Check if we have nodes left
		if len(g.nodes) == 0 {
			break
		}

		// Find vertex with minimum distance
		min := 32767
		for index := range g.nodes {
			if dist[index] < min {
				min = dist[index]
				u = index
			}
		}

		// Remove minimum vertex
		delete(g.nodes, u)

		// Calculate minimum edgde distance
		for _, edge := range g.edges[u] {
			if dist[u]+edge.length < dist[edge.head] {
				dist[edge.head] = dist[u] + edge.length
			}
		}
	}

	return dist
}

func main() {

	g := &graph{}
	g.edges = make(map[int][]*edge)
	g.nodes = make(map[int]struct{})

	log.Println("Loading graph...")
	g.load("dijkstraData.txt")

	distances := g.dijkstra(1)

	fmt.Printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", distances[7], distances[37], distances[59], distances[82], distances[99], distances[115], distances[133], distances[165], distances[188], distances[197])
}
