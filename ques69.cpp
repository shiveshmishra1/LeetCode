class Solution {
    public:
        int mySqrt(int x) {
            // Handle special cases
            if (x == 0) return 0;
            
            // Binary search approach
            long long left = 1, right = x;
            while (left <= right) {
                // Prevent potential integer overflow
                long long mid = left + (right - left) / 2;
                long long square = mid * mid;
                
                // If perfect square is found
                if (square == x) return mid;
                
                // Adjust search range
                if (square < x) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            // Return the floor value
            return right;
        }
    };