class Solution {
    public boolean isPalindrome(int x) {
        // Negative numbers are never palindromes
        if (x < 0) {
            return false;
        }
        
        // Single digit numbers are always palindromes
        if (x >= 0 && x < 10) {
            return true;
        }
        
        // If the number ends with 0, it can't be a palindrome unless it's 0 itself
        if (x % 10 == 0 && x != 0) {
            return false;
        }
        
        // Reverse the number and compare
        long reversed = 0;
        int original = x;
        
        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        return original == reversed;
    }
}