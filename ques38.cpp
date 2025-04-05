class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int i = 0;
            int n = nums.size();
            
            // Cyclic sort logic
            while (i < n) {
                int correct = nums[i];
                if (correct < n && nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                } else {
                    i++;
                }
            }
    
            // Find the missing number
            for (int i = 0; i < n; i++) {
                if (nums[i] != i) {
                    return i;
                }
            }
    
            // If all positions are correct, the missing number is n
            return n;
        }
    };
    