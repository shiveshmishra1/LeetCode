class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;
        
        // dp[i][j] represents the minimum time to reach cell (i,j)
        long[][] dp = new long[n][m];
        
        // Initialize dp array with maximum value
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = Long.MAX_VALUE;
            }
        }
        
        // Base case: Starting point is (0,0) with time 0
        dp[0][0] = 0;
        
        // Directions for adjacent cells: right, down, left, up
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Process cells in BFS manner
        java.util.Queue<int[]> queue = new java.util.LinkedList<>();
        queue.offer(new int[]{0, 0, 0}); // {row, col, time}
        
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int row = curr[0];
            int col = curr[1];
            int time = curr[2];
            
            // If current time is worse than what we've already found, skip
            if (time > dp[row][col]) {
                continue;
            }
            
            // Try all four directions
            for (int[] dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                // Check if valid cell
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    // Calculate the earliest time we can start moving to this cell
                    long waitTime = Math.max(time, moveTime[newRow][newCol]);
                    
                    // Add 1 second for movement
                    long newTime = waitTime + 1;
                    
                    // If we found a better time to reach this cells
                    if (newTime < dp[newRow][newCol]) {
                        dp[newRow][newCol] = newTime;
                        queue.offer(new int[]{newRow, newCol, (int)newTime});
                    }
                }
            }
        }
        
        // Return the minimum time to reach the bottom-right cell
        return dp[n-1][m-1] == Long.MAX_VALUE ? -1 : (int)dp[n-1][m-1];
    }
}
