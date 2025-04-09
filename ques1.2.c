
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the result
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // Check all possible pairs
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                // Store the indices and return
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
   
    *returnSize = 0;
    return result;
}