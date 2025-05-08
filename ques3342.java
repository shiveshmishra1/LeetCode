class Solution {
    // Four possible directions: up, right, down, left
    private static final int[][] DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;
        
        // [row][col][nextMoveCost] where nextMoveCost: 0 = 1-second move, 1 = 2-second move
        int[][][] dp = new int[n][m][2];
        
        // Initialize all states to maximum value
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j][0] = Integer.MAX_VALUE;
                dp[i][j][1] = Integer.MAX_VALUE;
            }
        }
        
        // Starting point: We're at (0,0) with time 0
        // nextMoveCost = 0 means our first move will cost 1 second
        dp[0][0][0] = 0;
        
        // Priority queue for Dijkstra's algorithm
        // [row, col, nextMoveCost, time]
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[3] - b[3]);
        pq.offer(new int[]{0, 0, 0, 0});
        
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int row = current[0];
            int col = current[1];
            int nextMoveCost = current[2];
            int time = current[3];
            
            // Skip if we've found a better path
            if (time > dp[row][col][nextMoveCost]) {
                continue;
            }
            
            // Try all four directions
            for (int[] dir : DIRECTIONS) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                // Check if new position is valid
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    // Calculate move cost and new state
                    int moveCost = (nextMoveCost == 0) ? 1 : 2;
                    int newNextMoveCost = 1 - nextMoveCost; // Toggle between 0 and 1
                    
                    // We can only START MOVING TO the new room when time >= moveTime[newRow][newCol]
                    int earliestStartTime = Math.max(time, moveTime[newRow][newCol]);
                    int arrivalTime = earliestStartTime + moveCost;
                    
                    // Update if we found a better path
                    if (arrivalTime < dp[newRow][newCol][newNextMoveCost]) {
                        dp[newRow][newCol][newNextMoveCost] = arrivalTime;
                        pq.offer(new int[]{newRow, newCol, newNextMoveCost, arrivalTime});
                    }
                }
            }
        }
        
        // Return minimum time to reach destination
        int result = Math.min(
            dp[n-1][m-1][0] == Integer.MAX_VALUE ? Integer.MAX_VALUE : dp[n-1][m-1][0],
            dp[n-1][m-1][1] == Integer.MAX_VALUE ? Integer.MAX_VALUE : dp[n-1][m-1][1]
        );
        
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
