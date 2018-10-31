public static void main (String [] args){
            depthFirstSearch dfs = new depthFirstSearch(10);

        dfs.addEdges(1,4);
        dfs.addEdges(2,4);
        dfs.addEdges(4,5);
        dfs.addEdges(3,6);
        dfs.addEdges(3,6);
        dfs.addEdges(4,8);
        dfs.addEdges(5,9);
        dfs.addEdges(3,6);
        dfs.addEdges(4,7);
        dfs.addEdges(2,5);
        dfs.addEdges(1,2);
        dfs.addEdges(3,3);
        dfs.addEdges(6,2);
        dfs.addEdges(3,2);
        dfs.addEdges(2,1);


        dfs.DFSearch(1);
    }
