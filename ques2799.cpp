class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            // First, count the total number of distinct elements in the array
            unordered_set<int> distinctElements;
            for (int num : nums) {
                distinctElements.insert(num);
            }
            int totalDistinct = distinctElements.size();
            
            // Edge case: if there's only one distinct element, all subarrays are complete
            if (totalDistinct == 1) {
                return (nums.size() * (nums.size() + 1)) / 2;
            }
            
            int count = 0;
            int n = nums.size();
            
            // For each possible starting position
            for (int start = 0; start < n; start++) {
                unordered_map<int, int> currentDistinct;
                // Try all possible ending positions
                for (int end = start; end < n; end++) {
                    // Add current element to our map
                    currentDistinct[nums[end]]++;
                    
                    // Check if the current subarray has the same number of distinct elements
                    if (currentDistinct.size() == totalDistinct) {
                        count++;
                    }
                }
            }
            
            return count;
        }
    };