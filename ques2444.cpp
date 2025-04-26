class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long result = 0;
            int n = nums.size();
            
            // Tracking most recent positions
            int lastOutOfBounds = -1;   // Position of last element outside [minK, maxK]
            int lastMinK = -1;          // Position of last minK occurrence
            int lastMaxK = -1;          // Position of last maxK occurrence
            
            for (int i = 0; i < n; i++) {
                // Check if current element is within bounds
                if (nums[i] < minK || nums[i] > maxK) {
                    lastOutOfBounds = i;
                }
                
                // Update positions of minK and maxK
                if (nums[i] == minK) {
                    lastMinK = i;
                }
                if (nums[i] == maxK) {
                    lastMaxK = i;
                }
                
                // Calculate valid subarrays ending at current position
                // We need both minK and maxK to appear after the last out-of-bounds element
                if (lastMinK > lastOutOfBounds && lastMaxK > lastOutOfBounds) {
                    // Count subarrays = min(lastMinK, lastMaxK) - lastOutOfBounds
                    result += min(lastMinK, lastMaxK) - lastOutOfBounds;
                }
            }
            
            return result;
        }
    };