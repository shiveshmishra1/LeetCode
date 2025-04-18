class Solution {
    public int reverse(int x) {
        // Get the sign
        int sign = (x < 0) ? -1 : 1;
        
        // Convert to positive for processing
        long num = Math.abs((long) x);
        
        // Convert to string, reverse, and convert back to long
        StringBuilder sb = new StringBuilder(String.valueOf(num));
        long reversed = Long.parseLong(sb.reverse().toString());
        
        // Apply sign
        reversed = sign * reversed;
        
        // Check for 32-bit integer overflow
        if (reversed > Integer.MAX_VALUE || reversed < Integer.MIN_VALUE) {
            return 0;
        }
        
        return (int) reversed;
    }
}