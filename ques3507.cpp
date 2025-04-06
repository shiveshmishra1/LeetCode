#include <vector>
using namespace std;

class Solution 
{
public:
        int isSorted(vector<int>& nums, int n) {
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) return 0;
        }
        return 1;
    }

    
    void mergeMinPair(vector<int>& nums, int& n) 
    {
        int minSum = nums[0] + nums[1];
        int index = 0;

        for (int i = 1; i < n - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (sum < minSum) {
                minSum = sum;
                index = i;
            }
        }

        
        nums[index] = nums[index] + nums[index + 1];

        
        for (int j = index + 2; j < n; ++j) 
        {
            nums[j - 1] = nums[j];
        }

        
        n--;
    }

    
    int minimumPairRemoval(vector<int>& nums) 
    {
        int n = nums.size();
        int steps = 0;

        while (!isSorted(nums, n)) 
        {
            mergeMinPair(nums, n);
            steps++;
        }
        return steps;
    }
};
