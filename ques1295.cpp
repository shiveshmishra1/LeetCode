class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count = 0;
            
            for (int num : nums) {
                // Count the number of digits in the current number
                int digits = 0;
                int temp = num;
                
                // Count digits by dividing by 10 until number becomes 0
                while (temp > 0) {
                    temp /= 10;
                    digits++;
                }
                
                // Special case for 0 (has 1 digit)
                if (num == 0) {
                    digits = 1;
                }
                
                // Check if the number of digits is even
                if (digits % 2 == 0) {
                    count++;
                }
            }
            
            return count;
        }
    };