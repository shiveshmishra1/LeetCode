class Solution {
    public int[] findEvenNumbers(int[] digits) {
        // Set to store unique even combinations
        Set<Integer> uniqueEvenCombinations = new HashSet<>();
        
        // Get the length of the input array
        int n = digits.length;
        
        // Generate all possible combinations of 3 digits
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue; // Skip if same index
                
                for (int k = 0; k < n; k++) {
                    // Skip if same index as i or j
                    if (k == i || k == j) continue;
                    
                    // Check for leading zero
                    if (digits[i] == 0) continue;
                    
                    // Construct the number
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    
                    // Check if the number is even
                    if (num % 2 == 0) {
                        uniqueEvenCombinations.add(num);
                    }
                }
            }
        }
        
        // Convert set to sorted array
        return uniqueEvenCombinations.stream()
                .sorted()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}
