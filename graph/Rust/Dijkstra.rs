use std::io::stdin;

// Dijkstra receives a graph and the start point
fn dijkstra(graph: &mut Vec<Vec<usize>>, start: usize) {
    let mut distance: Vec<usize> = Vec::new();
    distance.resize(graph.len(), std::usize::MAX);

    // If shortest path was found, we will set it as true
    let mut shortest_path_tree: Vec<bool> = Vec::new();
    shortest_path_tree.resize(graph.len(), false);

    distance[start] = 0;

    for _ in 0..(graph.len() - 1) {
        // Find the minimum distance vertex from all the vertices not processed
        let mut min = std::usize::MAX;
        let mut min_distance = 0;
    
        for v in 0..graph.len() {
            if !shortest_path_tree[v]  &&
                distance[v] <= min {
                min = distance[v];
                min_distance = v;
            }
        }

        // Set the vertex found as processed
        shortest_path_tree[min_distance] = true;

        // Update the distance of all vertices that are adjacent of the vertex previously found
        for v in 0..graph.len() {
            if !shortest_path_tree[v] &&
                graph[min_distance][v] != 0 &&
                distance[min_distance] != std::usize::MAX &&
                distance[min_distance] + graph[min_distance][v] < distance[v] {

                distance[v] = distance[min_distance] + graph[min_distance][v];
            }
        }
    }

    for i in 0..distance.len() {
        println!("Node: {} => Distance: {}", i, distance[i]);
    }
}

fn add_edge(graph: &mut Vec<Vec<usize>>, u: usize, v: usize) {
    graph[u].push(v);
}

fn main() {
   let mut graph: Vec<Vec<usize>> = Vec::new();
    graph.resize(9, vec![]);

    // Graph for Dijkstra has one entry for each vertex.
    // Each vertex in Graph has the distance from this vertex to its neighbors, 
    // or 0 for itself or nodes that it is not connected to
    graph = vec![
                vec![0, 4, 0, 0, 0, 0, 0, 8, 0],
                vec![4, 0, 8, 0, 0, 0, 0, 11, 0],
                vec![0, 8, 0, 7, 0, 4, 0, 0, 2],
                vec![0, 0, 7, 0, 9, 14, 0, 0, 0],
                vec![0, 0, 0, 9, 0, 10, 0, 0, 0],
                vec![0, 0, 4, 14, 10, 0, 2, 0, 0],
                vec![0, 0, 0, 0, 0, 2, 0, 1, 6],
                vec![8, 11, 0, 0, 0, 0, 1, 0, 7],
                vec![0, 0, 2, 0, 0, 0, 6, 7, 0]
            ]; 

    dijkstra(&mut graph, 0);
}

#[test]
fn test_dijkstra_with_graph() {
    let mut graph: Vec<Vec<usize>> = Vec::new();
    graph.resize(9, vec![]);

    graph = vec![
                vec![0, 4, 0, 0, 0, 0, 0, 8, 0],
                vec![4, 0, 8, 0, 0, 0, 0, 11, 0],
                vec![0, 8, 0, 7, 0, 4, 0, 0, 2],
                vec![0, 0, 7, 0, 9, 14, 0, 0, 0],
                vec![0, 0, 0, 9, 0, 10, 0, 0, 0],
                vec![0, 0, 4, 14, 10, 0, 2, 0, 0],
                vec![0, 0, 0, 0, 0, 2, 0, 1, 6],
                vec![8, 11, 0, 0, 0, 0, 1, 0, 7],
                vec![0, 0, 2, 0, 0, 0, 6, 7, 0]
            ];

    println!("Dijkstra Starting from vertex 0");

    dijkstra(&mut graph, 0);
}
