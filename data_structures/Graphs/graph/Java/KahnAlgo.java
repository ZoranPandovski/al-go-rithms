class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indegrees = new int[numCourses];
        int[][] adj = new int[numCourses][numCourses];
        int count = 0;
        for(int i = 0; i < prerequisites.length; i++) {
            adj[prerequisites[i][0]][prerequisites[i][1]] = 1;
            indegrees[prerequisites[i][1]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < indegrees.length; i++) {
            if(indegrees[i] == 0) {
                queue.add(i);
            }
        }
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                int course = queue.poll();
                count++;
                for(int j = 0; j < adj[course].length; j++) {
                    if(adj[course][j] == 1) {
                        adj[course][j]--;
                        indegrees[j]--;
                        if(indegrees[j] == 0) {
                        queue.add(j);
                        }
                    }
               }
           }
        }
        return count == numCourses;
    }
}
