class Solution:
    def reverse(self, x: int) -> int:
        # Handle the sign
        sign = -1 if x < 0 else 1
        x = abs(x)
        
        # Convert to string, reverse, and convert back to integer
        rev = int(str(x)[::-1])
        
        # Check for 32-bit integer overflow
        if rev > 2**31 - 1:
            return 0
            
        return sign * rev