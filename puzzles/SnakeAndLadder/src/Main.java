import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static class Node {
        int vertex;
        int count;
    }

    static int getMinDiceThrows(int[] moves, int n) {
        int[] visited = new int[n];
        Queue<Node> queue = new LinkedList<>();
        Node currNode = new Node();
        currNode.vertex=0;
        currNode.count=0;
        queue.add(currNode);
        visited[0]=1;

        while(!queue.isEmpty()) {
            currNode = queue.remove();
            int v = currNode.vertex;
            if(v == n-1) break;

            for (int i = (v+1); i <= (v+6)&& i<n; i++) {
                //ignore if already visited
                if(visited[i]==0) {
                    Node node = new Node();
                    node.count = currNode.count+1;
                    visited[i] = 1;

                    if(moves[i]!=-1) {
                        node.vertex = moves[i];
                    } else {
                        node.vertex = i;
                    }
                    queue.add(node);
                }
            }
        }
        return currNode.count;
    }

    public static void main(String[] args) {
        int N = 30;
        int moves[] = new int[N];
        for (int i = 0; i < N; i++)
            moves[i] = -1;

        // Ladders
        moves[2] = 21;
        moves[4] = 7;
        moves[10] = 25;
        moves[19] = 28;

        // Snakes
        moves[26] = 0;
        moves[20] = 8;
        moves[16] = 3;
        moves[18] = 6;
        System.out.println(getMinDiceThrows(moves, N));
    }
}