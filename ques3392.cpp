class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int count = 0;
            int n = nums.size();
            
            // We need at least 3 elements to form a subarray of length 3
            if (n < 3) {
                return 0;
            }
            
            // Iterate through all possible starting positions of subarrays with length 3
            for (int i = 0; i <= n - 3; i++) {
                // Check if the sum of first and third elements equals half of the second element
                // Make sure to avoid issues with odd numbers by checking if the middle element is even
                if (nums[i+1] % 2 == 0 && nums[i] + nums[i+2] == nums[i+1] / 2) {
                    count++;
                }
            }
            
            return count;
        }
    };