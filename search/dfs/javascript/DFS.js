class Graph {
   
    constructor(noOfVertices) {
        this.noOfVertices = noOfVertices;
        this.AdjList = new Map();
    }
 
  
    addVertex(v) {
       
        this.AdjList.set(v, []);
    }
 
    addEdge(v, w){
       
        this.AdjList.get(v).push(w);
    
        this.AdjList.get(w).push(v);
    }
  
    dfs(startingNode){
    
        var visited = {};
    
        this.DFSUtil(startingNode, visited);
    }
    
    DFSUtil(vert, visited){
        visited[vert] = true;
        console.log(vert);

        var get_neighbours = this.AdjList.get(vert);
    
        for (var i in get_neighbours) {
            var get_elem = get_neighbours[i];
            if (!visited[get_elem])
                this.DFSUtil(get_elem, visited);
        }
    }
}



module.exports = Graph;