#include <vector>
class Solution {
    public int[] twoSum(int[] nums, int target) 
    {
        for (int i = 0; i < nums.length; i++) 
        {
            for (int j = i + 1; j < nums.length; j++) 
            {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j}; // Return the indices
                }
            }
        }
        return new int[]{}; // Return an empty array if no solution
    }
}
