/*
    In your terminal, run the following command: node <file name>
*/

const Graph = require('./DFS')

var g = new Graph(6);
var vertices = [ 'A', 'B', 'C', 'D', 'E', 'F' ];
        

for (var i = 0; i < vertices.length; i++) {
   g.addVertex(vertices[i]);
}
        
g.addEdge('A', 'B');
g.addEdge('A', 'D');
g.addEdge('A', 'E');
g.addEdge('B', 'C');
g.addEdge('D', 'E');
g.addEdge('E', 'F');
g.addEdge('E', 'C');
g.addEdge('C', 'F');


g.dfs("E")
