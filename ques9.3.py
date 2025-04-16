class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Negative numbers are never palindromes
        if x < 0:
            return False
        
        # Single digit numbers are always palindromes
        if 0 <= x < 10:
            return True
        
        # If the number ends with 0, it can't be a palindrome unless it's 0 itself
        if x % 10 == 0 and x != 0:
            return False
        
        # Reverse the number and compare
        reversed_num = 0
        original = x
        
        while x > 0:
            reversed_num = reversed_num * 10 + x % 10
            x //= 10  # Integer division in Python 3
        
        return original == reversed_num