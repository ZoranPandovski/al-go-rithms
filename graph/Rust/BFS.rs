use std::io::stdin;
use std::collections::VecDeque;

// BFS receives a graph and the start point
fn bfs(graph: &mut Vec<Vec<usize>>, start: usize) {
    let mut visited: Vec<bool> = Vec::new();
    visited.resize(graph.len(), false);

    // Create a VecDeque, it will function as a Queue if we use push_back(value: T) and pop_front(),
    // push starting node to queue and set as visited
    let mut queue = VecDeque::new();
    visited[start] = true;
    queue.push_back(start);

    while !queue.is_empty() {
        let node = queue.pop_front().unwrap();
        println!("{}", node);

        // While queue is not empty, get a slice of the neighbors of chosen node and visit them
        // A slice allows us to traverse the vector read-only by borrowing a section of an array
        let adj_list = &graph[node];
        for neighbor in adj_list {
            if !visited[*neighbor] {
                visited[*neighbor] = true;
                queue.push_back(*neighbor);
            }
        }
    }
}

fn add_edge(graph: &mut Vec<Vec<usize>>, u: usize, v: usize) {
    graph[u].push(v);
}

fn main() {
    let mut edges: usize;
    let mut graph: Vec<Vec<usize>> = Vec::new();
    graph.resize(100, vec![]);

    // Read number of edges from user
    let mut input: String = String::new();
    stdin().read_line(&mut input).unwrap(); 
    edges = input.trim().parse::<u32>().unwrap() as usize;

    while edges > 0 {
        let u: usize;
        let v: usize;

        // Read u and v by splitting input into words and reading the first words found
        let mut input: String = String::new();
        stdin().read_line(&mut input).unwrap();
        let mut words = input.split_whitespace();
        u = words.next().unwrap().parse::<u32>().unwrap() as usize;
        v = words.next().unwrap().parse::<u32>().unwrap() as usize;

        add_edge(&mut graph, u, v);

        edges = edges - 1;
    }

    let start: usize;
    let mut input: String = String::new();
    stdin().read_line(&mut input).unwrap();
    start = input.trim().parse::<u32>().unwrap() as usize;

    bfs(&mut graph, start);
}

#[test]
fn test_bfs_with_graph() {
    let mut graph: Vec<Vec<usize>> = Vec::new();
    graph.resize(4, vec![]);

    add_edge(&mut graph, 0, 1);
    add_edge(&mut graph, 0, 2);
    add_edge(&mut graph, 1, 2);
    add_edge(&mut graph, 2, 0);
    add_edge(&mut graph, 2, 3);
    add_edge(&mut graph, 3, 3);

    println!("BFS Starting from vertex 2");

    bfs(&mut graph, 2);
}
