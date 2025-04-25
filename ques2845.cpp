class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            int n = nums.size();
            long long result = 0;
            
            // Create a prefix array that tracks count mod modulo
            vector<int> prefix(n + 1, 0);
            
            for (int i = 0; i < n; i++) {
                // Increment the prefix count if the current number satisfies the condition
                prefix[i + 1] = prefix[i] + (nums[i] % modulo == k ? 1 : 0);
            }
            
            // Map to store frequency of each remainder
            unordered_map<int, int> remainderCount;
            remainderCount[0] = 1;  // Initialize with empty prefix
            
            for (int i = 1; i <= n; i++) {
                // Convert prefix sum to prefix count modulo
                int currentRemainder = prefix[i] % modulo;
                
                // Find the target remainder we need to form an interesting subarray
                int targetRemainder = (currentRemainder - k + modulo) % modulo;
                
                // Add count of subarrays ending at position i
                result += remainderCount[targetRemainder];
                
                // Update the frequency of the current remainder
                remainderCount[currentRemainder]++;
            }
            
            return result;
        }
    };