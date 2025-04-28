class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();
            long long count = 0;
            long long sum = 0;
            int left = 0;
            
            // Use sliding window technique
            for (int right = 0; right < n; right++) {
                // Add current element to sum
                sum += nums[right];
                
                // Calculate current window score: sum * length
                long long currentScore = sum * (right - left + 1);
                
                // Shrink window from left until score is less than k
                while (left <= right && currentScore >= k) {
                    sum -= nums[left];
                    left++;
                    // Update score after shrinking
                    currentScore = (left <= right) ? sum * (right - left + 1) : 0;
                }
                
                // Add count of valid subarrays ending at this position
                count += (right - left + 1);
            }
            
            return count;
        }
    };