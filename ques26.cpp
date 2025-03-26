class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            // If the array is empty, return 0
            if (nums.empty()) return 0;
            
            // Use two-pointer technique
            // k will track the position to place unique elements
            int k = 1;
            
            // Start from the second element
            for (int i = 1; i < nums.size(); i++) {
                // If current element is different from previous unique element
                if (nums[i] != nums[k-1]) {
                    // Place the unique element at position k
                    nums[k] = nums[i];
                    // Increment k to track next unique position
                    k++;
                }
            }
            
            // Return the number of unique elements
            return k;
        }
    };