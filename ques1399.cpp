class Solution {
    public:
        int countLargestGroup(int n) {
            // Map to store the count of numbers in each digit-sum group
            std::unordered_map<int, int> digitSumGroups;
            
            // Calculate digit sum for each number and update groups
            for (int i = 1; i <= n; i++) {
                int digitSum = calculateDigitSum(i);
                digitSumGroups[digitSum]++;
            }
            
            // Find the size of the largest group
            int maxSize = 0;
            for (const auto& group : digitSumGroups) {
                maxSize = std::max(maxSize, group.second);
            }
            
            // Count how many groups have the largest size
            int count = 0;
            for (const auto& group : digitSumGroups) {
                if (group.second == maxSize) {
                    count++;
                }
            }
            
            return count;
        }
        
    private:
        int calculateDigitSum(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    };