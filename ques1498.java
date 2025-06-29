import java.util.Arrays;

class Solution {
    final int MOD = (int)1e9 + 7;
    
    private void precomputePowerOfTwo(int[] powerOfTwo, int n) {
        powerOfTwo[0] = 1;
        for (int i = 1; i < n; ++i) {
            powerOfTwo[i] = (int)((powerOfTwo[i - 1] * 2L) % MOD);
        }
    }
    
    public int numSubseq(int[] nums, int target) {
        int n = nums.length;
        int[] powerOfTwo = new int[n];
        precomputePowerOfTwo(powerOfTwo, n);
        
        Arrays.sort(nums);
        int subsequences = 0;
        
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                subsequences = (subsequences + powerOfTwo[right - left]) % MOD;
                left++;
            }
        }
        return subsequences;
    }
}
