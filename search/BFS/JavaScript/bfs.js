graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

const visited = new Set();
const queue = [];

const bfs = (visited, graph, node) => {
    visited.add(node);
    queue.push(node);

    while(queue.length) {
        let current = queue.shift();
        console.log(current);

        for(let neighbour of graph[current]) {
            if(!visited.has(neighbour)) {
                visited.add(neighbour);
                queue.push(neighbour);
            }
        }
    }
};

bfs(visited, graph, 'A'); // O/P: A B C D E F
bfs(visited, graph, 'B'); // O/P: B D E F
bfs(visited, graph, 'F'); // O/P: F