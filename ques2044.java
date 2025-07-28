class Solution {
    private int solve(int[] nums, int idx, int currOR, int maxOR, int[][] mem) {
        if (idx >= nums.length) {
            return currOR == maxOR ? 1 : 0;
        }
        if (mem[idx][currOR] != -1) {
            return mem[idx][currOR];
        }

        int exclude = solve(nums, idx + 1, currOR, maxOR, mem);
        int include = solve(nums, idx + 1, currOR | nums[idx], maxOR, mem);

        return mem[idx][currOR] = exclude + include;
    }

    public int countMaxOrSubsets(int[] nums) {
        int n = nums.length;
        int maxOR = 0;
        for (int ele : nums) {
            maxOR |= ele;
        }

        int[][] mem = new int[n][maxOR + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxOR; j++) {
                mem[i][j] = -1;
            }
        }

        return solve(nums, 0, 0, maxOR, mem);
    }
}
