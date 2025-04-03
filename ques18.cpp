#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // If there are fewer than 4 elements, return empty result
        if (n < 4) return result;
        
        // Sort the array to handle duplicates and for the two-pointer technique
        std::sort(nums.begin(), nums.end());
        
        // Use long long to avoid integer overflow
        long long targetLL = static_cast<long long>(target);
        
        // Fix the first two elements and use two-pointer technique for the remaining two
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Early pruning: if the sum of the smallest 4 numbers > target, no solution exists
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > targetLL) break;
            
            // Early pruning: if the sum including current number and the largest 3 numbers < target, try next number
            if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < targetLL) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Early pruning for the second level
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > targetLL) break;
                if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < targetLL) continue;
                
                // Use two pointers for the remaining two elements
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum < targetLL) {
                        left++;
                    } else if (sum > targetLL) {
                        right--;
                    } else {
                        // Found a quadruplet
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        // Move both pointers
                        left++;
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};