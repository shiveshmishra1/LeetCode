class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        n = len(digits)
        
        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            
            digits[i] = 0
        
        # If we reach here, it means all digits were 9
        result = [0] * (n + 1)
        result[0] = 1
        
        return result