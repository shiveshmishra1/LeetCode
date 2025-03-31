class Solution {
    public:
        int romanToInt(string s) {
            // Create a mapping from Roman numeral symbols to their values
            unordered_map<char, int> symbolValues = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };
            
            int result = 0;
            int n = s.length();
            
            for (int i = 0; i < n; i++) {
                // If current value is less than next value, subtract current from result
                if (i < n - 1 && symbolValues[s[i]] < symbolValues[s[i + 1]]) {
                    result -= symbolValues[s[i]];
                } else {
                    // Otherwise, add current value to result
                    result += symbolValues[s[i]];
                }
            }
            
            return result;
        }
    };