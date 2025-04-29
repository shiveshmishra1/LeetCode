class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            
            // Find the maximum value in the array
            int maxVal = *max_element(nums.begin(), nums.end());
            
            // Sliding window approach
            long long result = 0;
            int maxCount = 0;
            int left = 0;
            
            for (int right = 0; right < n; right++) {
                // Expand window to the right
                if (nums[right] == maxVal) {
                    maxCount++;
                }
                
                // Check if we need to update left pointer
                // We maintain the invariant that [left, right] has fewer than k maxVal
                while (maxCount >= k) {
                    // If we have k or more maxVal, we need to shrink the window
                    if (nums[left] == maxVal) {
                        maxCount--;
                    }
                    left++;
                }
                
                // Count subarrays ending at right with fewer than k maxVal
                // These don't contribute to our result
                // So we subtract them from the total possible subarrays ending at right
                result += (right - left + 1);
            }
            
            // The total number of possible subarrays is n*(n+1)/2
            // Subtracting the number of subarrays with fewer than k maxVal
            // gives us the number of subarrays with at least k maxVal
            long long totalSubarrays = (long long)n * (n + 1) / 2;
            
            return totalSubarrays - result;
        }
    };